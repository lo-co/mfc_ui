#ifndef MFCUI_H
#define MFCUI_H

#include <QMainWindow>
#include <memory>
#include "../../serial/serialcomm.h"
#include "../../alicat/alicat.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

namespace Ui {
class MfcUi;
}

class MfcUi : public QMainWindow
{
    Q_OBJECT

public:
    explicit MfcUi(QWidget *parent = 0);
    ~MfcUi();

private:
    Ui::MfcUi *ui;
    std::map<std::string, alicat*> alicat_map;
    std::shared_ptr<SerialComm> port;

    boost::property_tree::ptree pt;



private slots:
    void getData();
};

#endif // MFCUI_H
