#include "converterlogic.h"

void ConverterLogic::doCommand(QString command){
    if(command == "CLEAR")
        clear();
    else if(isNumber(command))
        appendNumber(command);
    else if(command == "BIN")
        changeToBin();
    else if(command == "OCT")
        changeToOct();
    else if(command == "DEC")
        changeToDec();
    else if(command == "HEX")
        changeToHex();
    else if(command == "EraseLeft")
        eraseLeft();
    else if(command == "EraseRight")
        eraseRight();
}

bool ConverterLogic::isNumber(QString command){
    QString numbers =  "0123456789ABCDEF";
    for(int i = 0;i < 16;i++)
        if(numbers[i]==command){
            return true;
            break;
        }
    return false;
}

void ConverterLogic::changeToHex(){
    if(base != 16 && number != ""){
        if(base != 10)
            anythingToDecimal();
        decimalToAnything(16);
    }
    base = 16;
}

void ConverterLogic::changeToOct(){
    if(base!=8 && number != ""){
        if(base != 10)
            anythingToDecimal();
        decimalToAnything(8);
    }
    base = 8;
}

void ConverterLogic::changeToBin(){
    if(base != 2 && number != ""){
        if(base != 10)
            anythingToDecimal();
        decimalToAnything(2);
    }
    base = 2;
}

void ConverterLogic::changeToDec(){
    if(base!=10 && number != "")
        anythingToDecimal();
    base = 10;
}

void ConverterLogic::eraseLeft(){
    QString tmp = "";
    for(int i = 1;i<number.length();i++)
        tmp+=number[i];
    number = tmp;
}

void ConverterLogic::eraseRight(){
    QString tmp = "";
    for(int i = 0;i<number.length()-1;i++)
        tmp+=number[i];
    number = tmp;
}

int value(QString c){
   if (c >= "0" && c <= "9")
        return c.toInt();
    else if (c=="A")
        return 10;
    else if(c == "B")
        return 11;
    else if(c == "C")
        return 12;
    else if(c == "D")
        return 13;
    else if(c == "E")
        return 14;
    else if(c == "F")
        return 15;
    return 20;
}

void ConverterLogic::anythingToDecimal(){
    int num =0;

    for(int i =0;i<number.length();i++)
        num += (value(QString(number[i])) * pow(base, number.length()-1-i));
    number = QString::number(num);
}

void ConverterLogic::decimalToAnything(int newBase){
    int convertFrom = number.toInt();
    int digit;
    std::string stringDigit, answer;
    while (convertFrom != 0){
        digit = convertFrom % newBase;
        if (digit < 10)
            stringDigit = '0' + digit;
        else
            stringDigit = digit - 10 + 'A';
        answer = stringDigit + answer;
        convertFrom /= newBase;
        number = QString::fromStdString(answer);
    }
}












