/*-- List.cpp-----------------------------------------------------------
This file implements List member functions.
-------------------------------------------------------------------------*/
#include <cassert>
using namespace std;
#include "List.h"

//--- Definition of class constructor
List ::List()
    : mySize(0)
{
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
    if (mySize == CAPACITY)
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
