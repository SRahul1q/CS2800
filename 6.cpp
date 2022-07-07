#include<bits/stdc++.h>
using namespace std;

class node
{
  private:
  friend class trie;
  bool isEnd;
  vector<node*>next;
  public:
  node()
  {
    isEnd = false;
    next.resize(26,NULL);
  }
};

class trie
{
  public:
  trie()
  { 
    head = new node;
  }
  node*donode()
  {
    node *Newnode = new node;
    return Newnode;
  }
  void insert(string s)
  { 
    node *ptr = head; 
    for(int i=0;i<s.size();i++)
    {
       if (ptr->next[s[i]-'a']==NULL)
       { 
        ptr->next[s[i]-'a']= donode();
       }
       ptr = ptr->next[s[i]-'a'];
    }
    ptr->isEnd = true;
  }
  void search(string s)
  {
    node*ptr=head; 
    if(ptr->next[s[0]-'a']==NULL){cout<<s<<" ";}
    else
    {
      string r=""; int temp=0; string small;
      for(int i=0;i<s.size() && ptr->next[s[i]-'a']!=NULL;i++)
      {
        if(ptr->isEnd==true)
        {
          small=r;
          temp=1;
        }
        r=r+s[i]; 
        ptr=ptr->next[s[i]-'a'];
      }
      if(ptr->isEnd==true){cout<<r<<" ";}
      else
      {
        if(temp==1){cout<<small<<" ";}
        else{cout<<s<<" ";}
      }
    }
  }
  private:
   node*head;
};

int main()
{
    trie t;
    int a;
    cin>>a; 
    string s;
    for(int i=0;i<a;i++)
    {
        cin>>s;
        t.insert(s);
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        t.search(s);
    }
    cout<<endl;
}