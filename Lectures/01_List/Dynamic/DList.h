/*-- DList.h--------------------------------------------------------------
This header file defines the data type List for processing lists.
Basic operations are:
Constructor
Destructor
Copy constructor
Assignment operator
empty: Check if list is empty
insert: Insert an item
erase: Remove an item
display: Output the list
<<: Output operator
-------------------------------------------------------------------------*/
#include <iostream>
#ifndef DLIST
#define DLIST
typedef int ElementType;
class List
{
public:
    /******** Function Members ********/
    /***** Class constructor *****/
    List(int maxSize = 1024);
    /*---------------------------------------------------------------------
   Construct a List object
    Precondition:  maxSize is a positive integer with default value 1024.
    Postcondition: An empty List object is constructed; myCapacity
    maxSize (default value 1024); myArray points to a dynamic
    array with myCapacity as its capacity; and mySize is 0.
    -----------------------------------------------------------------------*/

    /***** Class destructor *****/
    ~List();
    /*---------------------------------------------------------------------
    Destroys a List object.
    Precondition: The life of a List object is over.
    Postcondition: The memory dynamically allocated by the constructor
    for the array pointed to by myArray has been returned to the heap.
    -----------------------------------------------------------------------*/

    /***** Copy constructor *****/
    List(const List &aList);
    /*---------------------------------------------------------------------
    Construct a List object by copying the elements of aList.
    Precondition:  A copy of origList is needed; origList is a const
 reference parameter.
    Postcondition: A copy of origList has been constructed.
    -----------------------------------------------------------------------*/

    /***** Assignment operator *****/
    const List &operator=(const List &rightHandSide);
    /*---------------------------------------------------------------------
    Assign aList to the current List object.
    Precondition: None
    Postcondition: A copy of rightHandSide has been assigned to this
    object. A const reference to this list is returned.
    -----------------------------------------------------------------------*/

    /***** empty operation *****/
    bool empty() const;
    /*---------------------------------------------------------------------
   Check if a list is empty.
    Precondition: None
    Postcondition: true is returned if the list is empty, false if not.
    -----------------------------------------------------------------------*/

    /***** insert and erase *****/
    void insert(ElementType item, int pos);
    /*---------------------------------------------------------------------
   Insert a value into the list at a given position.
    Precondition: item is the value to be inserted; there is room in
    the array (mySize < myCapacity); and the position satisfies
    o <= pos <= mySize.
    Postcondition: item has been inserted into the list at the position
    determined by pos (provided there is room and pos is a legal
    position).
    -----------------------------------------------------------------------*/

    void erase(int pos);
    /*---------------------------------------------------------------------
   Remove a value from the list at a given position.
    Precondition: The list is not empty and the position satisfies
    o <= pos < mySize.
    Postcondition: element at the position determined by pos has been
    removed (provided pos is a legal position).
    ----------------------------------------------------------------------*/

    /***** output *****/
    void display(ostream &out) const;
    /*---------------------------------------------------------------------
    Display a list
    Precondition: The ostream out is open.
    Postcondition: The list represented by this List object has been
    inserted into out.
    -----------------------------------------------------------------------*/
private:
    /******** Data Members ********/
    int mySize;           // current size of list
    int myCapacity;       // capacity of array
    ElementType *myArray; // pointer to dynamic array
}; //--- end of List class

//------ Prototype of output operator
ostream &operator<<(ostream &out, const List &aList);
#endif