#include "LinkedList.hpp"
#include <iostream>

int main()
{
    LinkedList* ll = new LinkedList();
    ll->addFront(1);
    ll->addFront(2);
    ll->addFront(3);
    ll->addEnd(4);
    ll->display();

    std::cout<< "addAtIndex: (2,10)" << "\n";
    ll->addAtIndex(2, 10);
    ll->display();

    ll->removeAtIndex(0);
    ll->display();    
      
    delete ll;



}