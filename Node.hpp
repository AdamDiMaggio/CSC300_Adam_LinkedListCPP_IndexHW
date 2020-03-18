#ifndef Node_hpp
#define Node_hpp

class Node
{
private:
    int payload;    //holds node value
    Node* nextNode; //points to the next node in the list
                    //like int* holds memory address of some int, Node* holds address of some Node object
    
public:
Node(int payload);  //Constructor
int getPayload();   //(method)payload is a private field so we need some way to get it
Node* getNextNode();    //(method)nextNode is also private so we need some way to get it
void setNextNode(Node* n);  //takes in a new nextNode to change the current one

};
#endif /* Node_hpp */