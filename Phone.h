#ifndef _PHONE_H
#define _PHONE_H

#include <iostream>
#include <vector>

class Phone {
    private:
    std::string areaCode;
    std::string threeDigits;
    std::string fourDigits;
    long num;
    std::string numberString;
    std::string newnum;
    //std::string getNumString() {return numberString;};
    long numInt;
    public:
    Phone();
    //Phone(std::string AreaCode, std::string threeDigits, std::string fourDigits);
    Phone(std::string number);
    std::string getNumString() {return numberString;};
    std::string getActualPhone() {return newnum;};
    //bool operator<(Phone& lhs, Phone& rhs);
    long getNum() {return num;};
    void show();

};


#endif