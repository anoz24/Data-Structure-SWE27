#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

const int STACK_CAPACITY = 128;
typedef int StackElement;

class Stack
{
public:
    /***** Function Members *****/
    /***** Constructor *****/
    Stack();
    /*------------------------------------------------------------------------
      Construct a Stack object.

      Precondition:  None.
      Postcondition: An empty Stack object has been constructed (myTop is
          initialized to -1 and myArray is an array with STACK_CAPACITY
          elements of type StackElement).
     -----------------------------------------------------------------------*/

    bool empty() const;
    /*------------------------------------------------------------------------
      Check if stack is empty.
      Precondition: None
      Postcondition: Returns true if stack is empty and false otherwise.
     -----------------------------------------------------------------------*/

    void push(const StackElement& value);
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

    StackElement pop();
    /*------------------------------------------------------------------------
      Remove value at top of stack (if any).

      Precondition:  Stack is nonempty.
      Postcondition: Value at top of stack has been removed, unless the stack
          is empty; in that case, an error message is displayed and
          execution allowed to proceed.
     -----------------------------------------------------------------------*/

private:
    /***** Data Members *****/
    StackElement myArray[STACK_CAPACITY];
    int myTop;// **Why not stack element instead of int?**/ it is like an indication for
    //how many elements are there in the stack
}; // end of class declaration




#endif // STACK_H_INCLUDED
