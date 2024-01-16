#include "Fan.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>

using namespace std;

Fan::Fan() {
    firstName = "";
    lastName = "";
    number;
    email;
    seat = "hi";
    concession = -1;
}

Fan::Fan(const std::string &first, const std::string &last,
             const Phone num, const Email e, const std::string &seatName, const unsigned int &con) {
    firstName = first;
    lastName = last;
    number = num;
    email = e;
    seat = seatName;
    concession = con;
    }

Fan::~Fan() {
    //delete Fan;
}
