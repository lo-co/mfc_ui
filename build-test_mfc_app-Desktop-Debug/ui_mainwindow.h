/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QTimeEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QDoubleSpinBox *mfc0SP;
    QLabel *label;
    QPlainTextEdit *log_text_box;
    QTimeEdit *timeEdit;
    QDoubleSpinBox *Q;
    QDoubleSpinBox *Q0;
    QDoubleSpinBox *P;
    QDoubleSpinBox *T;
    QDoubleSpinBox *Qsp;
    QLabel *label_2;
    QPushButton *sendTextBtn;
    QTextEdit *addressTxtBox;
    QLabel *label_3;
    QTextEdit *dataTxtBox;
    QLabel *label_4;
    QTextEdit *dataInTxtBox;
    QMenuBar *menuBar;
    QMenu *menuAlicat_Control;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(703, 621);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mfc0SP = new QDoubleSpinBox(centralWidget);
        mfc0SP->setObjectName(QString::fromUtf8("mfc0SP"));
        mfc0SP->setGeometry(QRect(30, 80, 66, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 60, 111, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        log_text_box = new QPlainTextEdit(centralWidget);
        log_text_box->setObjectName(QString::fromUtf8("log_text_box"));
        log_text_box->setGeometry(QRect(20, 340, 651, 91));
        log_text_box->setAcceptDrops(false);
        log_text_box->setReadOnly(true);
        timeEdit = new QTimeEdit(centralWidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(410, 100, 118, 26));
        timeEdit->setFrame(true);
        timeEdit->setReadOnly(true);
        timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        timeEdit->setTimeSpec(Qt::UTC);
        timeEdit->setTime(QTime(2, 0, 0));
        Q = new QDoubleSpinBox(centralWidget);
        Q->setObjectName(QString::fromUtf8("Q"));
        Q->setGeometry(QRect(410, 130, 69, 26));
        Q->setReadOnly(true);
        Q->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Q0 = new QDoubleSpinBox(centralWidget);
        Q0->setObjectName(QString::fromUtf8("Q0"));
        Q0->setGeometry(QRect(410, 160, 69, 26));
        Q0->setReadOnly(true);
        Q0->setButtonSymbols(QAbstractSpinBox::NoButtons);
        P = new QDoubleSpinBox(centralWidget);
        P->setObjectName(QString::fromUtf8("P"));
        P->setGeometry(QRect(410, 190, 69, 26));
        P->setReadOnly(true);
        P->setButtonSymbols(QAbstractSpinBox::NoButtons);
        T = new QDoubleSpinBox(centralWidget);
        T->setObjectName(QString::fromUtf8("T"));
        T->setGeometry(QRect(410, 220, 69, 26));
        T->setReadOnly(true);
        T->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Qsp = new QDoubleSpinBox(centralWidget);
        Qsp->setObjectName(QString::fromUtf8("Qsp"));
        Qsp->setGeometry(QRect(410, 250, 69, 26));
        Qsp->setReadOnly(true);
        Qsp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 320, 67, 17));
        sendTextBtn = new QPushButton(centralWidget);
        sendTextBtn->setObjectName(QString::fromUtf8("sendTextBtn"));
        sendTextBtn->setGeometry(QRect(150, 200, 131, 28));
#ifndef QT_NO_TOOLTIP
        sendTextBtn->setToolTip(QString::fromUtf8("Hit to send text in box..."));
#endif // QT_NO_TOOLTIP
        addressTxtBox = new QTextEdit(centralWidget);
        addressTxtBox->setObjectName(QString::fromUtf8("addressTxtBox"));
        addressTxtBox->setGeometry(QRect(33, 147, 71, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 120, 111, 18));
        dataTxtBox = new QTextEdit(centralWidget);
        dataTxtBox->setObjectName(QString::fromUtf8("dataTxtBox"));
        dataTxtBox->setGeometry(QRect(30, 210, 104, 78));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 180, 59, 18));
        dataInTxtBox = new QTextEdit(centralWidget);
        dataInTxtBox->setObjectName(QString::fromUtf8("dataInTxtBox"));
        dataInTxtBox->setGeometry(QRect(20, 470, 651, 78));
        dataInTxtBox->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 703, 28));
        menuAlicat_Control = new QMenu(menuBar);
        menuAlicat_Control->setObjectName(QString::fromUtf8("menuAlicat_Control"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuAlicat_Control->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Alicat 0 SP", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        log_text_box->setToolTip(QApplication::translate("MainWindow", "Message logs emitted by system.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        timeEdit->setDisplayFormat(QApplication::translate("MainWindow", "hh:mm:ss", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        sendTextBtn->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Device Address", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Data", 0, QApplication::UnicodeUTF8));
        menuAlicat_Control->setTitle(QApplication::translate("MainWindow", "Alicat Control", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
