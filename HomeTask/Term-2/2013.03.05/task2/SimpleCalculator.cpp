#include "SimpleCalculator.h"
#include "ui_SimpleCalculator.h"

SimpleCalculator::SimpleCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleCalculator)
{
    ui->setupUi(this);
    QObject::connect(ui->leftArgument, SIGNAL(valueChanged(int)), this, SLOT(changedValue()));
    QObject::connect(ui->rightArgument, SIGNAL(valueChanged(int)), this, SLOT(changedValue()));
    QObject::connect(ui->operation, SIGNAL(currentIndexChanged(int)), this, SLOT(changedValue()));
}

SimpleCalculator::~SimpleCalculator()
{
    delete ui;
}

enum operation
{
    fold = 0,
    deduct,
    multiply,
    divide
};

void SimpleCalculator::changedValue()
{
    int leftArgument = ui->leftArgument->value();
    int rightArgument = ui->rightArgument->value();
    double result = 0;
    switch (ui->operation->currentIndex())
    {
        case fold:
        {
            result = leftArgument + rightArgument;
            break;
        }
        case deduct:
        {
            result = leftArgument - rightArgument;
            break;
        }
        case multiply:
        {
            result = leftArgument * rightArgument;
            break;
        }
        case divide:
        {
            if (rightArgument == 0)
            {
                ui->result->setText("Error!");
                return;
            }
            else
            {
                result = double(leftArgument) / double(rightArgument);
            }
            break;
        }
    }
    ui->result->setText(QString::number(result));
}
