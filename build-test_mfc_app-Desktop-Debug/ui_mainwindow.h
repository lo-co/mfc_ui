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
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTimeEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
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
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QDoubleSpinBox *ac0_P;
    QLabel *label_4;
    QDoubleSpinBox *ac0_T;
    QLabel *label_5;
    QDoubleSpinBox *ac0_Q;
    QLabel *label_6;
    QDoubleSpinBox *ac0_Q0;
    QLabel *label_7;
    QDoubleSpinBox *ac0_Qsp;
    QCheckBox *checkBox;
    QPushButton *saveButton;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QDoubleSpinBox *ac1_P;
    QLabel *label_9;
    QDoubleSpinBox *ac1_T;
    QLabel *label_10;
    QDoubleSpinBox *ac1_Q;
    QLabel *label_11;
    QDoubleSpinBox *ac1_Q0;
    QLabel *label_12;
    QDoubleSpinBox *ac1_Qsp;
    QDoubleSpinBox *mfc1SP;
    QLabel *label_13;
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
        mfc0SP->setGeometry(QRect(30, 40, 66, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 111, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        log_text_box = new QPlainTextEdit(centralWidget);
        log_text_box->setObjectName(QString::fromUtf8("log_text_box"));
        log_text_box->setGeometry(QRect(20, 440, 651, 91));
        log_text_box->setAcceptDrops(false);
        log_text_box->setReadOnly(true);
        timeEdit = new QTimeEdit(centralWidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(380, 30, 118, 26));
        timeEdit->setFrame(true);
        timeEdit->setReadOnly(true);
        timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        timeEdit->setTimeSpec(Qt::UTC);
        timeEdit->setTime(QTime(2, 0, 0));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 420, 67, 17));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(450, 70, 139, 281));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        ac0_P = new QDoubleSpinBox(layoutWidget);
        ac0_P->setObjectName(QString::fromUtf8("ac0_P"));
        ac0_P->setReadOnly(true);
        ac0_P->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout->addWidget(ac0_P);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        ac0_T = new QDoubleSpinBox(layoutWidget);
        ac0_T->setObjectName(QString::fromUtf8("ac0_T"));
        ac0_T->setReadOnly(true);
        ac0_T->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout->addWidget(ac0_T);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        ac0_Q = new QDoubleSpinBox(layoutWidget);
        ac0_Q->setObjectName(QString::fromUtf8("ac0_Q"));
        ac0_Q->setReadOnly(true);
        ac0_Q->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout->addWidget(ac0_Q);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        ac0_Q0 = new QDoubleSpinBox(layoutWidget);
        ac0_Q0->setObjectName(QString::fromUtf8("ac0_Q0"));
        ac0_Q0->setReadOnly(true);
        ac0_Q0->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout->addWidget(ac0_Q0);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        ac0_Qsp = new QDoubleSpinBox(layoutWidget);
        ac0_Qsp->setObjectName(QString::fromUtf8("ac0_Qsp"));
        ac0_Qsp->setReadOnly(true);
        ac0_Qsp->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout->addWidget(ac0_Qsp);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(200, 140, 85, 24));
        checkBox->setCheckable(true);
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(210, 60, 80, 26));
        saveButton->setCheckable(true);
        saveButton->setChecked(false);
        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(40, 130, 139, 281));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        ac1_P = new QDoubleSpinBox(layoutWidget_2);
        ac1_P->setObjectName(QString::fromUtf8("ac1_P"));
        ac1_P->setReadOnly(true);
        ac1_P->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_2->addWidget(ac1_P);

        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        ac1_T = new QDoubleSpinBox(layoutWidget_2);
        ac1_T->setObjectName(QString::fromUtf8("ac1_T"));
        ac1_T->setReadOnly(true);
        ac1_T->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_2->addWidget(ac1_T);

        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_2->addWidget(label_10);

        ac1_Q = new QDoubleSpinBox(layoutWidget_2);
        ac1_Q->setObjectName(QString::fromUtf8("ac1_Q"));
        ac1_Q->setReadOnly(true);
        ac1_Q->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_2->addWidget(ac1_Q);

        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11);

        ac1_Q0 = new QDoubleSpinBox(layoutWidget_2);
        ac1_Q0->setObjectName(QString::fromUtf8("ac1_Q0"));
        ac1_Q0->setReadOnly(true);
        ac1_Q0->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_2->addWidget(ac1_Q0);

        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_2->addWidget(label_12);

        ac1_Qsp = new QDoubleSpinBox(layoutWidget_2);
        ac1_Qsp->setObjectName(QString::fromUtf8("ac1_Qsp"));
        ac1_Qsp->setReadOnly(true);
        ac1_Qsp->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_2->addWidget(ac1_Qsp);

        mfc1SP = new QDoubleSpinBox(centralWidget);
        mfc1SP->setObjectName(QString::fromUtf8("mfc1SP"));
        mfc1SP->setGeometry(QRect(40, 90, 66, 23));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(40, 70, 111, 16));
        label_13->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 703, 19));
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
        label_3->setText(QApplication::translate("MainWindow", "Pressure (mb)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Temperature (degC)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Q (lpm)", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Q0 (slpm)", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Qsp (lpm)", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Pressure (mb)", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Temperature (degC)", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Q (lpm)", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Q0 (slpm)", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Qsp (lpm)", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Alicat 1 SP", 0, QApplication::UnicodeUTF8));
        menuAlicat_Control->setTitle(QApplication::translate("MainWindow", "Alicat Control", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
