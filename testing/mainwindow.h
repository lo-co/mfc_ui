#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include "../serial/serial.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    boost::asio::io_service io_service_;

    Serial serial_port;
    //boost::thread t;
    char* data;

private slots:
    void on_mfc0SP_valueChanged(double arg1);
    void getData();
};

#endif // MAINWINDOW_H
