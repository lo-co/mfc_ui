#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

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
    void configurePort();
    void closePort();
    std::shared_ptr<boost::asio::serial_port> port;

    /* The following are used by the handler... */
    bool read_complete;
    int bytes_read;
    boost::system::error_code report;

    void read_handler(const boost::system::error_code& error,
                      size_t bytes_transfered, bool& finished_reading,
                      size_t& bytes_read, boost::system::error_code& error_report);

private slots:
    void on_mfc0SP_valueChanged(double arg1);
    void getData();
};

#endif // MAINWINDOW_H
