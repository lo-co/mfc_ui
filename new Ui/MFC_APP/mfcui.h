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

    std::vector<std::string> IDs;



private slots:
    void getData();
    void on_ac0SP_valueChanged(double sp);
    void on_ac1SP_valueChanged(double sp);
};

#endif // MFCUI_H
