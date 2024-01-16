#ifndef _NODE_H
#define _NODE_H

#include <iostream>

#include "Fan.h"
using namespace std;

class Node {
			public:
				Node() {data = Fan(); next = prev = nullptr;};
				Node(Fan &d) {data = d; next = prev = nullptr;}
                //string data;
				Fan data;
				Node *next;
				Node *prev;
			private:
				//string data;
				//Node *next;
        };

#endif