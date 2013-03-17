#pragma once
#include <QWidget>
#include <QSignalMapper>
#include <Calculator.h>

namespace Ui {
class UberCalc;
}

class UberCalc : public QWidget
{
    Q_OBJECT
    
public:
    explicit UberCalc(QWidget *parent = 0);
    ~UberCalc();
private:
    QSignalMapper *numberMapper;
    QSignalMapper *operationMapper;
    double firstArg;
    double secondArg;
    double MemSave;
    bool fArgChosen;
    bool memSaved;
    QString operation;
    Ui::UberCalc *ui;
    Calculator calc;
    void connectButtons();
    void clearLines();
public slots:
    void addToResultLine(QString newSym);
    void operationClicked(QString chosenOperation);
    void equalClicked();
    void clearClicked();
    void plus_minusClicked();
    void MemSaveClicked();
    void MemRestClicked();
};

