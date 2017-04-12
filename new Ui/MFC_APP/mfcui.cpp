#include "mfcui.h"
#include "ui_mfcui.h"
#include <qt4/QtCore/QTimer>
#include <iostream>
#include "../../alicat/alicat.h"

MfcUi::MfcUi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MfcUi)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getData()));

    port = std::shared_ptr<SerialComm>(new SerialComm(io_parameters("\r")
                                                      ,serial_setup("/dev/ttyUSB3")));

    alicat_map["AlicatA"] = new alicat('A', "AlicatA", std::shared_ptr<SerialComm>(port));
    alicat_map["AlicatB"] = new alicat('B', "AlicatB", std::shared_ptr<SerialComm>(port));
    //alicat(const char &addr, const std::string &id, std::shared_ptr<SerialComm> port_)

    // This is polling pretty fast...
    timer->start(500);
    
    
}

void MfcUi::getData(){


    ui->timeEdit->setTime(QTime::currentTime());

    if(port->isOpen()){

        //std::cout << "Port is open..." << std::endl;

        for (auto const &ent : alicat_map){

            alicat_data *data = (alicat_data*)ent.second->get_data();
            //std::cout << ent.first + "\t" + data->serialize2ascii() << std::endl;

            if(ent.first == "AlicatA"){

                alicat_data data_ = *data;
                // Example of how to update controls for one of the controllers
                ui->ac0_P->setValue(data_.pressure);
                ui->ac0_T->setValue(data_.temperature);
                ui->ac0_Q->setValue(data_.flow_rate);
                ui->ac0_Q0->setValue(data_.mass_flow_rate);
                ui->ac0_Qsp->setValue(data_.setpoint);
            }
        }

    }

}

MfcUi::~MfcUi()
{

    for (auto const &ent : alicat_map){
        ent.second->~alicat();
    }
    delete ui;
}
