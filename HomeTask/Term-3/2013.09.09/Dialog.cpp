#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    currentOS(Windows)
{
    ui->setupUi(this);
    rndType = new RealRandom;
    network = new Network(10, rndType);
    connect(ui->osBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectOS()));
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addComp()));
    connect(ui->infectButton, SIGNAL(clicked()), this, SLOT(infectClicked()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectComps()));
    connect(ui->skipButton, SIGNAL(clicked()), this, SLOT(skipClicked()));
}

Dialog::~Dialog()
{
    delete ui;
    delete network;
    delete rndType;
}

void Dialog::selectOS()
{
    switch (ui->osBox->currentIndex())
    {
        case Windows:
        {
            currentOS = Windows;
            break;
        }
        case Mac:
        {
            currentOS = Mac;
            break;
        }
        case Linux:
        {
            currentOS = Linux;
            break;
        }
    }
}

void Dialog::addComp()
{
    network->addComputer(currentOS);
}

void Dialog::infectClicked()
{

    network->infect(network->getCompList()[ui->setCompToInfect->text().toInt()]);
    ui->setCompToInfect->clear();
    showNetworkStatistics();
}

void Dialog::skipClicked()
{
    Computer **compList = network->getCompList();
    int compCounter = network->getCompCounter();
    for (int i = 0; i < compCounter; i++)
    {
        if (compList[i]->getInfectStatus())
        {
            for (int j = 0; j < compCounter; j++)
            {
                if (i != j && network->areConnected(i, j) && !compList[j]->getInfectStatus())
                {
                    network->infect(compList[j]);
                    showNetworkStatistics();
                    return;
                }
            }
        }

    }
    showNetworkStatistics();
}

void Dialog::connectComps()
{
    network->connectComputers(ui->firstCompToConnect->text().toInt()
                              , ui->secondCompToConnect->text().toInt());
    ui->firstCompToConnect->clear();
    ui->secondCompToConnect->clear();
}

void Dialog::showNetworkStatistics()
{
    int compCounter = network->getCompCounter();
    int infectedCompCounter = 0;
    for (int i = 0; i < compCounter; i++)
    {
        if (network->getCompList()[i]->getInfectStatus())
        {
            infectedCompCounter++;
        }

    }
    ui->outputLog->append(
        QString("Computers in the network: ") + (QString::number(network->getCompCounter()) + QString("\n"))
                + (QString("Infected Computer in the network: ") + QString::number(infectedCompCounter)) + QString("\n"));
}
