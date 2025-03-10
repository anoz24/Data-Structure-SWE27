#include "Linkedlist.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "*** Creating the Linked List list1\n";
    Linkedlist list1;

    cout << "*** Filling the Linked List list1 with five values 9, 17, 22, 26, 34\n";
    list1.insert(9, 0); list1.insert(17, 1); list1.insert(22, 2);
    list1.insert(26, 3); list1.insert(34, 4);

    cout << "*** Print the Linked List list1 using the print - Display Functions\n";
    cout<<list1<<endl;

    cout << "\n*** Assigning list1 to list2 ->  List list2 = list1;\n";
    List list2 = list1;

    cout << "\n*** Printing list2;\n";
    cout<<list2<<endl;

    cout << "*** Insert new node after the second node the Linked List list1\n";
    list1.insert(20, 2);

    cout << "*** Display the Linked List list1 after inserting 20 after the second node\n";
    cout<<list1<<endl;

    cout << "\n*** Creating empty list3 uding copy constructor from list1 to list3\n";
    List list3(list1);

    cout << "\n*** Printing list3\n";
    cout<<list3<<endl;


    cout << "*** Delete the third node (22) of the Linked List list1\n";
    list1.erase(3);

    cout << "*** Display the Linked List list1 after deleting 22\n";
    cout<<list1<<endl;



//    cout << "\n*** Use Assignment opeerator to generate list4:  List list4 = list2;\n";
//    List list4 = list2;
//
//    cout << "\n*** Print list4 after being assigned to list2\n";
//    print(list4);
//
//    cout << "\n*** Use nodeCount function to print the node count of list4\n";
//    cout << list4.nodeCount() <<endl;
//
//
//    cout << "\n*** Use reverse function to reverse the list4\n";
//    list4.reverse();
//
//    cout << "\n*** Print list4 after reversing\n";
//    print(list4);



    return 0;
}
