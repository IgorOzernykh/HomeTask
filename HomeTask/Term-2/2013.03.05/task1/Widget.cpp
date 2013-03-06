#include "Widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->horizontalScrollBar, SIGNAL (valueChanged(int)), ui->progressBar, SLOT (setValue(int)));
}

Widget::~Widget()
{
    delete ui;
}
