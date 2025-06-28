#include "CalculatorQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CalculatorQt window;
    window.show();
    return app.exec();
}
