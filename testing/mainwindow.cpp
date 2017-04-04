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

    std::vector<string> tokens;
    boost::split(tokens, msg, boost::is_any_of(" "));

    device_map[tokens.at(0)] = alicat_data(std::stof(tokens.at(1)),
                                           std::stof(tokens.at(2)),
                                           std::stof(tokens.at(3)),
                                           std::stof(tokens.at(4)),
                                           std::stof(tokens.at(5)),
                                           Air);


    // Example of how to update controls for one of the controllers
    ui->ac0_P->setValue(device_map["B"].pressure);
    ui->ac0_T->setValue(device_map["B"].temperature);
    ui->ac0_Q->setValue(device_map["B"].flow_rate);
    ui->ac0_Q0->setValue(device_map["B"].mass_flow_rate);
    ui->ac0_Qsp->setValue(device_map["B"].setpoint);



    /*boost::char_separator<char> sep(" ");
    boost::tokenizer<boost::char_separator<char>> tok(msg, sep);

    for(boost::tokenizer<boost::char_separator<char>>::iterator beg=tok.begin(); beg!=tok.end();++beg){
        cout << *beg << "\n";
    }*/
    QString qs;

    ui->log_text_box->setPlainText(qs.fromStdString(msg));
}

bool alt = false;

string tempDev = "/dev/ttyUSB3";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serial_port(io_parameters("\r")
                ,serial_setup("/dev/ttyUSB3")
                ,std::bind(&MainWindow::simple_test, this,std::placeholders::_1)
                )
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getData()));

    // This is polling pretty fast...
    timer->start(250);

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

void MainWindow::on_mfc0SP_valueChanged(double arg1)
{
    boost::lock_guard<boost::mutex> guard(mtx);
    //boost::lock_guard<MainWindow> guard(*this);
    //serial_port.write
    std::cout << "Current value of control is: " +
                 std::to_string(ui->mfc0SP->value()) << std::endl;

    string flow_int = to_string(int(ui->mfc0SP->value()*64000/100));

    serial_port.writeString("A" + flow_int + "\r");
    serial_port.readStrUntil();

}

void MainWindow::getData(){
    boost::lock_guard<boost::mutex> guard(mtx);
    //boost::lock_guard<MainWindow> guard(*this);

    //io_service_.poll();
    ui->timeEdit->setTime(QTime::currentTime());

    // Alternate calls - what should really happen here is that we run
    // this at 1 Hz but pull all of the controllers much faster...
    // Also, this needs to be locked to prevent any writes from stepping on
    // each other
    /*if (alt) serial_port.writeString('A');
    else serial_port.write('B');

    serial_port.write('\r');*/

   if (alt) serial_port.writeString("A\r");
        else serial_port.writeString("B\r");

    serial_port.readStrUntil();

    // Alternate the controller we are talking to.
    alt = !alt;

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
