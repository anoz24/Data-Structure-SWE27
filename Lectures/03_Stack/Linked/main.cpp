#include <iostream>

using namespace std;


#include <iostream>
using namespace std;

#include "stack.h"


int main(){
    Stack s;
    cout << "Stack created.  Empty? " << boolalpha << s.empty() << endl;

    cout << "How many elements to add to the stack? ";
    int numItems;
    cin >> numItems;
    for (int i = 1; i <= numItems; i++)
        s.push(100*i);
    cout << "Stack empty? " << s.empty() << endl;

    cout << "Contents of stack s (via  print):\n";
    cout<<s<< endl;
    cout << "Check that the stack wasn't modified by print:\n";
    cout<<s<< endl;

    Stack t, u;
    t = u = s;
    cout << "Contents of stacks t and u after t = u = s (via  print):\n";
    cout << "u:\n"<<u<< endl;
    cout << "t:\n"<<t<< endl;
    cout << "Top value in t: " << t.top() << endl;

    while (!t.empty())
    {
        cout << "Popping t:  " << t.top() << endl;
        t.pop();
    }
    cout << "Stack t empty? " << t.empty() << endl;
    cout << "Top value in t: " << t.top() << endl;
    cout << "Trying to pop t: " << endl;
    t.pop();
    return 0;
}
