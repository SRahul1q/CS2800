#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Matrix{
   private:
    int rows;
    int columns;
    int mat[1000][1000];
  public:
    Matrix(int rows,int columns);
    Matrix(int rows, int columns, int matrix[1000][1000]);
    void setValue(int row,int col,int val);
    void solveSpiral(int start, int top, int bottom);
    int getValue(int row,int col);
    int getNoRows();
    int getNoColumns();
    void printSpiral();
    int trace();
    bool isSpecialMatrix();
    bool checkTriangular();
    
};
//If it is triangular, return true, else return false
bool Matrix::checkTriangular(){
   int a=0,b=0;
    if(rows!=columns)  return false;
    for (int i=0; i<rows;i++)
    {
      for (int j=0;j<columns;j++)
      {
        if(j>i && mat[i][j]!=0) 
         a=1;
        if(j<i && mat[i][j]!=0)  b=1;
        }
    }
     if(a==0 ||b==0)  
    return true;
    else  
    return false;
 }
//Prints the elements of this matrix in spiral order
void Matrix::solveSpiral(int start, int top, int bottom) 
{
      
        if(start>top || start>bottom) return;
        for(int i=start; i<=top; i++) 
        {
            cout << mat[start][i] << " ";
        }
        for(int i=start+1; i<=bottom; i++) 
        {
            cout << mat[i][top] << " ";
        }
        if(start!=bottom)
         {
            for(int i=top-1; i>=start; i--)
             {
                cout << mat[bottom][i] << " ";
            }
        }
        if(start!=top) {
            for(int i=bottom-1; i>start; i--)
             {
                cout <<mat[i][start] << " ";
            }
        }
        solveSpiral(start+1, top-1, bottom-1);
    }
//To store values
 Matrix::Matrix(int n,int m)
 {
    rows=n;
    columns=m;
 }
 //To take values in the matrices
 Matrix::Matrix(int n,int m,int arr[1000][1000])
 {
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++)
       {
           mat[i][j]=arr[i][j];
       } 
    }
 }

 void Matrix::setValue(int row,int col,int val)
 {
    mat[row][col]=val;
 }

 int Matrix::getValue(int row,int col)
 {
    int ans=mat[row][col];
    return ans;
 }
 
 int Matrix::getNoRows()
 {
     return rows;
 }

 int Matrix::getNoColumns()
 {
     return columns;
 }
//To print the sprial after the function is excuted
 void Matrix::printSpiral()
 {
      solveSpiral(0, columns-1, rows-1);
        cout << endl;
 }
//Return trace of the matrix if possible. If it is not possible, then return -1.
  int Matrix::trace()
  {
  int sum=0;
  if(rows==columns)
  {
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<columns;j++)
      {
        if(i==j)  
        sum+=mat[i][j];
      }
    }
    return sum;
  }
  else  
    return -1;
 }
 //special matrix if the sum of each row is integer 'x' and sum of each column is integer 'y' and 'x' equals 'y'. Return true if the matrix is special, else return false.

 bool Matrix::isSpecialMatrix()
 {
  int x=0;
        for(int i=0; i<rows; i++) 
        {
            x += mat[i][0];
        }
        for(int i=0; i<rows; i++) 
        {
            int c=0;
            for(int j=0; j<columns; j++) 
            {
                c += mat[i][j];
            }
            if(c!=x) 
            return false;
        }
        for(int i=0; i<columns; i++) 
        {
            int c=0;
            for(int j=0; j<rows; j++) 
            {
                c += mat[j][i];
            }
            if(c!=x) 
            return false;
        }
        return true;
 }
  
int main() 
{
    int n,m,q,c;
    cin>>n>>m;
    Matrix M(n,m);
    int arr[n+1][m+1];
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++)
       {
           int x;
           cin>>x;
           M.setValue(i,j,x);
       } 
    }
    cin>>q;
    int input;
    while(q--)
    {
      cin>>input;
      if(input==1)  
      M.printSpiral();
      else if(input==2) 
       cout<<M.trace()<<endl;
      else if(input==3)   
      {
            if(M.checkTriangular()) 
            cout << "true\n";
            else 
            cout << "false\n";
        }
      else if(input==4)  
       {
            if(M.isSpecialMatrix()) 
            cout << "true\n";
            else 
            cout << "false\n";
        }
    }  
    return 0;
}