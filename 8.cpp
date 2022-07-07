#include <bits/stdc++.h>
using namespace std;
template<class T>
class Node
{
    public:
    T key;
    T value;
    Node<T>* next;
    Node<T>* back;
    Node<T>* bel;
    Node<T>* abo;

};

bool bit()
{
    if(rand()%2==0){return true;}
    else return false;
}

template<class T>
class Skiplist
{
private:
Node<T>* tail;
Node<T>* head;
void Empty(T l,T h)
{
  Node<T>* newhead = new Node<T>();
  Node<T>* newtail = new Node<T>();
  newhead->key = l;
  newtail->key = h;
  newhead->next = newtail;
  newtail->back = newhead;
  head->abo = newhead;
  tail->abo = newtail;
  newhead->bel = head;
  newtail->bel = tail;
  head = newhead;
  tail = newtail;
}
public :
int n = 0,height = 0;
void Set(T low,T high)
{
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    tail->back = head;
    head->key = low;
    tail->key = high;
} 
void insert(T k,T v,T l,T h)
{
    int level = -1;
    Node<T>* a = search(k);
    Node<T>* b = NULL;
    Node<T>* c = new Node<T>();
    if(a->key == k)
    return;
    n++;
    c->key = k;
    c->value = v;
    c->next = a->next;
    c->back = a;
    c->abo = NULL;
    c->bel = NULL;
    a->next->back = c;
    a->next = c;
    a = c->back;
    b = c->next;
    while(height <= 10 && bit())
    {
        level++;
        if(height > level)
       {
            Node<T>* newnode =  new Node<T>();
            newnode->key = k;
            newnode->value = v;
            while(a->abo == NULL && a->back != NULL)
            a = a->back;
             while(b->abo == NULL && b->back != NULL) 
             b = b->next;      
             a = a->abo;
             b = b->abo;
             c->abo = newnode;
             newnode->next = a->next;
             newnode->back = a;
             newnode->bel = c;
             a->next->back = newnode;
             a->next = newnode;
             c = newnode;
             }
             else if(height <= level && height < 10)
             {
                     Empty(l,h);
                     a = head;
                     b = tail;
                     Node<T>* newnode = new Node<T>();
                     newnode->key = k;
                     newnode->value = v;
                     c->abo = newnode;
                     newnode->bel = c;
                     newnode->next = a->next;
                     newnode->back = a;
                     a->next->back = newnode;
                     a->next = newnode;
                     c = newnode;
                     height++;
                 }
                 else break;
             }
    }
    void delet(T k)
    {
        Node<T>* current = search(k);
        if(k != current->key)
        return;
        n--;
        while(current != NULL)
        {
            current->back->next = current->next;
            current->next->back = current->back;
            current = current->abo;
        }
    }
    Node<T>* search(T k)
    {
        Node<T>* current = head;
        while(current->bel != NULL)
        current = current->bel;
        while(current->next->key <= k)
        current=current->next;
        return current;
    }
    int keyc()
    {
        return n;
    }
};

template<class T>
class Dictionary
{
    public:
    Skiplist<T> S;
    Dictionary(T l,T h)
    {
        S.Set(l,h);
    }
    void empty()
    {
        if(S.keyc() == 0)
        cout<<"True"<<endl;
        else
        cout<<"False"<<endl;
    }
    void insertD(T k,T v,T l,T h)
    {
        S.insert(k,v,l,h);
    }
    void deleteD(T k)
    {
        S.delet(k);
    }
    void find(T k)
    {
        Node<T>* seen = S.search(k);
        if(seen->key == k)
        {
            cout<<seen->value<<endl;
            return;
        }
        cout<<"NOT FOUND"<<endl;
    }
    void size()
    {
        cout<<S.keyc()<<endl;
    }
};

int main()
{
    string r; cin>>r;
    
    if(r=="INTEGERDICT")
    {
        int p; cin>>p;
      Dictionary<int>D(INT_MIN,INT_MAX);
      while(p--)
      {
        string s; cin>>s;
        if(s=="ISEMPTY")
        {
            D.empty();
        }
        else if(s=="INSERT")
        {
            int a,b; cin>>a>>b;
            D.insertD(a,b,INT_MIN,INT_MAX);
        }
        else if(s=="DELETE")
        {
            int k; cin>>k;
            D.deleteD(k);
        }
        else if(s=="SIZE")
        {
            D.size();
        }
        else if(s=="FIND")
        {
          int k; cin>>k;
           D.find(k); 
        }
      }
    }
    else if(r=="STRINGDICT")
    {
        int p; cin>>p;
     Dictionary<string>D("R","{");
      while(p--)
      {
        string s; cin>>s;
        if(s=="ISEMPTY")
        {
             D.empty();
        }
        else if(s=="INSERT")
        {
            string a,b; cin>>a>>b;
            D.insertD(a,b,"R","{");
        }
        else if(s=="DELETE")
        {
            string k; cin>>k;
            D.deleteD(k);
        }
        else if(s=="SIZE")
        {
            D.size();
        }
        else if(s=="FIND")
        {
          string s; cin>>s; 
          D.find(s); 
        }
      }
    }
    return 0;
}