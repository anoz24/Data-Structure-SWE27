#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef int ListEntry;

class List
{
    int size;
    int capacity;
    ListEntry * array;
    public:
        List(int c);
        ~List();
        void Insert(ListEntry e, int pos);
        ListEntry Retrieve(int pos);
        bool Empty();
        bool Full();
        int Size();
        void Display();
        //----------------------------
        ListEntry RetrieveCopy(int pos);
        void ReverseList();

};



#endif // LIST_H_INCLUDED
