#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "Node.hpp"

#include <stdio.h>  //import equivalent

class LinkedList
{
private:
    Node* head; //points to the first element in the linked list
                //Node* holds the address of the first Node object in the linked list

    int count;  //field that tells us how many nodes there are in the linked list
                //this should increment everytime we create a new node object
    Node* findEnd();
    
public:
    LinkedList(); //constructor for new linked list, no parameters because we are creating an empty list
    void addFront(int payload);  //method to add a node to the front of the linked list
    int getFront();
    int removeFront(); 
    void addEnd(int payload);
    int getEnd();
    int removeEnd();

    int getIndex(int index);    //return payload at given index in LinkedList
    void addAtIndex(int index, int payload);    //take payload and add node at given index with said payload
    int removeAtIndex(int index);   //remove node from index and return its payload

    void display();
     
};
#endif /* LinkedList_hpp */