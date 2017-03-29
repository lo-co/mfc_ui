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


using namespace std;

void MainWindow::simple_test(string msg){
    cout <<'\r' << msg << flush;

    std::vector<string> tokens;
    boost::split(tokens, msg, boost::is_any_of(" "));

    // Example of how to update controls for one of the controllers
    if (tokens.at(0) == "B"){
        ui->ac0_P->setValue(std::stof(tokens.at(1)));
        ui->ac0_T->setValue(std::stof(tokens.at(2)));
        ui->ac0_Q->setValue(std::stof(tokens.at(3)));
        ui->ac0_Q0->setValue(std::stof(tokens.at(4)));
    }



    /*boost::char_separator<char> sep(" ");
    boost::tokenizer<boost::char_separator<char>> tok(msg, sep);

    for(boost::tokenizer<boost::char_separator<char>>::iterator beg=tok.begin(); beg!=tok.end();++beg){
        cout << *beg << "\n";
    }*/
    QString qs;

    ui->log_text_box->setPlainText(qs.fromStdString(msg));
}

bool alt = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    io_service_(),
    serial_port(io_service_, 19200, "/dev/ttyUSB3", std::bind(&MainWindow::simple_test, this, std::placeholders::_1)),
    data_path("data")
{
    //callback = &MainWindow::simple_test;
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getData()));

    // This is polling pretty fast...
    timer->start(250);

    // Clear the line...
    serial_port.write('\r');
    serial_port.write('\r');

    /* If the main data path does not exist, create it... */
    if (!boost::filesystem::exists(data_path)) boost::filesystem::create_directory(data_path);

    getData();
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
    //serial_port.write
    std::cout << "Current value of control is: " +
                 std::to_string(ui->mfc0SP->value()) << std::endl;

    /* char* flow_int = std::to_string(int(ui->mfc0SP->value()*64000/100));

    serial_port.write('A');



    serial_port.write(flow_int);
    serial_port.write('\r');

    */
    // A delay should be added to make sure that there is no
    // collision...

}

void MainWindow::getData(){

    io_service_.poll();
    ui->timeEdit->setTime(QTime::currentTime());

    // Alternate calls - what should really happen here is that we run
    // this at 1 Hz but pull all of the controllers much faster...
    // Also, this needs to be locked to prevent any writes from stepping on
    // each other
    if (alt) serial_port.write('A');
    else serial_port.write('B');

    serial_port.write('\r');

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
