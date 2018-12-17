#include "converter.h"
#include "ui_converter.h"

Converter::Converter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Converter)
{
    this->conv = new ConverterLogic;
    ui->setupUi(this);
    connectAll();
    ui->radioButtonDec->click();
}

void Converter::connectAll(){
    connect(ui->pushButton0,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButton3,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButton4,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButton5,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButton6,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButton7,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButton8,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButton9,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButtonA,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButtonB,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButtonC,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButtonD,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButtonE,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButtonF,SIGNAL(clicked()),this,SLOT(onBtnClicked()));

    connect(ui->pushButtonClear,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButtonLeft,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
    connect(ui->pushButtonRight,SIGNAL(clicked()),this,SLOT(onBtnClicked()));

    connect(ui->radioButtonBin,SIGNAL(clicked()),this,SLOT(onRdbBtnClicked()));
    connect(ui->radioButtonDec,SIGNAL(clicked()),this,SLOT(onRdbBtnClicked()));
    connect(ui->radioButtonHex,SIGNAL(clicked()),this,SLOT(onRdbBtnClicked()));
    connect(ui->radioButtonOct,SIGNAL(clicked()),this,SLOT(onRdbBtnClicked()));


    connect(this->conv,SIGNAL(numberChanged()),this,SLOT(onNumberChanged()));
    connect(this->conv,SIGNAL(numberBaseChanged(int)),this,SLOT(onNumberBaseChanged(int)));
}



void Converter::onBtnClicked(){
    QPushButton * btnClicked = (QPushButton*)sender();
    this->conv->doCommand(btnClicked->text());
}

void Converter::onRdbBtnClicked(){
    QRadioButton * btnClicked = (QRadioButton*)sender();
    this->conv->doCommand(btnClicked->text());
}

void Converter::enable(){
    ui->pushButtonF->setEnabled(true);
    ui->pushButtonE->setEnabled(true);
    ui->pushButtonD->setEnabled(true);
    ui->pushButtonC->setEnabled(true);
    ui->pushButtonB->setEnabled(true);
    ui->pushButtonA->setEnabled(true);
    ui->pushButton9->setEnabled(true);
    ui->pushButton8->setEnabled(true);
    ui->pushButton7->setEnabled(true);
    ui->pushButton6->setEnabled(true);
    ui->pushButton5->setEnabled(true);
    ui->pushButton4->setEnabled(true);
    ui->pushButton3->setEnabled(true);
    ui->pushButton2->setEnabled(true);
}

void Converter::dissable(int base){
    if(base <= 10){
        ui->pushButtonF->setEnabled(false);
        ui->pushButtonE->setEnabled(false);
        ui->pushButtonD->setEnabled(false);
        ui->pushButtonC->setEnabled(false);
        ui->pushButtonB->setEnabled(false);
        ui->pushButtonA->setEnabled(false);
    }
    if(base <= 8){
        ui->pushButton9->setEnabled(false);
        ui->pushButton8->setEnabled(false);
    }
    if(base <= 2){
        ui->pushButton7->setEnabled(false);
        ui->pushButton6->setEnabled(false);
        ui->pushButton5->setEnabled(false);
        ui->pushButton4->setEnabled(false);
        ui->pushButton3->setEnabled(false);
        ui->pushButton2->setEnabled(false);
    }
}

void Converter::onNumberBaseChanged(int base){
    enable();
    dissable(base);
    QString asd = this->conv->getNumber();
    ui->lineEdit->setText(asd);
}

void Converter::onNumberChanged(){
    QString asd = this->conv->getNumber();
    ui->lineEdit->setText(asd);
}

Converter::~Converter()
{
    delete ui;
}
