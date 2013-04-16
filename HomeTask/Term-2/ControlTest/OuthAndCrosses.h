#pragma once

#include <QWidget>

#include <QPushButton>

namespace Ui {
class OuthAndCrosses;
}

class OuthAndCrosses : public QWidget
{
    Q_OBJECT
    
public:
    explicit OuthAndCrosses(QWidget *parent = 0);
    ~OuthAndCrosses();
    bool BtnPressed[9];
private:
    Ui::OuthAndCrosses *ui;
    QString Sequence;
    void changeSequence();
    void checkEnd();
private slots:
    void connectButtons();
    void button1Clicked();
    void button2Clicked();
    void button3Clicked();
    void button4Clicked();
    void button5Clicked();
    void button6Clicked();
    void button7Clicked();
    void button8Clicked();
    void button9Clicked();

};

