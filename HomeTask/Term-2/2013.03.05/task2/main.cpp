#include <QtGui/QApplication>
#include "SimpleCalculator.h"

int main(int argc, char *argv[])
{
    QApplication SimpleCalc(argc, argv);
    SimpleCalculator widget;
    widget.show();
    
    return SimpleCalc.exec();
}
