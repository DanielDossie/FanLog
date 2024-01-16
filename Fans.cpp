#include <stdio.h>
#include "Parser.h"
#include <cctype>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include "Phone.h"
#include "BSTTemp.h"
#include "LL.h"
#include "Email.h"
#include "Fan.h"
#include <sstream>
#include <unistd.h>
#include <assert.h>
#include <string>
#include <fstream>
using namespace std;

LL linkedList = LL();
BSTTemp<Phone> p;
BSTTemp<Email> e;
string P_OR_E = "";

//void outputUpdate() {
//    for (Node *np = head; np!=nullptr; np = np->next) {
//        cout << np->data.getFirst() << endl;
//    }
//}
string strConvert(string PhoneOrEmail) {
    if (P_OR_E == "Email") {
        string numberString = "";
        for (int i = 0; i < PhoneOrEmail.size(); i++) {
            if (isalpha(PhoneOrEmail.at(i))) {
                numberString.push_back(PhoneOrEmail.at(i));
            }
            else {
            }
        }
        return numberString;
    }
    else {
        
        string numberString = "";
        for (int i = 0; i < PhoneOrEmail.size(); i++) {
            if (PhoneOrEmail.at(i) == '(' || PhoneOrEmail.at(i) == ')' || PhoneOrEmail.at(i) == '-' || PhoneOrEmail.at(i) == ' ') {
            //cout << "in here?" << endl;
            }
            else {
            //cout << "here" << endl;
            //cout << number.at(i);
            //cout << "we reac h here?" << endl;
            numberString.push_back(PhoneOrEmail.at(i));
            }
        }
        return numberString;
    }
}

bool stringEval(string PhoneOrEmail) {
    for (int i = 0; i < PhoneOrEmail.size(); i++) {
        if (PhoneOrEmail.at(i) == '@') {
            P_OR_E = "Email";
            return true;
        }
        else {

        }
    }
    if (P_OR_E != "Email") {
        P_OR_E = "Phone";
        return true;
    }
}

bool concessionsCheck(string con) {
    for (int i = 0; i < con.size(); i++) {
        if (con.at(i) >= '0' && con.at(i) <= '9') {
        }
        else {
            return false;
        }
    }
    return true;
}

bool nameCheck(string name) {
    for (int i = 0; i < name.size(); i++) {
        if ((name.at(i) >= 'a' && name.at(i) <= 'z') || (name.at(i) >= 'A' && name.at(i) <= 'Z')) {
    }
        else {
        return false;
        }
        if (!isupper(name.at(0))) {
            return false;
        }
    }
    return true;
}

bool emailCheck(string mail) {
    int atchecker = 0;
    int dashchecker = 0;
    int charchecker = 0;
    int digitchecker = 0;
    int totchars = 0;
    for (int i = 0; i < mail.size(); i++) {
        totchars++;
        if (mail.at(i) == '@') {
            atchecker++;
        }
        else if (mail.at(i) == '.') {
            dashchecker++;
        }
        else if (mail.at(i) >= '0' && mail.at(i) <= '9') {
            digitchecker++;
        }
        else if ((mail.at(i) >= 'a' && mail.at(i) <= 'z') || (mail.at(i) >= 'A' && mail.at(i) <= 'Z')) {
            charchecker++;
        }
    }
    //cout << "Stats: " << atchecker << " " << dashchecker << " " << charchecker << endl;
    if (atchecker != 1) {
        return false;
    }
    if (dashchecker != 1) {
        return false;
    }
    if (dashchecker + charchecker + atchecker + digitchecker != totchars) {
        return false;
    }
    return true;
}

bool PhoneCheck(string number) {
    int atchecker = 0;
    if (number.size() != 13) {
        return false;
    }
    for (int i = 0; i < number.size(); i++) {
        
        if (number.at(i) == '@') {
            atchecker++;
        }
        else{

        }
    }
    //assert(atchecker == 1);
    //cout << number.at(0) << " << THis is numat 0" << endl;
    //assert(number.at(0) == '(');
    //assert(number.at(4) == ')');
    //assert(number.at(8) == '-');
    if (number.at(0) == '(') {

    }
    else {
        return false;
    }
    if (number.at(4) == ')') {

    }
    else {
        return false;
    }
    if (number.at(8) == '-') {

    }
    else {
        return false;
    }
    if (number.at(1) >= '0' && number.at(1) <= '9') {

    }
    else {
        return false;
    }
    if (number.at(2) >= '0' && number.at(2) <= '9') {

    }
    else {
        return false;
    }
    if (number.at(3) >= '0' && number.at(3) <= '9') {

    }
    else {
        return false;
    }
    if (number.at(5) >= '0' && number.at(5) <= '9') {

    }
    else {
        return false;
    }
    if (number.at(6) >= '0' && number.at(6) <= '9') {

    }
    else {
        return false;
    }
    if (number.at(7) >= '0' && number.at(7) <= '9') {

    }
    else {
        return false;
    }
    if (number.at(9) >= '0' && number.at(9) <= '9') {

    }
    else {
        return false;
    }
    if (number.at(10) >= '0' && number.at(0) <= '9') {

    }
    else {
        return false;
    }
    if (number.at(11) >= '0' && number.at(11) <= '9') {

    }
    else {
        return false;
    }
    if (number.at(12) >= '0' && number.at(12) <= '9') {

    }
    else {
        return false;
    }
    return true;
    
}

bool operator<(Phone& lhs, Phone& rhs) {
    return lhs.getNum() < rhs.getNum();
}

bool operator>(Phone& lhs, Phone& rhs) {
    return lhs.getNum() > rhs.getNum();
}

bool operator==(Phone& lhs, Phone& rhs) {
    return lhs.getNum() == rhs.getNum();
}

bool operator<(Email& lhs, Email& rhs) {
    return lhs.getNumString() < rhs.getNumString();
}

bool operator>(Email& lhs, Email& rhs) {
    return lhs.getNumString() > rhs.getNumString();
}

bool operator==(Email& lhs, Email& rhs) {
    return lhs.getNumString() == rhs.getNumString();
}


int commands() {

}

int readFiles(string inputfile, string outputfile) {
    cout << "readFiles() is running with input as " << inputfile << endl;
    string line;
    int numlines;
    string inputfilename;
    string outputfilename;
    ifstream infile;
    ofstream outfile;
    infile.open(inputfile);
    outfile.open(outputfile);
    if (!infile.is_open()) {
      cout << "Could not open file" << endl;
      return 1;
    }
    while(!infile.eof()) {
        //cout << "We here?" << endl;
        //numTeams++;
        getline(infile, line);
        numlines++;
        //cout << "We here 2 ?" << endl;
        //getline(cin, teamName, region, seed);
        Parser arg1(line);
        Parser arg2(line);
        Parser arg3(line);
        Parser arg4(line);
        Parser arg5(line);
        Parser arg6(line);
        /*if (arg1.getArg1() == "Quit") {
         if (arg1.numArgs() > 0) 
            cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl; 
         cout << "Quittin" << endl;
         exit(0);
        }
        else if (arg1.getArg1() == "Load") {
            cout << "Load" << endl;
        }
        else if (arg1.getArg1() == "Show") {

        }
        else if (arg1.getArg1() == "Spend") {

        }
        else if (arg1.getArg1() == "Remove") {
            cout << "gonnna remove some info" << endl;
        }
        else if (arg1.getArg1() == "Process") {
            readFiles(arg1.getArg2());
        }
        else {*/
        const string last = arg1.getArg1();
        const string first = arg2.getArg2();
        string num = arg3.getArg3();
        string email = arg4.getArg4();
        string seat = arg5.getArg5();
        string con = arg6.getArg6();
        unsigned int concession = stoi(arg6.getArg6());
        if (PhoneCheck(num) == false) {
            cout << "PhoneCheck was false for " << num << endl;
            continue;
        }
        if (emailCheck(email) == false ) {
            cout << "emailCheck was false for " << email << endl;
            continue;
        }
        if (nameCheck(last) == false ) {
            cout << "NameCheck was false for " << last << endl;
            continue;
        }
        if (nameCheck(first) == false ) {
            cout << "NameCheck was false for " << first << endl;
            continue;
        }
        if (concessionsCheck(con) == false ) {
            cout << "concessionsCheck was false for " << con << endl;
            continue;
        }
        Phone newNum(num);
        Email newEmail(email);
        newNum.show();
        //cout << "SEAT TESTER :: " << seat << endl;
        Fan newFan(first, last, newNum, newEmail, seat, concession);
        //cout << ":NEWFANTESTER: " << newFan.getSeat() << endl;
        Node *BNode = linkedList.insert(newFan);
        linkedList.show();
        p.insert(newNum, BNode);
        e.insert(newEmail, BNode);
        p.show();
        e.show();
        //outfile << last << " " << first << " " << newNum.getNum() << " " << newEmail.getNumString() << " " << seat << " " <<concession << endl;
        //e.show();
        //cout << "ELSE STATEMENT EXECUTING?" << endl;
        cout << last << " " << first << " " << num << " " << email << " " << seat << " " << concession << endl;
    } 
    return 0;
}
int process(string inputfile){
    cout << "readFiles() is running with input as " << inputfile << endl;
    string line;
    int numlines;
    string inputfilename;
    string outputfilename;
    ifstream infile;
    ofstream outfile;
    infile.open(inputfile);
    if (!infile.is_open()) {
      cout << "Could not open file" << endl;
      return 1;
    }
    while(!infile.eof()) {
        getline(infile, line);
        numlines++;
        Parser arg1(line);
        if (arg1.getArg1() == "Quit") {
         if (arg1.numArgs() > 0) 
            cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl; 
         cout << "Quitting" << endl;
         p.BSTTempDestruct(p.root);
         e.BSTTempDestruct(e.root);
         exit(0);
        }
        else if (arg1.getArg1() == "Load") {
            cout << "Inside Process function: Load" << endl;
            readFiles(arg1.getArg2(), arg1.getArg3());
        }
        else if (arg1.getArg1() == "Show") {
            cout << "Inside Process function: Show command called" << endl;
        }
        else if (arg1.getArg1() == "Spend") {
            cout << "Inside Process function: Spend command called" << endl;
        }
        else if (arg1.getArg1() == "Remove") {
            cout << "Inside Process function: Remove Called." << endl;
        }
        else if (arg1.getArg1() == "Process") {
            cout << "Process command called" << endl;
            process(arg1.getArg2());
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int op;
    //LL linkedList = LL();
    string line;
    int numlines;
    string inputfilename;
    string outputfilename;
    ifstream infile;
    ofstream outfile;
    while ((op = getopt(argc, argv, ":i:o:")) != -1) {
        switch(op) {
            case 'i':
                cout << "opt is i. Oparg is " << optarg << endl;
                inputfilename = optarg;
                //infile.open(inputfilename); 
                break;
            case 'o':
                cout << "opt is o, oparg is " << optarg << endl;
                outputfilename = optarg;
                //outfile.open(optarg);
                break;
            case '?':
                break;
        }
    }
    //cout << " Made to End of File" << endl;
    readFiles(inputfilename, outputfilename);
    while (1) {
        //cout << "We here?" << endl;
        cout << "Choose Command: " << endl;
        cout << "Load <input-filename>" << endl;
        cout << "Show <fan-id>" << endl;
        cout << "Spend <fan-id> <dollars>" << endl;
        cout << "Remove <fan-id>" << endl;
        cout << "Process <commands-filename>" << endl;
        cout << "Quit" << endl;
        cout << " : ";
        getline(cin, line);
        Parser command(line);
        if (command.getArg1().empty()) {
            if (std::cin.fail()) {
	            break;
            }
        continue;
        }
        //readFiles(command.getArg1());
    /*infile.open(inputfilename);
    //outfile.open(outputfilename);
    if (!infile.is_open()) {
      cout << "Could not open file" << endl;
      return 1;
    }
    while(!infile.eof()) {*/    
        /*cout << "We here?" << endl;
        cout << "Choose Command:" << endl;
        cout << "Load" << endl;
        cout << "Show" << endl;
        cout << "Spend" << endl;
        cout << "Remove" << endl;
        cout << "Process" << endl;
        cout << "Quit" << endl;*/
        //numTeams++;
        numlines++;
        //cout << "We here 2 ?" << endl;
        //getline(cin, teamName, region, seed);
        Parser arg1(line);
        Parser arg2(line);
        Parser arg3(line);
        Parser arg4(line);
        Parser arg5(line);
        Parser arg6(line);
        if (arg1.getArg1() == "Quit") {
         if (arg1.numArgs() > 0) 
            cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl; 
         linkedList.traverse(outputfilename);
         cout << "Quittin" << endl;
         break;
        }
        else if (arg1.getArg1() == "Load") {
            if (arg1.numArgs() == 1) { 
                cout << "Load command called" << endl;
                readFiles(arg1.getArg2(), arg1.getArg3());
            }
            else if (arg1.numArgs() > 1) {
                cout  << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
                readFiles(arg1.getArg2(), arg1.getArg3());
            }
            else {
                cout << "Can't operate with missing arguments";
            }
        }
        else if (arg1.getArg1() == "Show") {
            if (arg1.numArgs() == 1) { 
                cout << "Show command called" << endl;
                stringEval(arg1.getArg2());
                std::string finder = strConvert(arg1.getArg2());
                std::string findInput = finder;
                if (P_OR_E == "Email") {
                    Node *val = e.find(findInput);
                    cout << val->data.getLast() << " " << val->data.getFirst() << " " << val->data.getActualPhone() << " " << val->data.getActualEmail() << " " << val->data.getSeat() << " " << val->data.getConcessions() << endl;
                }
                else {
                    Node *val = p.find(findInput);
                    cout << val->data.getLast() << " " << val->data.getFirst() << " " << val->data.getActualPhone() << " " << val->data.getActualEmail() << " " << val->data.getSeat() << " " << val->data.getConcessions() << endl;

                }
            }
            else if (arg1.numArgs() > 1) {
                cout  << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
                cout << "Show command called" << endl;
                stringEval(arg1.getArg2());
                std::string finder = strConvert(arg1.getArg2());
                std::string findInput = finder;
                if (P_OR_E == "Email") {
                    Node *val = e.find(findInput);
                    cout << val->data.getActualEmail() << endl;
                }
                else {
                    Node *val = p.find(findInput);
                    cout << val->data.getActualPhone() << endl;

                }
            }
            else {
                cout << "Can't operate with missing arguments";
            }
        }
        else if (arg1.getArg1() == "Spend") {
            if (arg1.numArgs() == 2) { 
                cout << "Spend command called" << endl;
                std::string findInput = arg1.getArg2();
                Node *val = p.find(findInput);
                unsigned int arg = stoi(arg3.getArg3());
                val->data.setConcessions(arg);
                cout << val->data.getConcessions() << "GET CONCESSIONS" << endl;
                //readFiles(arg1.getArg2(), arg1.getArg3());

            }
            else if (arg1.numArgs() > 2) {
                cout  << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
                cout << "Spend command called" << endl;
                std::string findInput = arg1.getArg2();
                Node *val = p.find(findInput);
                unsigned int arg = stoi(arg3.getArg3());
                val->data.setConcessions(arg);
                cout << "concessions: " << val->data.getConcessions() << endl;
            }
            else {
                cout << "Can't operate with missing arguments";
            }
        }
        else if (arg1.getArg1() == "Remove") {
            if (arg1.numArgs() == 1) { 
                cout << "Remove command called" << endl;
                std::string findInput = arg1.getArg2();
                Node *FindNode = p.find(findInput);
                if (FindNode == NULL) {
                    cout << "Its null" << endl;
                }
                else {
                    cout << "Dereferencing FindNode: " << FindNode << endl;
                    Fan findString = FindNode->data;
                    cout << "FIND PERSON " << FindNode->data.getFirst() << endl;
                }
                p.remove(FindNode->data.getPhone());
                //readFiles(arg1.getArg2());
            }
            else if (arg1.numArgs() > 1) {
                cout  << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
                cout << "Remove command called" << endl;
            }
            else {
                cout << "Can't operate with missing arguments";
            }
        }
        else if (arg1.getArg1() == "Process") {
            if (arg1.numArgs() == 1) { 
                cout << "Process command called" << endl;
                process(arg1.getArg2());
            }
            else if (arg1.numArgs() > 1) {
                cout  << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
                cout << "Process command called" << endl;
                process(arg1.getArg2());
            }
            else {
                cout << "Can't operate with missing arguments";
            }
        }
        else {
            cout << "Unrecognized Command: Please try again." << endl;
        //string last = arg1.getArg1();
        //string first = arg2.getArg2();
        //string num = arg3.getArg3();
        //string email = arg4.getArg4();
        //string seat = arg5.getArg5();
        //string concession = arg6.getArg6();
        //cout << last << first << num << email << seat << concession << endl;
        }
    }
    return 0;
    //use getopt or argparse or use argv
}