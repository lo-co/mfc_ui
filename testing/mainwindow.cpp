#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <qt4/QtCore/QTimer>
#include <qt4/QtCore/QString>
#include <functional>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include "../alicat/alicat.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <locale>
#include <map>
#include <boost/bind.hpp>


using namespace std;

std::map<std::string, alicat_data> device_map;

serial_setup tempSerial= {boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none),
                          boost::asio::serial_port_base::character_size(8),
                          boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none),
                          boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one),
                          "/dev/ttyUSB0",
                          19200,
                          1000
                         };

void MainWindow::simple_test(string msg){
    //cout <<'\r' << msg << flush;

    if(isprint(msg[0])){
        try{
            std::vector<string> tokens;
            boost::split(tokens, msg, boost::is_any_of(" "));

            device_map[tokens.at(0)] = alicat_data(std::stof(tokens.at(1)),
                                                   std::stof(tokens.at(2)),
                                                   std::stof(tokens.at(3)),
                                                   std::stof(tokens.at(4)),
                                                   std::stof(tokens.at(5)),
                                                   Air);
        }
        catch(std::exception const &e){
            cout << msg <<endl;
            cout << "Exception thrown in simple_test.  EC: "  + string(e.what(), 100)<<endl;
        }


        // Example of how to update controls for one of the controllers
        ui->ac0_P->setValue(device_map["B"].pressure);
        ui->ac0_T->setValue(device_map["B"].temperature);
        ui->ac0_Q->setValue(device_map["B"].flow_rate);
        ui->ac0_Q0->setValue(device_map["B"].mass_flow_rate);
        ui->ac0_Qsp->setValue(device_map["B"].setpoint);



        // Example of how to update controls for one of the controllers
        ui->ac1_P->setValue(device_map["A"].pressure);
        ui->ac1_T->setValue(device_map["A"].temperature);
        ui->ac1_Q->setValue(device_map["A"].flow_rate);
        ui->ac1_Q0->setValue(device_map["A"].mass_flow_rate);
        ui->ac1_Qsp->setValue(device_map["A"].setpoint);

        //ui->mfc0SP->setValue();

        QString qs;

        //ui->log_text_box->setPlainText(qs.fromStdString(msg));
    }
    else{
        cout << "msg started with garbage..." << endl;
    }
}

bool alt = false;

string tempDev = "/dev/ttyUSB3";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serial_port(io_parameters("\r")
                ,serial_setup("/dev/ttyUSB3")
                //,std::bind(&MainWindow::simple_test, this,std::placeholders::_1)
                )
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getData()));

    // This is polling pretty fast...
    timer->start(500);

    cout << "Starting session..." << endl;
    // Clear the line...
    serial_port.writeString("\r\r");
}

MainWindow::~MainWindow()
{
    std::cout << "Closing connection..." << std::endl;
    serial_port.close();
    std::cout << "Joining threads..." << std::endl;
    delete ui;

}

void MainWindow::on_mfc0SP_valueChanged(double sp)
{
    boost::lock_guard<boost::mutex> guard(mtx);

    serial_port.async_rw("A" + to_string(int(sp*64000/100)) + "\r");

}

void MainWindow::getData(){

    try{
        boost::lock_guard<boost::mutex> guard(mtx);

        ui->timeEdit->setTime(QTime::currentTime());

        // Alternate calls - what should really happen here is that we run
        // this at 1 Hz but pull all of the controllers much faster...
        // Also, this needs to be locked to prevent any writes from stepping on
        // each other

        if (alt) serial_port.async_rw("A\r");
        else serial_port.async_rw("B\r");

        // Alternate the controller we are talking to.
        alt = !alt;
    }
    catch(std::exception const &e){
        cout << "Exception thrown in GetData.  EC: "  + string(e.what(), 100)<<endl;
    }

}

void MainWindow::on_saveButton_clicked(bool checked)
{
    if (checked){
        boost::posix_time::time_facet *facet = new boost::posix_time::time_facet("%Y%d%b_%H%M%S");

        // stream to stick the string based format...
        std::stringstream  ss;
        // Get the current time
        const boost::posix_time::ptime time = boost::posix_time::ptime();

        ss.imbue(std::locale(std::locale::classic(), facet));
        ss << time;

        // String representation of time...
        ss.str();
    }

}

void MainWindow::on_mfc1SP_valueChanged(double sp)
{
    boost::lock_guard<boost::mutex> guard(mtx);

    serial_port.async_rw("B" + to_string(int(sp*64000/100)) + "\r");

}
