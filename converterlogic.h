#ifndef CONVERTERLOGIC_H
#define CONVERTERLOGIC_H
#include <QApplication>
#include <math.h>

class ConverterLogic : public QObject {

    Q_OBJECT

private:
    int base;
    QString number;
public:
    explicit ConverterLogic(QObject *parent = 0);

private:

    inline void clear(){ number = ""; emit numberChanged(); }

    void appendNumber(QString command);

    bool isNumber(QString command);

    void changeToHex();

    void changeToOct();

    void changeToBin();

    void changeToDec();

    void eraseLeft();

    void eraseRight();

    void anythingToDecimal();

    void decimalToAnything(int newBase);

signals:
    void numberChanged();
    void numberBaseChanged(int);

public:
    void doCommand(QString command);

    QString getNumber(){
        return number;
    }
};

#endif // CONVERTERLOGIC_H