#pragma once

#include <QDialog>
#include "Network.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();    
private:
    Ui::Dialog *ui;
    OS currentOS;
    Network *network;
    void showNetworkStatistics();
    MyRandom *rndType;
public slots:
    void addComp();
    void selectOS();
    void infectClicked();
    void connectComps();
    void skipClicked();
};
