#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CalculatorQt.h"

class CalculatorQt : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorQt(QWidget *parent = nullptr);
    ~CalculatorQt();

private slots:
    void handleDigitClicked();
    void handleOperatorClicked();
    void handleEqualClicked();
    void handleClearClicked();

private:
    Ui::CalculatorQtClass ui;
    QString currentInput;
    QString pendingOperator;
    double storeValue = 0.0;

};

