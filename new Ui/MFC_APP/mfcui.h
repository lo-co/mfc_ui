#ifndef MFCUI_H
#define MFCUI_H

#include <QMainWindow>
#include <memory>
#include "../../serial/serialcomm.h"
#include "../../alicat/alicat.h"

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

private slots:
    void getData();
};

#endif // MFCUI_H
