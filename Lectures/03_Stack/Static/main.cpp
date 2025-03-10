#include <iostream>
#include "Stack.h"

using namespace std;

int mainM()
{
    Stack s;
    cout << "Stack created.  Empty? " << boolalpha << s.empty() << endl;

    cout << "How many elements to add to the stack? ";
    int numItems;
    cin >> numItems;
    for (int i = 1; i <= numItems; i++)
        s.push(100*i);
    cout << "Stack empty? " << s.empty() << endl;

    cout << "Contents of stack s (via  print):\n";
    s.display();
    Stack t, u;
    t = u = s;
    cout << "Contents of stacks t and u after t = u = s (via  print):\n";
    u.display();
    t.display();
    cout << "Top value in t: " << t.top() << endl;

    while (!t.empty())
    {
        cout << "Popping t:  " << t.top() << endl;
        t.pop();
    }
    cout << "Stack t empty? " << t.empty() << endl;
    cout << "\nNow try to retrieve top value from t." << endl;
    cout << "Top value in t: " << t.top() << endl;
    cout << "\nTrying to pop t: " << endl;
    t.pop();
    return 0;
}
