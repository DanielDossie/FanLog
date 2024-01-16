#ifndef _LL_H
#define _LL_H

#include <iostream>
#include "Node.h"
#include "Fan.h"

using namespace std;
class LL {
    //private:
        //Node* head = nullptr; //head initially should be a nullptr
        //int num_elements;
        //Class LL {
	public:
		LL() {head = tail = nullptr; num_elements = 0;}
		Node* insert(Fan fan);
		void show();
		bool find(Fan fan);
        void traverse(std::string outputfilename);
                //Node* head = nullptr;
                //Node* tail = nullptr;
        ~LL();
		
	private:
                int num_elements;
                Node* head = nullptr;
                Node* tail = nullptr;
        
    

};

#endif
