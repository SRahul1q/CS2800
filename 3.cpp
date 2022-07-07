#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>class Node{
    public:
    T data;
    Node<T>* front = NULL;
    Node<T>* back = NULL;

};
template<class T>class Linkedlist
{
    private:
    Node<T>* head;
    public:
    Linkedlist()
    {
        this->head = NULL;
    }
    void insert_Front( T val);
    void insert_end(T val);
    int size();
    T pop_front();
    T pop_back();
};
template <class T> void Linkedlist<T>:: insert_Front(T val)
{
Node<T>* node = new Node<T>[1];
node->data = val;
if(head == NULL)
{
head = node;
return;
}
head->back = node;
node->front = head;
head = node;
}
template <class T> void Linkedlist<T>::insert_end(T val)
{
    Node<T> *newNode = new Node<T>;
    Node<T>*last = *head;
    newNode->data = val;
    newNode->front = NULL;
    if(*head == NULL)
    {
       newNode->back = NULL;
       *head=newNode;
       return;
    }
    while (last->front != NULL)
    last = last->front;
    last->front = newNode;
    newNode->back = last;
    return;
}

template <class T> int Linkedlist<T>::size()
{
    int num=0;
    Node<T> *value=head;
    while (value != NULL)
    {
        value=value->front;
        num++;
    }
    return num;
}

template <class T> T Linkedlist<T>::pop_front()
{
 if(head != NULL)
 {
  Node<T> *del=head;
  head=del->front;
  return (del->data);
 }
 else return 0;
}

template <class T> T Linkedlist<T>::pop_back()
{
    if(head != NULL)
    {
        if(head->front == NULL)
        {
            head = NULL;
        }
        else
        {
            Node<T>* del1;
            del1=head;
            while(del1->front->front != NULL)
            {
            del1 = del1->front;
            }
            Node<T>* lnode = del1->front;
            del1->front = NULL;
            return (lnode->data);

        }
    }
}



template <class T> class Stack
{
    public:
           void push(T k);
           void  pop();
           int sizestack();
           T topele();
           bool compare(T temp);
    private:
    Linkedlist<T> LL;

};

template <class T> void Stack<T>::push(T k)
{
 LL.insert_Front(k);
}

template <class T> void Stack<T>::pop()
{
    cout<<LL.pop_front();
}
template <class T> int Stack<T>::sizestack()
{
    return (LL.size());
}
template <class T>T Stack<T>::topele()
{
    T val=LL.pop_front();
    LL.insert_Front(val);
    return val;
}
template <class T> bool Stack<T>:: compare(T temp)
{
    T up=topele();
    if(temp>up) 
    {
        return true;
    }
    else
    {
      return false;
    } 
    
}

template<typename T>
void func(int N)
{
  T a[N];
  for(int i=0;i<N;i++){cin>>a[i];}
  Stack<T>r;
  for(int i=0;i<N;i++)
  {
    if(r.sizestack()==0)
    {r.push(a[i]);}
    else
    {
      if(r.compare(a[i])){r.push(a[i]);}
      else
      {
        while(r.sizestack()!=0 && r.compare(a[i])==false)
        {
          r.pop();
        }
        r.push(a[i]);
      }
    }
  }
  int stacksize=r.sizestack();
  while(stacksize--){r.pop();}
}





int main()
{
  int N; cin>>N;
  char T; cin>>T;
  if(T=='I')
  {
    func<int>(N);
  }
  else if(T=='C')
  {
    func<char>(N);
  }
  else if(T=='F')
  {
    func<float>(N);
  }
}
