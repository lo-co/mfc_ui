#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <qt4/QtCore/QTimer>
#include <qt4/QtCore/QString>
#include <functional>

using namespace std;

/* All of the above macros are used to convert strings returned from the
 * Alicat to an enum type defined in the macro invocation immediately
 * following.  This was taken from
 *
 * https://stackoverflow.com/questions/5093460/how-to-convert-an-enum-type-variable-to-a-string#5094430
 *
 * It will be moved to wherever we need it.
 */
#define X_DEFINE_ENUM_WITH_STRING_CONVERSIONS_TOSTRING_CASE(r, data, elem)    \
    case elem : return BOOST_PP_STRINGIZE(elem);

#define DEFINE_ENUM_WITH_STRING_CONVERSIONS(name, enumerators)                \
    enum name {                                                               \
        BOOST_PP_SEQ_ENUM(enumerators)                                        \
    };                                                                        \
                                                                              \
    inline const char* ToString(name v)                                       \
    {                                                                         \
        switch (v)                                                            \
        {                                                                     \
            BOOST_PP_SEQ_FOR_EACH(                                            \
                X_DEFINE_ENUM_WITH_STRING_CONVERSIONS_TOSTRING_CASE,          \
                name,                                                         \
                enumerators                                                   \
            )                                                                 \
            default: return "[Unknown " BOOST_PP_STRINGIZE(name) "]";         \
        }                                                                     \
    }

/* Here is the enumeration for gas based on the preprocessor definition above */
DEFINE_ENUM_WITH_STRING_CONVERSIONS(gas, (Air))

/* This stuff is only here for testing right now...
 * move it when we have determined this will work.
 */
struct alicat_data{
    std::string address;
    float pressure;
    float temperature;
    float flow_rate;
    float mass_flow_rate;
    gas gas_;

};


void stupid_test(string msg){
    cout <<'\r' << msg << flush;

    //QString qs;

    //ui->log_text_box->setPlainText(qs.fromStdString(msg));
}

void MainWindow::simple_test(string msg){
    cout <<'\r' << msg << flush;

    QString qs;

    ui->log_text_box->setPlainText(qs.fromStdString(msg));
}

bool alt = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    io_service_(),
    serial_port(io_service_, 19200, "/dev/ttyUSB3", std::bind(&MainWindow::simple_test, this, std::placeholders::_1))
{
    //callback = &MainWindow::simple_test;
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
