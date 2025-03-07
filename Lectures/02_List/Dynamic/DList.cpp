/*-- List.cpp-----------------------------------------------------------
This file implements List member functions.
-------------------------------------------------------------------------*/
#include <cassert>
#include <new>
using namespace std;
#include "DList.h"

//--- Definition of class constructor
List ::List(int maxSize)
    : mySize(0), myCapacity(maxSize)
{
    myArray = new (nothrow) ElementType[maxSize];
    assert(myArray != 0);
}

//--- Definition of class destructor
List::~List()
{
    delete[] myArray;
}

//--- Definition of copy constructor
List::List(const List &origList)
    : mySize(origList.mySize), myCapacity(origList.myCapacity)
{
    //--- Get new array for copy
    myArray = new (nothrow) ElementType[myCapacity];

    if (myArray != 0) // check if memory allocation succeeded
    {
        //--- Copy the array
        for (int i = 0; i < mySize; i++)
            myArray[i] = origList.myArray[i];
    }
    else
    {
        cerr << "Memory allocation failure\n";
        exit(1);
    }
}

//--- Definition of assignment operator
const List &List::operator=(const List &rightHandSide)
{
    if (this != &rightHandSide) // check that not self-assignment
    {
        //-- Allocate a new array if necessary
        delete[] myArray;
        myCapacity = rightHandSide.myCapacity;
        myArray = new (nothrow) ElementType[myCapacity];

        if (myArray == 0) // Check if memory allocation succeeded
        {
            cerr << "Memory allocation failure\n";
            exit(1);
        }
    }
    //--- Copy rightHandSide's list elements into this new array
    mySize = rightHandSide.mySize;
    for (int i = 0; i < mySize; i++)
    {
        myArray[i] = rightHandSide.myArray[i];
    }
    return *this;
}

//--- Definition of empty()
bool List::empty() const
{
    return mySize == 0;
}

//--- Definition of display()
void List::display(ostream &out) const
{
    for (int i = 0; i < mySize; i++)
        cout << myArray[i] << " ";
}

//--- Definition of output operator
ostream &operator<<(ostream &out, const List &aList)
{
    aList.display(out);
    return out;
}

//--- Definition of insert()
void List::insert(ElementType item, int pos)
{
    if (mySize == myCapacity)
    {
        cerr << "No space for list element-- terminating execution\n";
        exit(1);
    }
    if (pos < 0 || pos > mySize)
    {
        cerr << "Illegal location to insert-- " << pos
             << ". List unchanged.\n";
        return;
    }
    // First shift array elements right to make room for item
    for (int i = mySize - 1; i > pos; i--)
    {
        myArray[i] = myArray[i - 1];
    }
    myArray[pos] = item;
    mySize++;
}

//--- Definition of erase()
void List::erase(int pos)
{
    if (mySize == 0)
    {
        cerr << "*** List is empty ***\n";
        return;
    }
    if (pos < 0 || pos >= mySize)
    {
        cerr << "Illegal location to erase-- " << pos
             << ". List unchanged.\n";
        return;
    }
    // Shift array elements left to close the gap
    for (int i = pos; i < mySize - 1; i++)
    {
        myArray[i] = myArray[i + 1];
    }
    // Decrease list size
    mySize--;
}
