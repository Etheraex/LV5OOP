#ifndef CONVERTERLOGIC_H
#define CONVERTERLOGIC_H
#include <QApplication>
#include <QMessageBox>

class ConverterLogic : public QObject {
private:
    int base;
    QString number;

private:
    void clear(){
        number = "";
    }

    bool isNumber(QString command){
        QString numbers[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
        for(int i = 0;i < 16;i++)
            if(numbers[i]==command){
                return true;
                break;
            }
        return false;
    }

    void appendNumber(QString command){
        number += command;
    }

    void changeToHex(){
        /*
         * Check the current base and convert to hexadecimal
        */
        base = 16;
    }

    void changeToOct(){
        /*
         * Check current base and convert to octal
        */
        base = 8;
    }

    void changeToBin(){
        /*
         * Check current base and convert to binary
        */
        base = 2;
    }

    void changeToDec(){
        /*
         * Check current base and convert to decimal
        */
        base = 10;
    }

    void eraseLeft(){
        /*
         * TODO
        */
    }

    void eraseRight(){
        /*
         * TODO
        */
    }


public:
    void doCommand(QString command){
        if(command == "CLEAR")
            clear();
        else if(isNumber(command))
            appendNumber(command);
        else if(command == "2")
            changeToBin();
        else if(command == "8")
            changeToOct();
        else if(command == "10")
            changeToDec();
        else if(command == "16")
            changeToHex();
        else if(command == "EraseLeft")
            eraseLeft();
        else if(command == "EraseRight")
            eraseRight();
    }

    static ConverterLogic& getInstance(){
                static ConverterLogic instance;
                return instance;
    }
    int getBase(){
        return base;
    }

    QString getNumber(){
        return number;
    }

};

#endif // CONVERTERLOGIC_H
