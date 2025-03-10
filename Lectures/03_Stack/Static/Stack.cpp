
#include "Stack.h"

Stack::Stack():myTop(-1)
{
}

bool Stack::empty() const
{
    return myTop == -1;
}

void Stack::push(const StackElement& value)
{

    if (myTop >= STACK_CAPACITY - 1)
    {
        cerr << "Stack-full! " << endl;
        exit(1);
    }
    ++myTop;
    myArray[myTop] = value;
}

void Stack::display() const
{
    if (empty())
    {
        cout << "Stack-empty! " << endl;
        return;

    }
    for (int i = myTop; i >= 0; i--)
    {
        cout << myArray[i] << endl;
    }
}



StackElement Stack::pop()
{
    StackElement temp;
    if(!empty())
    {
        temp=myArray[myTop];
        myTop--;
        return temp;
    }
    else
    {
        cout << "Stack Empty!" << endl;
        return 0;
    }
}

StackElement Stack::top() const
{

    if (!empty())
        return myArray[myTop];
    else
    {
        cout << "Stack Empty -- Returning garbage " << endl;
        return myArray[STACK_CAPACITY - 1];
    }
}
