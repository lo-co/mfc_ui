#include "mfcui.h"
#include "ui_mfcui.h"
#include <qt4/QtCore/QTimer>
#include <iostream>
#include "../../alicat/alicat.h"
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/find.hpp>

using namespace boost;


MfcUi::MfcUi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MfcUi)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getData()));

    property_tree::ini_parser::read_ini("/home/mrichardson/alicat.ini", pt);


    std::string ids = pt.get<std::string>("Alicat.IDs");

    boost::split(IDs, ids, boost::is_any_of(","));

    port = std::shared_ptr<SerialComm>(new SerialComm(io_parameters("\r")
                                                      ,serial_setup(pt.get<std::string>("Alicat.Port"))));


    for (auto &id : IDs){

        std::string key_addr = "Alicat." + id + "_Address";

        char addr = pt.get<char>(key_addr);

        alicat_map[id] = new alicat(addr, id, std::shared_ptr<SerialComm>(port));
    }

    ui->alicat0GB->setTitle(IDs.at(0).data());
    ui->alicat1GB->setTitle(IDs.at(1).data());

    ui->ac0SPLabel->setText(QString::fromStdString(std::string(IDs.at(0).data()) + " Setpoint"));
    ui->ac1SPLabel->setText(QString::fromStdString(std::string(IDs.at(1).data()) + " Setpoint"));

    // This is polling pretty fast...
    timer->start(500);
    
    
}

void MfcUi::getData(){


    ui->timeEdit->setTime(QTime::currentTime());

    if(port->isOpen()){

        for (auto const &ent : alicat_map){

            alicat_data* data = (alicat_data*)ent.second->get_data();
            //std::cout << ent.first + "\t" + data->serialize2ascii() << std::endl;

            if(ent.first == ui->alicat0GB->title().toStdString()){

                //alicat_data data_ = *data;
                // Example of how to update controls for one of the controllers
                ui->ac0_P->setValue(data->pressure);
                ui->ac0_T->setValue(data->temperature);
                ui->ac0_Q->setValue(data->flow_rate);
                ui->ac0_Q0->setValue(data->mass_flow_rate);
                ui->ac0_Qsp->setValue(data->setpoint);
            }
            else{
                if (ent.first == ui->alicat1GB->title().toStdString()){

                    //alicat_data data_ = *data;
                    // Example of how to update controls for one of the controllers
                    ui->ac1_P_2->setValue(data->pressure);
                    ui->ac1_T_2->setValue(data->temperature);
                    ui->ac1_Q_2->setValue(data->flow_rate);
                    ui->ac1_Q0_2->setValue(data->mass_flow_rate);
                    ui->ac1_Qsp_2->setValue(data->setpoint);

                }
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

void MfcUi::on_ac0SP_valueChanged(double sp)
{
    alicat_map.at(IDs.at(0))->set_flow_rate(sp);
}

void MfcUi::on_ac1SP_valueChanged(double sp)
{
    alicat_map.at(IDs.at(1))->set_flow_rate(sp);

}
