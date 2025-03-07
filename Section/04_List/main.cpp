#include <iostream>
#include"List.h"
using namespace std;

int main()
{
    List L(5);
//    List * L = new List(5);
    L.Insert(1,0);
    L.Insert(2,0);
    L.Insert(3,0);
    L.Insert(4,0);
    L.Insert(5,0);

//    ListEntry e = L.Retrieve(2);

//    L.Insert(555,3);


//-----------------------------------------------------
//    ListEntry e = L.Retrieve(2);
//    L.Insert(e,2);
//    cout<<"at index 2 = "<<e<<endl;
    cout<<"at index 2 = "<<L.RetrieveCopy(2)<<endl;
//-----------------------------------------------------

//    int s = L.Size();
//    for(int i = 0 ; i < s-1 ; i ++)
//    {
//        e = L.Retrieve(s-1);
//        L.Insert(e,i);
//    }

//    L.ReverseList();

    L.Display();

    return 0;
}
