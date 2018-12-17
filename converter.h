#ifndef CONVERTER_H
#define CONVERTER_H
#include "converterlogic.h"
#include <QWidget>

namespace Ui {
class Converter;
}

class Converter : public QWidget
{
    Q_OBJECT

public:
    explicit Converter(QWidget *parent = 0);
    ~Converter();

private slots:
    void onBtnClicked();
    void onRdbBtnClicked();
    void onNumberBaseChanged(int);
    void onNumberChanged();

private:
    ConverterLogic* conv;
    Ui::Converter *ui;
    void connectAll();
    void dissable(int);
    void enable();
};

#endif // CONVERTER_H
