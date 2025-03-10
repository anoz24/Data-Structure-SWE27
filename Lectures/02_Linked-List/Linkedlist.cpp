
#include "Linkedlist.h"
#include <iostream>
using namespace std;

//-- Definition of the class constructor
List::List()
: first(0), mySize(0)
{}
//List L1(L2)
//-- Definition of the copy constructor  List l1(l2);
List::List(const List & origList)
: first(0), mySize(origList.mySize){
    if (mySize == 0) return;
    List::NodePointer origPtr, lastPtr;
    first = new Node(origList.first->data);  // copy first node
    lastPtr = first;
    origPtr = origList.first->next;
    while (origPtr != 0){
        lastPtr->next = new Node(origPtr->data);
        origPtr = origPtr->next;
        lastPtr = lastPtr->next;
    }
}

//-- Definition of the destructor
 List::~List(){
    List::NodePointer prev = first,
    ptr;
    while (prev != 0){
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
    first=0;
    mySize=0;
}

// Definition of empty()
bool List::empty(){
    return mySize == 0;
}
//L1=L2
//-- Definition of the assignment operator l1=l2;
const List & List::operator=(const List & rightSide){
    mySize = rightSide.mySize;

    if (mySize == 0){
        this->~List();
        first = 0;
        return *this;
    }
    if (this != &rightSide){
        this->~List();
        List::NodePointer origPtr, lastPtr;
        first = new Node(rightSide.first->data);  // copy first node
        lastPtr = first;
        origPtr = rightSide.first->next;

        while (origPtr != 0){
            lastPtr->next = new Node(origPtr->data);
            origPtr = origPtr->next;
            lastPtr = lastPtr->next;
        }
    }
    return *this;
}

//-- Definition of insert()
void List::insert(ElementType dataVal, int index){
    if (index < 0 || index > this->mySize){
        cerr << "Illegal location to insert -- " << index << endl;
        return; }
    mySize++;
    List::NodePointer newPtr = new Node(dataVal),
    predPtr = first;
    if (index == 0){
        newPtr->next = first;
        first = newPtr;
    }
    else {
        for(int i = 1; i < index; i++)
            predPtr = predPtr->next;
        newPtr->next = predPtr->next;
        predPtr->next = newPtr;
    }
}

//-- Definition of erase()
void List::erase(int index){
    if (index < 0 || index >= mySize){
        cerr << "Illegal location to delete -- " << index << endl;
        return; }
    mySize--;
    List::NodePointer ptr,
    predPtr = first;
    if (index == 0){
        ptr = first;
        first = ptr->next;
        delete ptr;
    }
    else {
        for(int i = 1; i < index; i++)
            predPtr = predPtr->next;
        ptr = predPtr->next;
        predPtr->next = ptr->next;
        delete ptr;
    }
}

//-- Definition of search()
int List::search(ElementType dataVal){
    int loc=0;
    NodePointer tempP = first;
    //for (loc = 0; loc < mySize; loc++)
    for(Node * p=first; p!=0;p=p->next, loc++)
        if (tempP->data == dataVal)
            return loc;
        else
            tempP = tempP->next;
    return -1;
}

//-- Definition of display()
void List::display(ostream & out) const{
    List::NodePointer ptr = first;
    while (ptr != 0){
        cout << ptr->data << "  ";
        ptr = ptr->next;
    }
}

//-- Definition of the output operator
ostream & operator<<(ostream & out, const List & aList){
    aList.display(out);
    return out;
}

//-- Definition of nodeCount()
int List::nodeCount(){
    int count = 0;
    List::NodePointer ptr = first;
    while (ptr != 0){
        count++;
        ptr = ptr->next;
    }
    return count;
}   // or simply,  { return mySize; }

//-- Definition of reverse()
void List::reverse(){
    NodePointer prevP = 0,
    currentP = first,
    nextP;
    while (currentP != 0){
        nextP = currentP->next;
        currentP->next = prevP;
        prevP = currentP;
        currentP = nextP;
    }
    first = prevP;       // new head of (reversed) linked list
}

//-- Definition of ascendingOrder()
bool List::ascendingOrder(){
    if (mySize <= 1)
        //empty or one element list
        return true;
    //else
    NodePointer prevP = first,
    tempP = first->next;
    while (tempP != 0 && prevP->data <= tempP->data){
        prevP = tempP;
        tempP = tempP->next;
    }
    if (tempP != 0)
        return false;
    // else
    return true;
}
