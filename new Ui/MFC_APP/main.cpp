#include "mfcui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MfcUi w;
    w.show();

    return a.exec();
}
