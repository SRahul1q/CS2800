#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<class R>
class Node
{
    public:
    R data; 
    Node*front=NULL;
     Node(R d)
     {
      data = d;
      front = NULL;
     }
};

template<class R>
class Queue
{ 
   public:
    Node<R>*right; Node<R>*left;
    Queue()
    {
    right=nullptr;
    left=nullptr;
    }
    void enqueue(R val)
    {
     Node<R>*temp= new Node<R>(val);
     if(left == NULL)
     {
       right=left=temp;
       return;
     }else
     left->front = temp;
     left = temp;
    }

    Node<R>*dequeue()
    {
      Node<R>*temp = NULL;
     //if(isEmpty())
     //return NULL;
       if(right == left)
      {
       temp = right;
       right = NULL;
       left = NULL;
       return temp;
      }
      else 
      {
        temp = right;
        right = right->front;
        return temp;
      }
     
    }

    int size()
    {
      int count = 0;
      Node<R>*temp = right;
      while (temp != NULL)
      {
        count++;
        temp = temp->front;
      }
      return count;
    }
    
    bool isEmpty()
    {
      if(size()==0)
      return true;
      else
      return false;
    }
};


template<class R>
class Printer
{
  private:
  Queue<R>Q;
  public:
  class InsufficientInk
  {
    public:
    InsufficientInk(string one)
    {
      cout<<one<<endl;
    }
  };
  class NoDocument
  {
    public: 
    NoDocument(string two)
    {
      cout<<two<<endl;
    }
  };
  class PrinterBusy
  {
    public:
    PrinterBusy(string three)
    {
      cout<<three<<endl;
    }
  };
  int a=0; int b=0;
  Printer(int capacity,int ink)
  {
   a=capacity;
   b=ink;
  }
  void addDocument(R val)
  {
    if(Q.size() == a)
    {
      throw PrinterBusy("PRINTER_BUSY");
    }
    Q.enqueue(val);
  }
  R printDocument()
  {
    if(Q.isEmpty() == true)
    {
      throw NoDocument("NO_DOCUMENT");
    }
    else if(b==0)
    {
      throw InsufficientInk("INSUFFICIENT_INK");
    }
    b--;
    return Q.dequeue()->data;
  }
  void fillink(int newink)
  {
    b = newink;
  }
  

};

int main()
{
  int M,N; char T;
  cin>>M>>N>>T;
  int Q; cin>>Q;
  if(T=='I')
  {
  Printer<int>P(M,N);
  while(Q!=0)
  {
    try
    {
     int op; cin>>op;
     if(op==1)
     {
       int temp; cin>>temp;
       P.addDocument(temp);
     }
     else if(op==2)
     {
       cout<<P.printDocument()<<endl;
     }
     else if(op==3)
     {
       int newink; cin>>newink;
       P.fillink(newink);
     }
    }
    catch(Printer<int>::PrinterBusy){}
    catch(Printer<int>::NoDocument){}
    catch(Printer<int>::InsufficientInk){}
    Q--;
  }
  }
  else if(T=='C')
  {
    Printer<char>P(M,N);
  while(Q!=0)
  {
    try
    {
     int op; cin>>op;
     if(op==1)
     {
       char temp; cin>>temp;
       P.addDocument(temp);
     }
     else if(op==2)
     {
       cout<<P.printDocument()<<endl;
     }
     else if(op==3)
     {
       int newink; cin>>newink;
       P.fillink(newink);
     }
    }
    catch(Printer<char>::PrinterBusy){}
    catch(Printer<char>::NoDocument){}
    catch(Printer<char>::InsufficientInk){}
    Q--;
  }
  }
  else if(T=='F')
  {
   Printer<float>P(M,N);
  while(Q!=0)
  {
    try
    {
     int op; cin>>op;
     if(op==1)
     {
       float temp; cin>>temp;
       P.addDocument(temp);
     }
     else if(op==2)
     {
       cout<<P.printDocument()<<endl;
     }
     else if(op==3)
     {
       int newink; cin>>newink;
       P.fillink(newink);
     }
    }
    catch(Printer<float>::PrinterBusy){}
    catch(Printer<float>::NoDocument){}
    catch(Printer<float>::InsufficientInk){}
    Q--;
  }
  }
}
