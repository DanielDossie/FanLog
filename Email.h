#ifndef _EMAIL_H
#define _EMAIL_H

#include <iostream>

class Email {
    private:
    std::string email;
    std::string numberString;
    std::string num;

    public:
    Email();
    Email(std::string email);
    std::string getNumString() {return numberString;};
    std::string getActualEmail() {return num;};

};


#endif