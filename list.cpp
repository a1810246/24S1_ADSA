#include<iostream>
using namespace std;
template <class type>
class LinkedList{
public:
    LinkedList();
    LinkedList(type a[], int n);
    ~LinkedList();
    int Length();
    type Get(int i);
    int Locate(int i);
    void Insert(int i, type x);
    type Delete(int i);
    void PrintList();

private:
    Node<type> *first;
};

template<class type>
void LinkedList<type>::PrintList()
{
    p = first -> next;
    while(p != NULL)
    {
        cout<< p->data;
        p = p->next;
    }
}

template<class type>
int LinkedList<type>::Length()
{
    p = first->next;
    count = 0;
    while(p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
} 

template<class type>
type LinkedList<type>::Get(int i)
{
    p=first ->next;
    count = 1;
    while(p!=NULL && count<i)
    {
        p=p->next;
        count++;
    }
    if(p!=NULL)
    {
        return p->data;
    }
}

template<class type>
int LinkedList<type>::Locate(int i)
{
    count = 1;
    p = first->next;
    while(p->!= NULL)
    {
        if(p->data == i)
        {
            return count;
        }
        p=p->next;
        count++;
    }
}

template<class type>
void LinkedList<type>::Insert(int i, type x)
{
    p=first;
    count = 0;

    while(p!=NULL && count<i-1)
    {
        p = p->next;
        count++;
    }
    if(p!=NULL)
    {
        s = new Node<type>;
        s->data = x;
        s->next = p->next;
        p->next = s
    }
}

