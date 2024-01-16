#include "Email.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <iomanip>

using namespace std;

Email::Email() {
    email = "";
}

Email::Email(std::string email) {
    email = email;
    numberString = "";
    for (int i = 0; i < email.size(); i++) {
        num.push_back(email.at(i));
        if (isalpha(email.at(i))) {
            numberString.push_back(email.at(i));
        }
        else {
        }
    }
    //cout << "Email value: " << numberString << endl;
}