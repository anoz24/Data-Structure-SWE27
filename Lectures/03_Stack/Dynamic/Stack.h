#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


#include <stdio.h>
#include <iostream>
using namespace std;

typedef int StackElement;

class Stack
{
public:
    /***** Function Members *****/
    /***** Constructors *****/
    Stack(int numElements = 128);
    /*------------------------------------------------------------------------
     Construct a Stack object.

     Precondition:  None.
     Postcondition: An empty Stack object has been constructed (myTop is
     initialized to -1 and myArray is an array with numElements
     (default 128) elements of type StackElement).
     ------------------------------------------------------------------------*/

    Stack(const Stack & original);
    /*------------------------------------------------------------------------
     Copy Constructor
     Precondition:  original is the stack to be copied and is received as
     a const reference parameter.
     Postcondition: A copy of original has been constructed.
     ------------------------------------------------------------------------*/

    /***** Destructor *****/
    ~Stack();
    /*-----------------------------------------------------------------------
     Class destructor

     Precondition:  None
     Postcondition: The dynamic array in the stack has been deallocated.
     ------------------------------------------------------------------------*/

    /***** Assignment *****/
    const Stack & operator= (const Stack & rightHandSide);
    /*------------------------------------------------------------------------
     Assignment Operator
     Precondition:  rightHandSide is the stack to be assigned and is
     received as a const reference parameter.
     Postcondition: The current stack becomes a copy of rightHandSide
     and a const reference to it is returned.
     ------------------------------------------------------------------------*/

    bool empty() const;
    /*------------------------------------------------------------------------
     Check if stack is empty.
     Precondition: None
     Postcondition: Returns true if stack is empty and false otherwise.
     -----------------------------------------------------------------------*/

    void push(const StackElement & value);
    /*------------------------------------------------------------------------
     Add a value to a stack.

     Precondition:  value is to be added to this stack
     Postcondition: value is added at top of stack provided there is space;
     otherwise, a stack-full message is displayed and execution is
     terminated.
     -----------------------------------------------------------------------*/

    void display() const;
    /*------------------------------------------------------------------------
     Display values stored in the stack.

     Precondition:  ostream out is open.
     Postcondition: Stack's contents, from top down, have been output to out.
     -----------------------------------------------------------------------*/

    StackElement top() const;
    /*------------------------------------------------------------------------
     Retrieve value at top of stack (if any).

     Precondition:  Stack is nonempty
     Postcondition: Value at top of stack is returned, unless the stack is
     empty; in that case, an error message is displayed and a "garbage
     value" is returned.
     -----------------------------------------------------------------------*/

    void pop();
    /*------------------------------------------------------------------------
     Remove value at top of stack (if any).

     Precondition:  Stack is nonempty.
     Postcondition: Value at top of stack has been removed, unless the stack
     is empty; in that case, an error message is displayed and
     execution allowed to proceed.
     -----------------------------------------------------------------------*/
    // Friend function declaration (must be outside the class)
    friend ostream& operator<<(ostream& out, const Stack& stack);

private:
    /***** Data Members *****/
    int myCapacity,           // capacity of stack
    myTop;                // top of stack
    StackElement * myArray;   // dynamic array to store elements

}; // end of class declaration


#endif // STACK_H_INCLUDED
