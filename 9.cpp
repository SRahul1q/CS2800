#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class base
{
public:
 int n;
 int r;
 virtual int Knapsack(int a,int n,int val[],int wt[])=0;

};

class derived:
public base
{
public:
    int Knapsack(int a,int n,int val[],int wt[])
    {
       int i,j;
       int b[a+1];
       for(int k=0;k<a+1;k++){b[k]=0;}
       for(i = 0;i <= a;i++)
       {
           for(j = 0;j < n;j++)
           {
              if(wt[j] <= i)
               {
                 b[i] = max(b[i],b[i-wt[j]]+val[j]);
               }
           }
       }
      return b[a];
    } 
};

int main()
{
  base *bp = new derived();
    
  int a;
  cin>>a;
  int count;
  cin>>count;
  int arr[count];
  for(int i = 0;i < count;i++)
  {
      cin>>arr[i];
  }
  int arr1[count];
  for(int j = 0;j < count;j++)
  {
      cin>>arr1[j];
  }
  int n = sizeof(arr)/sizeof(arr[0]);
 cout<< bp->Knapsack(a,n,arr,arr1);
  return 0;
  }