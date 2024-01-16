#ifndef _BSTTEMP_H
#define _BSTTEMP_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "Phone.h"
#include "Email.h"
#include <vector>
#include "Node.h"
#include "Fan.h"

using namespace std;

template <class T> class BSTTemp { 
   private: 
      //vector<T> elems;    // elements 
      //T *fanObject;
      //BSTNode root;
      //Node *left;
      //Node *right;

   public: 
      BSTTemp() {BSTNode *root = NULL;};
      BSTTemp(T const&);  // push element 
      void insert(T object, Node *node);
      //void show(BSTNode root);
      bool search(T object);
      Node *find(string input);
      void remove(T object);
      //void BSTTempDestruct(BSTNode node);
      
      //bool empty() const {      // return true if empty.
         //return elems.empty(); 
      //} 
     class BSTNode {
			public:
				BSTNode() {};//data = ""; left = right = nullptr;};
				BSTNode(T &d) {par = NULL; data = d.getNumString(); findval = &d; left = right = nullptr;};
                BSTNode(T &d, Fan &fan) {par = NULL; data = d; num = atol(d.getNumString().c_str()); fanObject = &fan; left = right = nullptr;};
                BSTNode(T &d, Node *node) {par = NULL; data = d; num = atol(d.getNumString().c_str()); LLNode = node; left = right = nullptr;};
                
                //string data;
				T data;
                long num;
                T *findval;
                //NEED A POINTER TO A LL NODE NOT A FAN.
                Node *LLNode;
                Fan *fanObject;
                BSTNode *par;
				BSTNode *left;
                BSTNode *right;
			private:
				//string data;
				//Node *next;
        };
    BSTNode *root;  
    void show();
    void BSTTempDestruct(BSTNode *node);
    
}; 


template <class T>
void BSTTemp<T>::insert(T object, Node *node){
    //cout << "SPOT 1" << endl;
    //cout << "SPOT 1" << endl;
    BSTNode *newnode = new BSTNode(object, node); 
    //cout << "SPOT 5" << endl;
    //cout << "we are about to process " << newnode->num << endl;
    if (root == NULL) {
        //cout << "spot 6" << endl;
        root = newnode;
        return;
    }
    else {
        //cout <<"HEREHERHERHERHE" << "hi" << endl;
        //cout <<"WHATTTTT" << endl;
        BSTNode *curr = root;
        //cout <<"HEREHERHERHERHE" << endl;
        while (curr!=NULL) {
            //cout << "spot 7: " << newnode->data.getNumString() << " " << curr->data.getNumString() << endl;
            if (newnode->data < curr->data) {
                //cout << "spot 8: " << newnode->data.getNumString() << " " << curr->data.getNumString() << endl;
                if (curr->left == NULL){
                    //cout << "spot 9" << endl;
                    curr->left = newnode;
                    //cout 
                    curr = NULL;
                    //return;
                }
                else {
                    //cout << "spot 10" << endl;
                    curr = curr->left;
                    //cout << "CURRENT HERE IS" << curr->data.getNumString() << endl;
                }
            }
            else {
                //cout << "so " << newnode->data.getNumString() << " is not less than " << curr->data.getNumString() << " ?" << endl;
                if (curr->right == NULL){
                    //cout << "spot 11" << endl;
                    curr->right = newnode;
                    curr = NULL;
                }
                else {
                    curr = curr->right;
                    //cout << "spot 12" << endl;
                }
            }
        }
        //cout << "Out of while loop" << endl;
    }
    //cout << "insert called" << endl;
    //cout << "Root: " << root->data << endl;
    //cout << "Left of root: " << root->left->data << endl;
    //cout << "Right of root: " << root->right->data << endl;
    //cout << "Left of left of root: " << root->left->left->data << endl;
    return;
}

template <class T>
void BSTTemp<T>::show() {
    //cout << "BST SHOW CALLED" << endl;
    BSTNode *newnode = new BSTNode();
    BSTNode *curr = root;
    //cout << "Root:" << root->data.getNumString() << endl;
    if (curr == NULL) {
        return;
    }
    else {
        if (root->left!=NULL) {
            if (root->left->left!=NULL) {
            //cout << "Brians NUmber below" << endl;
            //cout << root->left->left->data.getNumString() << " prior to this is Brians number in left left subtree" << endl;
            }
        }
        //while (curr!=NULL) {
        //    if (curr->right!=NULL) {
        //        cout << curr->right->data << endl;
        //    }
        //    else if (curr->right!=NULL) {
       //         cout << "right NODE" << curr->right->data << endl;
        //    }
        //    else {
        //        cout << "Both spots full. Both Left and irght Printed" << endl;
        //        curr = NULL;
        //    }
    }
    delete newnode;
    //show(rootval->left);
    //cout << root->data << endl;
    //show(rootval->right);
}

template <class T>
bool BSTTemp<T>::search(T object){
    //cout << "search called" << endl;
    BSTNode *newnode = new BSTNode(object);
    BSTNode *curr = root;
    while (curr!=NULL) {
        if (newnode->data == curr->data) {
            delete newnode;
            return curr;
        }
        else if (newnode->data < curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    delete newnode;
    return false;
}

template <class T>
Node *BSTTemp<T>::find(string input){
    //cout << "find called" << endl;
    T object(input);
    //cout << "T Object" << endl;
    BSTNode *newnode = new BSTNode(object);
    //cout << "BST" << endl;
    BSTNode *curr = root;
    //cout << "3" << endl;
    while (curr!=NULL) {
        if (newnode->data == curr->data) {
            //cout << "do we get here" << endl;
            delete newnode;
            return curr->LLNode;
        }
        else if (newnode->data < curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    cout << "bst::find() : " << input << " Not found" << endl;
    delete newnode;
    return NULL;
}

template <class T>
void BSTTemp<T>::remove(T object) {
    cout << "BST SPOT 1" << endl;
    BSTNode *par = NULL;
    cout << "BST SPOT 2" << endl;
    BSTNode *curr = root;
    cout << "BST SPOT 3" << endl;
    while (curr!=NULL) {
        cout << "BST SPOT 55" << endl;
        if (curr->data == object) {  
            cout << "BST SPOT 4" << endl;  
            if (curr->left==NULL && curr->right==NULL) {
                cout << "BST SPOT 5" << endl;
                if (par == NULL) {
                    cout << "BST SPOT 6" << endl;
                    root = NULL;
                }
                else if (par->left == curr){
                    cout << "BST SPOT 7" << endl;
                    par->left = NULL;
                }
                else {
                    cout << "BST SPOT 8" << endl;
                    par->right = NULL;
                }
            }
            else if (curr->right == NULL) {
                cout << "BST SPOT 9" << endl;
                if (par == NULL) {
                    cout << "BST SPOT 10" << endl;
                    root = curr->left;
                }
                else if (par->left == curr){
                    cout << "BST SPOT 11" << endl;
                    par->left = curr->left;
                }
                else {
                    cout << "BST SPOT 12" << endl;
                    par->right = curr->left;
                }
            }
            else if (curr->left == NULL) {
                cout << "BST SPOT 13" << endl;
                if (par == NULL) {
                    cout << "BST SPOT 14" << endl;
                    root = curr->right;
                }
                else if (par->left == curr) {
                    cout << "BST SPOT 15" << endl;
                    par->left = curr->right;
                }
                else {
                    cout << "BST SPOT 16" << endl;
                    par->right = curr->right;
                }
            }
            else {
                //cout << "BST SPOT 345" << endl;
                BSTNode *suc = new BSTNode();
                suc = curr->right;
                if (curr->right->fanObject == NULL) {
                    //cout << "FAN NULL" << endl;
                }
                while (suc->left!=NULL) {
                    suc = suc->left;
                    if (suc == NULL) {
                        //cout << "HOW" << endl;
                    }
                }
                if (suc->LLNode->data.getFirst().empty()) {
                    //cout << "fanOb NULL" << endl;
                }
                BSTNode *sucData = suc;
                //cout << "BST SPOT 400" << endl;
                if (suc->fanObject == NULL) {
                    //cout << "ITS NULL" << endl;
                }
                //remove(object);
                break;
                cout << "BST SPOT 5" << endl;
            }
        }
        else if (curr->data < object) {
            cout << "BST SPOT 344" << endl;
            par = curr;
            curr = curr->left;
        }
        else {
            cout << "BST SPOT 311" << endl;
            par = curr;
            curr = curr->right;
        }
    }
    return;
};

template <class T>
void BSTTemp<T>::BSTTempDestruct(BSTNode *node) {
    
    if (node->left != NULL) {
        BSTTempDestruct(node->left);
    }
    if (node->right != NULL) {
        BSTTempDestruct(node->right);
    }
    delete node;
}

#endif
