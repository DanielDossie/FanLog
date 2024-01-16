#ifndef _FAN_H
#define _FAN_H


#include <iostream>
#include "Email.h"
#include "Phone.h"

class Fan {
   private:
      std::string firstName;
      std::string lastName;
      Phone number;
      Email email;
      std::string seat;
      unsigned int concession;
      
      


   public:
      Fan();
      ~Fan();
      Fan(const std::string &first, const std::string &last,
             const Phone number, const Email email, const std::string &seat, const unsigned int &concession);
      std::string getFirst() {return firstName;};
      std::string getLast() {return lastName;};
      std::string getSeat() {return seat;};
      unsigned int getConcessions() {return concession;};
      void setConcessions(int input) {concession = concession + input;};
      std::string getPhone() {return number.getNumString();};
      std::string getEmail() {return email.getNumString();};
      std::string getActualPhone() {return number.getActualPhone();};
      std::string getActualEmail() {return email.getActualEmail();};

};

#endif