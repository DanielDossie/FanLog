#include "Phone.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <iomanip>

using namespace std;

Phone::Phone() {
    
    areaCode = "";
    threeDigits = "";
    fourDigits = "";
    newnum = "";
}

//Phone::Phone(std::string areaCode, std::string threeDigits, std::string fourDigits) {
    //areaCode = areaCode;
    //threeDigits = threeDigits;
    //fourDigits = fourDigits;
//}
Phone::Phone(std::string number) {
    //newnum = "";
    //cout << "do we get number?" << number << endl;
    //cout << number.size() << " " << number.at(0) << endl;
    for (int i = 0; i < number.size(); i++) {
        newnum.push_back(number.at(i));
        if (number.at(i) == '(' || number.at(i) == ')' || number.at(i) == '-' || number.at(i) == ' ') {
            //cout << "in here?" << endl;
        }
        else {
            //cout << "here" << endl;
            //cout << number.at(i);
            //cout << "we reac h here?" << endl;
            numberString.push_back(number.at(i));
        }
    }
    //num = stoi(numberString);
    //cout << "Their number will be stored as " << numberString << endl;
    //numInt = strtoull(numberString, 10); //phone number int value is huge. find new function for stoi. strtoull maybe
    //cout << numberString << "<<< this is our numInt" << endl;
    num = atol(numberString.c_str());
    //cout << "here?" << endl;
}

void Phone::show() {
    //cout << "newNum.show() successfully called!" << numberString << endl;
}

