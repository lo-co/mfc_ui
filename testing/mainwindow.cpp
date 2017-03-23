#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <qt4/QtCore/QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getData()));
    timer->start(1000);

    std::string comm = "/dev/ttyUSB0";



    getData();
}

MainWindow::~MainWindow()
{
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
