#include "OuthAndCrosses.h"
#include "ui_outhandcrosses.h"

OuthAndCrosses::OuthAndCrosses(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OuthAndCrosses),
    Sequence('X')
{
    for (int i = 0; i < 9; i++)
    {
        BtnPressed[i] = false;
    }
    ui->setupUi(this);
    connectButtons();
}

OuthAndCrosses::~OuthAndCrosses()
{
    delete ui;
}

void OuthAndCrosses::changeSequence()
{
    if (Sequence == QString('X'))
        Sequence = QString('O');
    else
        Sequence = QString('X');
}

void OuthAndCrosses::button1Clicked()
{
    if (BtnPressed[0])
        return;
    ui->B1->setText(Sequence);
    changeSequence();
    BtnPressed[0] = true;

}
void OuthAndCrosses::button2Clicked()
{
    if (BtnPressed[1])
        return;
    ui->B2->setText(Sequence);
    changeSequence();
    BtnPressed[1] = true;

}
void OuthAndCrosses::button3Clicked()
{
    if (BtnPressed[2])
        return;
    ui->B3->setText(Sequence);
    changeSequence();
    BtnPressed[2] = true;

}
void OuthAndCrosses::button4Clicked()
{
    if (BtnPressed[3])
        return;
    ui->B4->setText(Sequence);
    changeSequence();
    BtnPressed[3] = true;

}

void OuthAndCrosses::button5Clicked()
{
    if (BtnPressed[4])
        return;
    ui->B5->setText(Sequence);
    changeSequence();
    BtnPressed[4] = true;

}
void OuthAndCrosses::button6Clicked()
{
    if (BtnPressed[5])
        return;
    ui->B6->setText(Sequence);
    changeSequence();
    BtnPressed[5] = true;

}
void OuthAndCrosses::button7Clicked()
{
    if (BtnPressed[6])
        return;
    ui->B7->setText(Sequence);
    changeSequence();
    BtnPressed[6] = true;

}
void OuthAndCrosses::button8Clicked()
{
    if (BtnPressed[7])
        return;
    ui->B8->setText(Sequence);
    changeSequence();
    BtnPressed[7] = true;

}
void OuthAndCrosses::button9Clicked()
{
    if (BtnPressed[8])
        return;
    ui->B9->setText(Sequence);
    changeSequence();
    BtnPressed[8] = true;

}



void OuthAndCrosses::connectButtons()
{
    connect (ui->B1, SIGNAL (clicked()), this, SLOT (button1Clicked()));
    connect (ui->B2, SIGNAL (clicked()), this, SLOT (button2Clicked()));
    connect (ui->B3, SIGNAL (clicked()), this, SLOT (button3Clicked()));
    connect (ui->B4, SIGNAL (clicked()), this, SLOT (button4Clicked()));
    connect (ui->B5, SIGNAL (clicked()), this, SLOT (button5Clicked()));
    connect (ui->B6, SIGNAL (clicked()), this, SLOT (button6Clicked()));
    connect (ui->B7, SIGNAL (clicked()), this, SLOT (button7Clicked()));
    connect (ui->B8, SIGNAL (clicked()), this, SLOT (button8Clicked()));
    connect (ui->B9, SIGNAL (clicked()), this, SLOT (button9Clicked()));;
}
