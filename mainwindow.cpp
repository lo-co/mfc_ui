#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <qt4/QtCore/QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    bytes_read(0),
    read_complete(false)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getData()));
    timer->start(1000);

    std::string comm = "/dev/ttyUSB0";

    boost::asio::io_service io;
    port = std::shared_ptr<boost::asio::serial_port>(new boost::asio::serial_port(io, comm));
    std::cout << "Port has been successfully opened..." << std::endl;

    boost::asio::serial_port_base::baud_rate baud(19200);

    port->set_option(baud);
    std::cout << "Baud rate set to 19200..." << std::endl;



    getData();
}

void MainWindow::read_handler(const boost::system::error_code& error,
                              size_t bytes_transfered, bool& finished_reading,
                              size_t& bytes_read,boost::system::error_code& error_report){

    std::cout << "Finished read..." << std::endl;
    finished_reading = true;
    bytes_read = bytes_transfered;
    error_report = error;

}

MainWindow::~MainWindow()
{
    if (port->is_open()) port->close();
    delete ui;

}

void MainWindow::on_mfc0SP_valueChanged(double arg1)
{
    std::cout << "Current value of control is: " +
                 std::to_string(ui->mfc0SP->value()) << std::endl;

}

void MainWindow::getData(){

    ui->timeEdit->setTime(QTime::currentTime());
    //port->write_some(boost::asio::buffer("B\r"));

}

void MainWindow::configurePort(){

    char delimiter =  '\r';

}
