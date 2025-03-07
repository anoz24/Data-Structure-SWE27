#include "List.h"
#include "iostream"

using namespace std;

List::List(int c)
{
    size = 0;
    capacity = c;
    array = new ListEntry[c];
}

List::~List()
{
    size = 0;
    delete [] array;
}
void List::Insert(ListEntry e, int pos)
{
    for(int i = size; i > pos ; i--)
        array[i] = array[i-1];
    array[pos] = e;
    size++;
}
ListEntry List::Retrieve(int pos)
{
    ListEntry e = array[pos];
    for(int i = pos; i < size-1 ; i++)
        array[i] = array[i+1];
    size --;
    return e;
}
bool List::Empty()
{
    return size == 0;
}

bool List::Full()
{
    return size == capacity;
}

int List::Size()
{
    return size;
}

void List::Display()
{
    for(int i = 0 ; i < size ; i ++)
        cout<<array[i]<<endl;
}

ListEntry List::RetrieveCopy(int pos)
{
    return array[pos];
}

void List::ReverseList()
{
    ListEntry e;
    for(int i = 0, j = size-1 ; i < j ; i++, j--)
    {
        e = array[i];
        array[i] = array[j];
        array[j] = e;
    }
}
