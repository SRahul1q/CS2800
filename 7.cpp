#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#include<set>
#include<string>
using namespace std;

class Dictionary
{
  private:
   map<int,set<string>>rahul;
  public:
  void buildDict(vector<string>letters)
  {
      for(int i=0;i<letters.size();i++)
      {
        string s = letters[i];
        rahul[s.size()].insert(s);
      } 
        
  }
  void addWordToDict(string word)
  {
   rahul[word.size()].insert(word);
  }
  bool search(string target)
  {
   auto it = rahul[target.size()].find(target);
   if (it != rahul[target.size()].end()) return true;
   else return false;
  }

  set<string>getWordsAfterReplace(string target)
  {
       set<string>dog; int count; 
       for(auto ptr = rahul[target.size()].begin();ptr != rahul[target.size()].end();ptr++)
       {
           count=0;
       for (int i=0;i<target.size();i++)
       {
        if(target[i]==(*ptr)[i])
        {
            count++;
        }
       }
       if(count>=target.size()-1)
       {
          dog.insert(*ptr);
        }
      }
      return dog;
  }
set<string> getWordsAfterSwap(string target) 
    {
        set<string>::iterator it;
        set<string> r;
        for(it=rahul[target.length()].begin();it!=rahul[target.length()].end();it++)
        {
            for(int i=0;i<target.length()-1;i++)
            {
                string str = target;
                char temp=str[i];
                str[i]=str[i+1];
                str[i+1]=temp;
                if(*it==str) r.insert(str);
            }
        }
        return r;
    }
  int maxChangeableWord()
  { 
    int max=0;
    for(auto r=rahul.begin();r!=rahul.end();r++)
    {
        set<string>l=r->second;
        for(auto p=l.begin();p!=l.end();p++)
        {
         int x=getWordsAfterReplace(*p).size();
         if(x>=max){max=x;} 
        }
    }
    return max-1;
  }
  int maxSwappableWord() 
  {
    int max=0;
    for(auto r=rahul.begin();r!=rahul.end();r++)
    {
        set<string>l=r->second;
        for(auto p=l.begin();p!=l.end();p++)
        {
         int x=getWordsAfterSwap(*p).size();
         if(x>=max){max=x;} 
        }
    }
    return max;
  }
};

int main()
{
  
  int words; cin>>words;
  vector<string>letters(words);
  for(int i=0;i<words;i++)
  {
    cin>>letters[i];
  }
  //cout<<"sai";
  Dictionary dec;
  dec.buildDict(letters);
  //cout<<"sai";
  int Q; cin>>Q;
  for(int j=0;j<Q;j++)
  {
      string word;
      int input;
      cin>>input;
      if(input == 1)
      {
        
          cin>>word;
          dec.addWordToDict(word);
      }
      else if(input == 2)
      {
          cin>>word;
          if(dec.search(word))cout<<"true"<<endl;
          else cout<<"false"<<endl;
      }
      else if( input == 3)
      {
          cin>>word;
          auto a = dec.getWordsAfterReplace(word);
          if(a.size()!=0)
          {
            for(auto i:a)
            {
                cout<<i<<" ";
            }
            cout<<endl;
          }
          else
          cout<<"-1"<<endl;
      }
      else if (input == 4)
      {
          cin>>word;
          auto b = dec.getWordsAfterSwap(word);
          if(b.size()!=0)
          {
            for(auto i:b)
            {
                cout<<i<<" ";
            }
            cout<<endl;
          }
          else
          cout<<"-1"<<endl;
      }
      else if(input == 5)
      {
          cout<<dec.maxChangeableWord()<<endl;
      }
      else if(input == 6)
      {
          cout<<dec.maxSwappableWord()<<endl;
      }

  }
  
}