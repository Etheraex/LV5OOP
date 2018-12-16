#ifndef CONVERTERLOGIC_H
#define CONVERTERLOGIC_H
#include <QApplication>
#include <math.h>

class ConverterLogic : public QObject {
private:
    int base;
    QString number;

private:

    inline void clear(){ number = ""; }

    inline void appendNumber(QString command){ number += command; }

    bool isNumber(QString command);

    void changeToHex();

    void changeToOct();

    void changeToBin();

    void changeToDec();

    void eraseLeft();

    void eraseRight();

    void anythingToDecimal();

    void decimalToAnything(int newBase);

public:
    void doCommand(QString command);

    static ConverterLogic& getInstance(){
        static ConverterLogic instance;
        return instance;
    }

    QString getNumber(){
        return number;
        /* This will be removed in the final version */
    }
};

#endif // CONVERTERLOGIC_H