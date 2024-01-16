#include <iostream>

#include "Fan.h"
using namespace std;

class BSTNode {
			public:
				BSTNode() {data = Fan(); next = nullptr;};
				BSTNode(Fan &d) {data = d; next = nullptr;}
                //string data;
				Fan data;
				BSTNode *next;
			private:
				//string data;
				//Node *next;
        };