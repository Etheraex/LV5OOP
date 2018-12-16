#include "converter.h"
#include "ui_converter.h"
#include "converterlogic.h"

Converter::Converter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Converter)
{
    ui->setupUi(this);
    ConverterLogic::getInstance().doCommand("5");
    ConverterLogic::getInstance().doCommand("3");
    ConverterLogic::getInstance().doCommand("4");
    ConverterLogic::getInstance().setBase(10);
    ConverterLogic::getInstance().doCommand("EraseLeft");
    ConverterLogic::getInstance().doCommand("HEX");
    QString asd = ConverterLogic::getInstance().getNumber();
    ui->label->setText(asd);
}

Converter::~Converter()
{
    delete ui;
}
