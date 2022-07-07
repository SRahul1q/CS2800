#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Book
{
  public:
  string title;
  string author;
  int year;
  int price;
  Book*left;
  Book*right;
};

class Bookshelf
{
   public:
   void addbook(Book B);
   void removebook(int n);
   void list();
   void findcheap();
   void reverseUnqiue();
   bool checkEmpty(Book *point)
   {
     if (point == nullptr)
     {
       return true;
     }
     else 
     return false;
   }
};

class HorizontalBookshelf:public Bookshelf
{
  public: 
  Book *front;
  Book *back;
   HorizontalBookshelf()
   {
     front = NULL;
     back = NULL;
   }
    void addbook(Book B)
    {
     Book* temp = new Book;
      temp->title=B.title;
      temp->author=B.author;
      temp->price=B.price;
      temp->year=B.year;
     if(front != NULL)
     {
      back->right = temp;
      back = temp;
     }
     else
     {
      front=temp;
      back=temp;
    }
     return;
    }
    void removebook(int a)
    {
      while (a--)
      {
        if(front == NULL){
        cout<<"e"<<endl;
        }
      else{
        Book * temp=front;
        front=front->right;
        temp->right = NULL;
        delete (temp);
      }
    }
    }
    void list()
    {
    if(front == NULL)
    {
      cout<<"e"<<endl;
    }
    else
    {
    Book*ptr=front;
    while(ptr!=nullptr)
    {
    cout<<ptr->title<<","<<ptr->author<<","<<ptr->year<<","<<ptr->price<<endl;
    ptr=ptr->right;
    }
    }
    }  
     void findcheap()
    {
        if(front == NULL)
        {
            cout<<"e"<<endl;
            return;
        }
        int count=INT_MAX;
        Book *ans=front;
        while(ans)
        {
            if(ans->right==NULL)
            {
                if(ans->price<=count)
                {
                    cout<<"-1"<<endl;
                    count=ans->price;
                }
                else
                {
                    cout<<count<<endl;
                }
            }
            else
            {
                if(ans->price<=count)
                {
                    cout<<"-1,";
                    count=ans->price;
                }
                else
                {
                    cout<<count<<",";
                }
            }
            ans=ans->right;
        }
    }
    void reverseUnique()
    {
     Book *current=front;
     Book *prev=NULL;
     Book *right=NULL;
     Book *word0=front;
     Book *word1;
     while(word0 && word0->right!=NULL)
     {
       word1=word0;
       while(word1->right!=NULL)
       {
         if(word1->right->title == word0->title && word1->right->author == word0->author && word1->right != word0)
         {
          Book *rev=word1->right;
          word1->right=word1->right->right;
          rev->right=NULL;
          delete rev;
         }
         else {word1=word1->right;}
    }
       word0=word0->right;
     }
    
     
     while(current != NULL)
     {
       right=current->right;
       current->right=prev;
       prev=current;
       current=right;
     }
     front=prev;
    }
};

class VerticalBookshelf:public Bookshelf
{
  public: 
    Book *root;
    VerticalBookshelf()
  {
    root=NULL;
  }

    void addbook(Book B)
    {
      Book*fresh=new Book;
      fresh->title=B.title;
      fresh->author=B.author;
      fresh->price=B.price;
      fresh->year=B.year;
      if (root != nullptr) 
      {
       fresh->left=root;
       root=fresh;
      }
      else
       root=fresh;
      }
    void removebook(int b)
    {
      while(b--)
      {
        if(root == NULL)
        {
          cout<<"e"<<endl;
        }
        else{
        Book *val1=root;
        root=root->left;
        val1->left=NULL;
        delete val1;
        }
      }
    }
    void list()
    {
    if(root == NULL)
    {
    cout<<"e"<<endl;
    }
    else
    {
    Book*ptr=root;
    while(ptr!=nullptr)
    {
    cout<<ptr->title<<","<<ptr->author<<","<<ptr->year<<","<<ptr->price<<endl;
    ptr=ptr->left;
    }
    }
    }
        void findcheap()
    {
        if(root == NULL)
        {
            cout<<"e"<<endl;
            return;
        }
        int count1=INT_MAX;
        Book *number=root;
        while(number)
        {
            if(number->left==NULL)
            {
                if(number->price<=count1)
                {
                    cout<<"-1"<<endl;
                    count1=number->price;
                }
                else
                {
                    cout<<count1<<endl;
                }
            }
            else
            {
                if(number->price<=count1)
                {
                    cout<<"-1,";
                    count1=number->price;
                }
                else
                {
                    cout<<count1<<",";
                }
            }
            number=number->left;
        }
    }
    void reverseUnique()
    {
     Book *word0=root;
     Book *word1;
     while(word0 && word0->left!=NULL)
     {
       word1=word0;
       while(word1->left!=NULL)
       {
         if(word1->left->title == word0->title && word1->left->author == word0->author && word1->left != word0)
         {
          Book *rev=word1->left;
          word1->left=word1->left->left;
          rev->left=NULL;
          delete rev;
         }
         else {word1=word1->left;}
    }
       word0=word0->left;
     }
     VerticalBookshelf vs;
     word0=root;
     while(word0)
     {
       Book r;
       r.title=word0->title;
       r.year=word0->year;
       r.author=word0->author;
       r.price=word0->price;
       vs.addbook(r);
       word0=word0->left;
       removebook(1);
     }
     root=vs.root;

    }
};
int main()
{
  int Q; 
  cin>>Q;
  VerticalBookshelf v;
  HorizontalBookshelf h;
  
  while(Q != 0)
  {
     string input;
     cin>>input; 
     char a;
     if(input=="ADD")
     {
        cin>>a;
        if(a =='v')
        {
          Book B;
          cin>>B.title;
          cin>>B.author;
          cin>>B.year;
          cin>>B.price;
          v.addbook(B);
        }
        else if(a=='h')
        {
          Book B;
          cin>>B.title;
          cin>>B.author;
          cin>>B.year;
          cin>>B.price;
          h.addbook(B);
        }

     }
     else if(input=="REMOVE")
     {
         int n; 
         cin>>n; 
         cin>>a;
         if(a=='v')
         {
           v.removebook(n);
           }
         else if(a=='h')
         {
           h.removebook(n);
           }
     }
     else if(input=="LIST")
     {
        cin>>a;
        if(a=='v')
        {
          v.list();
          }
        else if(a=='h')
        {
          h.list();
          }
     }
     else if(input=="FINDC")
     {
       cin>>a;
        if(a=='v'){
          v.findcheap();
          }
        else if(a=='h'){
          h.findcheap();
          }
     }
     else if(input=="REVUNI")
     {
       cin>>a;
       if(a=='v'){
         v.reverseUnique();
         }
       else if(a=='h'){
         h.reverseUnique();
         }
     }
     Q--;
  }
}
