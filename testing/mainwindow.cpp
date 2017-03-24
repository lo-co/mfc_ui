#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <qt4/QtCore/QTimer>

bool alt = false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    io_service_(),
    serial_port(io_service_, 19200, "/dev/ttyUSB3")
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getData()));

    // This is polling pretty fast...
    timer->start(50);

    // Clear the line...
    serial_port.write('\r');
    serial_port.write('\r');

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

    // A delay should be added to make sure that there is no
    // collision...

}

void MainWindow::getData(){

    io_service_.poll();
    char ret = '\r';
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
