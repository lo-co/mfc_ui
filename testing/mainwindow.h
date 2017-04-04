#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
//#include "../serial/serial.h"
#include "../serial/serialcomm.h"
#include <functional>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/thread/lockable_adapter.hpp>
#include <boost/thread/mutex.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow/*, boost::basic_lockable_adapter<boost::mutex>*/
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void simple_test(std::string msg);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //boost::asio::io_service io_service_;

    //Serial serial_port;
    SerialComm serial_port;
    //boost::thread t;
    //char* data;

    boost::filesystem::path file;

    boost::filesystem::path data_path;

    boost::mutex mtx;

private slots:
    void on_mfc0SP_valueChanged(double arg1);
    void getData();
    void on_saveButton_clicked(bool checked);

};

#endif // MAINWINDOW_H
