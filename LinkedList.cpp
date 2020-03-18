#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()    //implement LinkedList constructor
{
    this->count = 0;    //set count to zero since we don't have any nodes yet
}

void LinkedList::addFront(int payload)  //implement addFront method
{
    Node* n = new Node(payload);    //new node object(Node n = new Node(payload) in Java),n points to the new node    
    
    //list currently has nothing in it
    if(!this->head) //if head currently points nowhere(count is zero)
    {
        this->head = n; //set head to the new node's address
    }
    else//list has something in it(count is not zero)
    {
        n->setNextNode(this->head); //n.setNextNode(address in head), this way we won't lose te way to that node
        this->head = n; //set head to hold new node's mem. address
    }
    this->count++;
}

int LinkedList::getFront()
{
    return this->head->getPayload(); 
}

int LinkedList::removeFront()
{
    Node* nodeToReturn = this->head;    //locate the node at the front of the list
    this->head = this->head->getNextNode(); //set head to the front's nextNode
    int val = nodeToReturn->getPayload(); //save the payload of the first node
    delete nodeToReturn;    //free up the memory space we were using
    this->count--;
    return val; //output the payload value we saved
}

Node* LinkedList::findEnd()
{
    Node* currNode = this->head;
    for(int i = 1; i < this->count; i++)
    {
        currNode = currNode->getNextNode();
    }
    return currNode;
}

void LinkedList::addEnd(int payload)   //add node to the end of the list
{
    
    if(!this->head)
    {
        this->addFront(payload);
    }
    else
    {
    Node* n = new Node(payload);
    Node* currNode = this->findEnd();
    currNode->setNextNode(n);
    }
    this->count++;
}

int LinkedList::getEnd()
{
    Node* currNode = this->findEnd();
    return currNode->getPayload();
}

int LinkedList::removeEnd()
{
    Node* nodeToReturn = this->findEnd();
    int val = nodeToReturn->getPayload();
    delete nodeToReturn;
    this->count--;
    return val;
}

int LinkedList::getIndex(int index)
{
    Node* currNode = this->head;
    for(int i = 0; i < index; i++)
    {
        currNode = currNode->getNextNode();
    }
    return currNode->getPayload();
}

void LinkedList::addAtIndex(int index, int payload)
{
    if(index == 0)
    {
        this->addFront(payload);
    }
    else
    {
        if(index>= this->count)
        {
            this->addEnd(payload);
        }
        else
        {
        Node* currNode = this->head;
        for(int i = 0; i < (index-1); i++)
        {
            currNode = currNode->getNextNode();
        }
        Node* n = new Node(payload);
        this->count++;
        n->setNextNode(currNode->getNextNode());
        currNode->setNextNode(n);
        }

    }
}

int LinkedList::removeAtIndex(int index)
{
    if(index==0)
    {
        this->removeFront();
    }
    else
    {
        if(index >= this->count - 1)
        {
            this->removeEnd();
        }
        else
        {
            Node* nodeBefore = this->head;
            Node* nodeToRemove = nodeBefore->getNextNode();
            for(int i = 1; i < index; i++)
            {
                nodeBefore = nodeBefore->getNextNode();
                nodeToRemove = nodeBefore->getNextNode();
            }
            nodeBefore->setNextNode(nodeToRemove->getNextNode());
            nodeToRemove->setNextNode(0);
            int val = nodeToRemove->getPayload();
            delete nodeToRemove;
            this->count--;
            return val;
        }
    }
}
    
void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode->getPayload() << "\n";
        currNode = currNode->getNextNode();
    }
    std::cout<< "Count = " << this->count <<"\n";

}