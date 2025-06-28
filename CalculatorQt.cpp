#include "CalculatorQt.h"
#include <QDebug>
#include <iostream>
#include <QMessageBox>

CalculatorQt::CalculatorQt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.btnZero, &QPushButton::clicked, this, &CalculatorQt::handleDigitClicked);
    connect(ui.btnOne, &QPushButton::clicked, this, &CalculatorQt::handleDigitClicked);
    connect(ui.btnTwo, &QPushButton::clicked, this, &CalculatorQt::handleDigitClicked);
    connect(ui.btnThree, &QPushButton::clicked, this, &CalculatorQt::handleDigitClicked);
    connect(ui.btnFour, &QPushButton::clicked, this, &CalculatorQt::handleDigitClicked);
    connect(ui.btnFive, &QPushButton::clicked, this, &CalculatorQt::handleDigitClicked);
    connect(ui.btnSix, &QPushButton::clicked, this, &CalculatorQt::handleDigitClicked);
    connect(ui.btnSeven, &QPushButton::clicked, this, &CalculatorQt::handleDigitClicked);
    connect(ui.btnEight, &QPushButton::clicked, this, &CalculatorQt::handleDigitClicked);
    connect(ui.btnNine, &QPushButton::clicked, this, &CalculatorQt::handleDigitClicked);
    connect(ui.btnPoint, &QPushButton::clicked, this, &CalculatorQt::handleDigitClicked);

    connect(ui.btnAddition, &QPushButton::clicked, this, &CalculatorQt::handleOperatorClicked);
    connect(ui.btnSubtraction, &QPushButton::clicked, this, &CalculatorQt::handleOperatorClicked);
    
    connect(ui.btnEqual, &QPushButton::clicked, this, &CalculatorQt::handleEqualClicked);
    connect(ui.btnClear, &QPushButton::clicked, this, &CalculatorQt::handleClearClicked);

    ui.output->setAlignment(Qt::AlignRight);

}

CalculatorQt::~CalculatorQt()
{}

void CalculatorQt::handleDigitClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    
    if (!button) return;
    if (currentInput == "0") currentInput.clear();

    currentInput += button->text();
    ui.output->setText(currentInput);
}

void CalculatorQt::handleOperatorClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button && currentInput.isEmpty()) return;

    pendingOperator = button->text();
    storeValue = currentInput.toDouble();
    currentInput.clear();
    ui.output->setText(pendingOperator);
}
void CalculatorQt::handleEqualClicked() {
    if (currentInput.isEmpty()) return;
    if (pendingOperator.isEmpty()) {
        ui.output->setText(currentInput);
        return;
    }

    double operand2 = currentInput.toDouble();
    double result;

    if (pendingOperator == "+") {
        result = storeValue + operand2;
    }
    else if (pendingOperator == "-") {
        result = storeValue - operand2;
    }
    

    ui.output->setText(QString::number(result));
}

void CalculatorQt::handleClearClicked() {
    storeValue = 0;
    pendingOperator = "";
    currentInput = "";
    ui.output->setText(currentInput);
}
