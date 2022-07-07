#include<bits/stdc++.h>
using namespace std;

class Node
{
   public :
   int data;
   Node *next; 
};
Node *top;

 class Stack
{
    public:
    Stack()
    {
    top=nullptr;
    }
    void push(int data)
    {
     Node *val = new Node();
     val->data = data;
     val->next = top;
     top = val;
    }
    int pop()
    {
     Node *temp;
      if (top == NULL)
      {
        return -1;
      }
      else
      {
        temp = top;
        top = temp->next;
        return (temp->data);
      }
    }
    int Top()
    {
      if (isEmpty() == 0)
      {
        return top->data;
      }
      else
      {
        return -1;
      }
    }
    int isEmpty()
    {
      if (top == NULL)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }

};

class Graph
{
private :
bool** adj;
int n;
   public:
  Graph(int n) {
    this->n = n;
    adj = new bool*[n];
    for (int i = 0; i < n; i++) {
      adj[i] = new bool[n];
      for (int j = 0; j < n; j++)
        adj[i][j] = false;
    }
  }
    void operator +=(pair<int,int>p)
    {
      adj[p.first][p.second]=true;
      adj[p.second][p.first]=true;
    }
    void operator -=(pair<int,int>p)
    {
      adj[p.first][p.second]=false;
      adj[p.second][p.first]=false;
    }
void cmp(int n)
{
  for(int k = 1;k<=n;k++)
    {
      for(int i=1;i<=n;i++)
        for(int j=1;j<1;j++)
          adj[i][j] = adj[i][j] | (adj[i][k] && adj[k][j]);
    }
}
    int Reach(int u,int v)
    {
       if ( adj[u][v] == 1)
         return 1;
      else
         return 0;
    }


    void print()
    {
      for (int i = 0;i<n;i++)
        {
          for (int j = 0;j<n;j++)
            {
              cout<<adj[i][j]<<" ";
            }
          cout<<endl;
        }
    }
bool iscyclic(int v,bool visited[],int x)
{
  visited[v] = true;
  
  for(int i=0;i!=n;++i)
    {
      if(adj[v][i]==true)
      {
       if(!visited[i])
       {
        if(iscyclic(i,visited,v))
          return true;
       }
       else if(i!= x)
        return true;
      }
    }
      return false;   
}
int detectcycle()
{
  bool visited[n];
  for(int i=0;i<n;i++)
    visited[i] = false;
  for(int u = 0;u<n;u++)
    {
      if(!visited[u])
        if(iscyclic(u,visited,-1))
          return 1;
    }
  return 0;
}
friend ostream& operator<<(ostream&s,Graph g);
};

ostream& operator<<(ostream&s,Graph g)
{
  for(int i=0;i<g.n;i++)
    {
      for(int j=0;j<g.n;j++)
        {
          s<<g.adj[i][j]<<" ";
        }
      s<<endl;
    }
  return s;
}


int main()
{
  int x;
  cin>>x;
  Stack s;
  for(int i=0;i<x;i++)
    {
      string input;
      cin>>input;
      int a;
      if(input == "push")
      {
        cin>>a;
        s.push(a);
      }
      if(input == "pop")
      {
        cout<<s.pop()<<endl;
      }
            if(input == "empty")
      {
        cout<<s.isEmpty()<<endl;
      } 
      if(input == "top")
      {
        cout<<s.Top()<<endl;
      }

    }
  int y,n;
  cin>>n;
   Graph g(n);
  cin>>y;
  for (int j=0;j<y;j++)
    {
      string input1;
      cin>>input1;
      if(input1 == "add")
      {
        int a,b;
        cin>>a>>b;
        g+=std::pair<int,int>(a,b);
      }
      if (input1 == "cycle")
      {
        cout<<g.detectcycle()<<endl;
      }
       if (input1 == "del")
      {
        int a,b;
        cin>>a>>b;
        g-=std::pair<int,int>(a,b);
      }
      if(input1 == "reach")
      {
        int a,b;
        cin>>a>>b;
        cout<<g.Reach(a,b)<<endl;
      }
       if (input1 == "print")
      {
        cout<<g;
      }

    }
  
}