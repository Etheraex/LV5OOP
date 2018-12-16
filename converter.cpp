#include "converter.h"
#include "ui_converter.h"
#include "converterlogic.h"

Converter::Converter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Converter)
{
    ui->setupUi(this);
    ConverterLogic::getInstance().doCommand("HEX");
    ConverterLogic::getInstance().doCommand("A");
    ConverterLogic::getInstance().doCommand("C");
    ConverterLogic::getInstance().doCommand("5");
    ConverterLogic::getInstance().doCommand("OCT");
    QString asd = ConverterLogic::getInstance().getNumber();
    ui->label->setText(asd);
}

Converter::~Converter()
{
    delete ui;
}
