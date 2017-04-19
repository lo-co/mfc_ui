/********************************************************************************
** Form generated from reading UI file 'mfcui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFCUI_H
#define UI_MFCUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QStatusBar>
#include <QtGui/QTimeEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MfcUi
{
public:
    QWidget *centralWidget;
    QTimeEdit *timeEdit;
    QLabel *label_2;
    QPlainTextEdit *log_text_box;
    QGroupBox *alicat0GB;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_13;
    QDoubleSpinBox *ac1_P_2;
    QLabel *label_14;
    QDoubleSpinBox *ac1_T_2;
    QLabel *label_15;
    QDoubleSpinBox *ac1_Q_2;
    QLabel *label_16;
    QDoubleSpinBox *ac1_Q0_2;
    QLabel *label_17;
    QDoubleSpinBox *ac1_Qsp_2;
    QGroupBox *alicat1GB;
    QWidget *widget;
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
    QDoubleSpinBox *ac0SP;
    QDoubleSpinBox *ac1SP;
    QLabel *ac0SPLabel;
    QLabel *ac1SPLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MfcUi)
    {
        if (MfcUi->objectName().isEmpty())
            MfcUi->setObjectName(QString::fromUtf8("MfcUi"));
        MfcUi->resize(731, 547);
        centralWidget = new QWidget(MfcUi);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        timeEdit = new QTimeEdit(centralWidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(20, 20, 118, 26));
        timeEdit->setFrame(true);
        timeEdit->setReadOnly(true);
        timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        timeEdit->setTimeSpec(Qt::UTC);
        timeEdit->setTime(QTime(2, 0, 0));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 350, 67, 17));
        log_text_box = new QPlainTextEdit(centralWidget);
        log_text_box->setObjectName(QString::fromUtf8("log_text_box"));
        log_text_box->setGeometry(QRect(20, 370, 651, 91));
        log_text_box->setAcceptDrops(false);
        log_text_box->setReadOnly(true);
        alicat0GB = new QGroupBox(centralWidget);
        alicat0GB->setObjectName(QString::fromUtf8("alicat0GB"));
        alicat0GB->setGeometry(QRect(20, 60, 142, 280));
        layoutWidget = new QWidget(alicat0GB);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 125, 241));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_2->addWidget(label_13);

        ac1_P_2 = new QDoubleSpinBox(layoutWidget);
        ac1_P_2->setObjectName(QString::fromUtf8("ac1_P_2"));
        ac1_P_2->setEnabled(true);
        ac1_P_2->setReadOnly(true);
        ac1_P_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_2->addWidget(ac1_P_2);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_2->addWidget(label_14);

        ac1_T_2 = new QDoubleSpinBox(layoutWidget);
        ac1_T_2->setObjectName(QString::fromUtf8("ac1_T_2"));
        ac1_T_2->setReadOnly(true);
        ac1_T_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_2->addWidget(ac1_T_2);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_2->addWidget(label_15);

        ac1_Q_2 = new QDoubleSpinBox(layoutWidget);
        ac1_Q_2->setObjectName(QString::fromUtf8("ac1_Q_2"));
        ac1_Q_2->setReadOnly(true);
        ac1_Q_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_2->addWidget(ac1_Q_2);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_2->addWidget(label_16);

        ac1_Q0_2 = new QDoubleSpinBox(layoutWidget);
        ac1_Q0_2->setObjectName(QString::fromUtf8("ac1_Q0_2"));
        ac1_Q0_2->setReadOnly(true);
        ac1_Q0_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_2->addWidget(ac1_Q0_2);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_2->addWidget(label_17);

        ac1_Qsp_2 = new QDoubleSpinBox(layoutWidget);
        ac1_Qsp_2->setObjectName(QString::fromUtf8("ac1_Qsp_2"));
        ac1_Qsp_2->setReadOnly(true);
        ac1_Qsp_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_2->addWidget(ac1_Qsp_2);

        alicat1GB = new QGroupBox(centralWidget);
        alicat1GB->setObjectName(QString::fromUtf8("alicat1GB"));
        alicat1GB->setGeometry(QRect(170, 60, 142, 280));
        widget = new QWidget(alicat1GB);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 30, 125, 241));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        ac0_P = new QDoubleSpinBox(widget);
        ac0_P->setObjectName(QString::fromUtf8("ac0_P"));
        ac0_P->setReadOnly(true);
        ac0_P->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout->addWidget(ac0_P);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        ac0_T = new QDoubleSpinBox(widget);
        ac0_T->setObjectName(QString::fromUtf8("ac0_T"));
        ac0_T->setReadOnly(true);
        ac0_T->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout->addWidget(ac0_T);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        ac0_Q = new QDoubleSpinBox(widget);
        ac0_Q->setObjectName(QString::fromUtf8("ac0_Q"));
        ac0_Q->setReadOnly(true);
        ac0_Q->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout->addWidget(ac0_Q);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        ac0_Q0 = new QDoubleSpinBox(widget);
        ac0_Q0->setObjectName(QString::fromUtf8("ac0_Q0"));
        ac0_Q0->setReadOnly(true);
        ac0_Q0->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout->addWidget(ac0_Q0);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        ac0_Qsp = new QDoubleSpinBox(widget);
        ac0_Qsp->setObjectName(QString::fromUtf8("ac0_Qsp"));
        ac0_Qsp->setReadOnly(true);
        ac0_Qsp->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout->addWidget(ac0_Qsp);

        ac0SP = new QDoubleSpinBox(centralWidget);
        ac0SP->setObjectName(QString::fromUtf8("ac0SP"));
        ac0SP->setGeometry(QRect(340, 160, 66, 23));
        ac1SP = new QDoubleSpinBox(centralWidget);
        ac1SP->setObjectName(QString::fromUtf8("ac1SP"));
        ac1SP->setGeometry(QRect(340, 210, 66, 23));
        ac0SPLabel = new QLabel(centralWidget);
        ac0SPLabel->setObjectName(QString::fromUtf8("ac0SPLabel"));
        ac0SPLabel->setGeometry(QRect(340, 140, 181, 20));
        ac1SPLabel = new QLabel(centralWidget);
        ac1SPLabel->setObjectName(QString::fromUtf8("ac1SPLabel"));
        ac1SPLabel->setGeometry(QRect(340, 190, 171, 16));
        MfcUi->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MfcUi);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 19));
        MfcUi->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MfcUi);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MfcUi->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MfcUi);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MfcUi->setStatusBar(statusBar);

        retranslateUi(MfcUi);

        QMetaObject::connectSlotsByName(MfcUi);
    } // setupUi

    void retranslateUi(QMainWindow *MfcUi)
    {
        MfcUi->setWindowTitle(QApplication::translate("MfcUi", "MfcUi", 0, QApplication::UnicodeUTF8));
        timeEdit->setDisplayFormat(QApplication::translate("MfcUi", "hh:mm:ss", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MfcUi", "Log", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        log_text_box->setToolTip(QApplication::translate("MfcUi", "Message logs emitted by system.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        alicat0GB->setTitle(QApplication::translate("MfcUi", "GroupBox", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MfcUi", "Pressure (mb)", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MfcUi", "Temperature (degC)", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MfcUi", "Q (lpm)", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MfcUi", "Q0 (slpm)", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MfcUi", "Qsp (lpm)", 0, QApplication::UnicodeUTF8));
        alicat1GB->setTitle(QApplication::translate("MfcUi", "GroupBox", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MfcUi", "Pressure (mb)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MfcUi", "Temperature (degC)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MfcUi", "Q (lpm)", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MfcUi", "Q0 (slpm)", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MfcUi", "Qsp (lpm)", 0, QApplication::UnicodeUTF8));
        ac0SPLabel->setText(QApplication::translate("MfcUi", "TextLabel", 0, QApplication::UnicodeUTF8));
        ac1SPLabel->setText(QApplication::translate("MfcUi", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MfcUi: public Ui_MfcUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFCUI_H
