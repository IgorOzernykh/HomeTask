#include "UberCalc.h"
#include "ui_UberCalc.h"

UberCalc::UberCalc(QWidget *parent) :
    QWidget(parent),
    numberMapper (new QSignalMapper(this)),
    operationMapper (new QSignalMapper(this)),
    firstArg(0),
    secondArg(0),
    MemSave(0),
    fArgChosen(false),
    memSaved(false),
    ui(new Ui::UberCalc)
{
    ui->setupUi(this);
    connectButtons();
}

UberCalc::~UberCalc()
{
    delete ui;
    delete numberMapper;
    delete operationMapper;
}

void UberCalc::connectButtons()
{
    numberMapper->setMapping(ui->Num_0, QString::number(0));
    numberMapper->setMapping(ui->Num_1, QString::number(1));
    numberMapper->setMapping(ui->Num_2, QString::number(2));
    numberMapper->setMapping(ui->Num_3, QString::number(3));
    numberMapper->setMapping(ui->Num_4, QString::number(4));
    numberMapper->setMapping(ui->Num_5, QString::number(5));
    numberMapper->setMapping(ui->Num_6, QString::number(6));
    numberMapper->setMapping(ui->Num_7, QString::number(7));
    numberMapper->setMapping(ui->Num_8, QString::number(8));
    numberMapper->setMapping(ui->Num_9, QString::number(9));
    numberMapper->setMapping(ui->dot, QString("."));

    connect (ui->Num_0, SIGNAL (clicked()), numberMapper, SLOT (map()));
    connect (ui->Num_1, SIGNAL (clicked()), numberMapper, SLOT (map()));
    connect (ui->Num_2, SIGNAL (clicked()), numberMapper, SLOT (map()));
    connect (ui->Num_3, SIGNAL (clicked()), numberMapper, SLOT (map()));
    connect (ui->Num_4, SIGNAL (clicked()), numberMapper, SLOT (map()));
    connect (ui->Num_5, SIGNAL (clicked()), numberMapper, SLOT (map()));
    connect (ui->Num_6, SIGNAL (clicked()), numberMapper, SLOT (map()));
    connect (ui->Num_7, SIGNAL (clicked()), numberMapper, SLOT (map()));
    connect (ui->Num_8, SIGNAL (clicked()), numberMapper, SLOT (map()));
    connect (ui->Num_9, SIGNAL (clicked()), numberMapper, SLOT (map()));
    connect (ui->dot, SIGNAL (clicked()), numberMapper, SLOT(map()));


    operationMapper->setMapping(ui->Composition, QString("+"));
    operationMapper->setMapping(ui->Subtraction, QString("-"));
    operationMapper->setMapping(ui->Multiplication, QString("*"));
    operationMapper->setMapping(ui->Division, QString("/"));

    connect (ui->Composition, SIGNAL (clicked()), operationMapper, SLOT(map()));
    connect (ui->Subtraction, SIGNAL (clicked()), operationMapper, SLOT(map()));
    connect (ui->Multiplication, SIGNAL (clicked()), operationMapper, SLOT(map()));
    connect (ui->Division, SIGNAL (clicked()), operationMapper, SLOT(map()));

    connect (ui->Equal, SIGNAL (clicked()), this, SLOT (equalClicked()));
    connect (ui->clear, SIGNAL (clicked()), this, SLOT (clearClicked()));
    connect (ui->plus_minus, SIGNAL (clicked()), this, SLOT (plus_minusClicked()));
    connect (ui->MemSave, SIGNAL (clicked()), this, SLOT (MemSaveClicked()));
    connect (ui->MemRest, SIGNAL (clicked()), this, SLOT (MemRestClicked()));

    connect(numberMapper, SIGNAL(mapped(QString)), this, SLOT (addToResultLine(QString)));
    connect(operationMapper, SIGNAL(mapped(QString)), this, SLOT(operationClicked(QString)));
}

void UberCalc::clearLines()
{
    ui->resultLine->clear();
    ui->action->clear();
}

void UberCalc::addToResultLine(QString newSym)
{
    if (ui->resultLine->text()[0] == 'D')
    {
        ui->resultLine->clear();
    }
    else if (ui->action->text() == "=")
    {
         clearLines();
    }
    ui->resultLine->setText(ui->resultLine->text() + newSym);
}

void UberCalc::operationClicked(QString chosenOperation)
{
    if (!fArgChosen)
    {
        firstArg = ui->resultLine->text().toDouble();
        fArgChosen = true;
        operation = chosenOperation;
        ui->action->setText(operation);
        ui->resultLine->clear();
    }
    else
    {
        if (ui->resultLine->text() == "")
        {
            operation = chosenOperation;
            ui->action->setText(operation);
            return;
        }
        secondArg = ui->resultLine->text().toDouble();
        try
        {
        firstArg = calc.calculate(firstArg, secondArg, operation);
        operation = chosenOperation;
        ui->action->setText(operation);
        ui->resultLine->clear();
        }
        catch (QString* exception)
        {
            ui->resultLine->setText(*exception);
            fArgChosen = false;
            ui->action->clear();
            delete exception;
        }
    }
}

void UberCalc::equalClicked()
{
    if (ui->resultLine->text()[0] == 'D' || ui->action->text() == "=")
        return;
    if (!fArgChosen && ui->resultLine->text() != "")
        return;

    secondArg = ui->resultLine->text().toDouble();
    try
    {
        firstArg = calc.calculate(firstArg, secondArg, operation);
        fArgChosen = false;
        ui->action->setText("=");
        ui->resultLine->setText(QString::number(firstArg));
    }
    catch (QString* exception)
    {
        ui->resultLine->setText(*exception);
        fArgChosen = false;
        ui->action->clear();
        delete exception;
    }
}

void UberCalc::clearClicked()
{
    clearLines();
    fArgChosen = false;
}

void UberCalc::plus_minusClicked()
{
    if (ui->resultLine->text()[0] != 'D')
        ui->resultLine->setText(QString::number(0 - ui->resultLine->text().toDouble()));
}

void UberCalc::MemSaveClicked()
{
    if (ui->resultLine->text()[0] != 'D')
    {
        MemSave = ui->resultLine->text().toDouble();
        memSaved = true;
    }
    else return;
}

void UberCalc::MemRestClicked()
{
    if (memSaved)
        ui->resultLine->setText(QString::number(MemSave));
    else
        return;
}
