#include<iostream>
#include<stdlib.h>
using namespace std;

template<class t>
class matrix
{
 t a[50][50],b[50][50];
 int r1,c1,r2,c2;
 
 public:
 void accept();
 void add();
 void multiply();
 void transpose();
 void saddlepoint();
};

template<class t>
void matrix<t>::accept()
{
 cout<<"Enter number of rows in matrix a:";
 cin>>r1;
 
 cout<<"Enter number of rows in matrix a:";
 cin>>c1;
 
 cout<<"Enter number of columns in matrix b:";
 cin>>r2;
 
 cout<<"Enter number of columns in matrix b:";
 cin>>c2;
 
 cout<<"\nEnter the elements of matrix 1:";
 for(int i=0;i<r1;i++)
 for(int j=0;j<c1;j++)
 cin>>a[i][j];
 
 cout<<"\nEnter the elements of matrix 2:";
 for(int i=0;i<r2;i++)
 for(int j=0;j<c2;j++)
 cin>>b[i][j];
}

template<class t>
void matrix<t>::add()
{
 cout<<"sum\n";
 t d[r1][c1];
 for(int i=0;i<r1;i++)
 {
  for(int j=0;j<=i;j++)
  {
   d[i][j]=a[i][j]+b[i][j];
   cout<<d[i][j];
  }
  cout<<"\n";
 } 
}

template<class t>
void matrix<t>::multiply()
{
 cout<<"Product\n";
 t d[c1][r2];
 if(r1==c2)
 {
  for(int i=0;i<r2;i++)
  {
   for(int j=0;j<c1;j++)
   {
    d[i][j]=0;
    for(int k=0;k<c2;k++)
    {
     d[i][j]+=a[i][k]*b[k][j];
     cout<<d[i][j];
    }
   }
  }
  cout<<"\n";
 }
}

template<class t>
void matrix<t>::transpose()
{
 cout<<"Transpose\n";
 for(int i=0;i<c1;i++)
 {
  for(int j=0;j<r2;j++)
  {
   cout<<a[j][i];
  }
  cout<<"\n";
 }
}
  
template<class t>
void matrix<t>::saddlepoint()
{
 int n,k,m;
 for(int i=0;i<r2;i++) 
 {
  n=a[i][0];
  for(int j=0;j<c1;j++)
  {
   if(n>=a[i][j])
   {
    n=a[i][j];
    k=j;
   }
  }
  m=a[0][k];
  for(i=0;i<r1;i++)
  {
   if(m<=a[i][k])
   m=a[i][k];
  }
  if(m=n)
  cout<<"Saddle point of the matrix is "<<m;
 }
}  
  
int main()
{
 int ch;
 char choice;
 matrix <int>obj1;
 matrix <float>obj2;
 for(;;)
 {
  cout<<"MENU\n1)int value\n2)Float value\n3)Exit\nEnter your choice:";
  cin>>ch;
  switch(ch)
  {
   case 1:
   obj1.accept();
   do
   {
    cout<<"MENU\n1)Addition\n2)Multiplication\n3)Transpose\n4)Saddlepoint\n5)Back to above menu\nEnter your choice:";
    cin>>ch;
    switch(ch)
    {
     case 1:obj1.add();
     break;
    
     case 2:obj1.multiply();
     break;
    
     case 3:obj1.transpose();
     break;
    
     case 4:obj1.saddlepoint();
     break;
    
     case 5:break;
    }
    cout<<"Continue[y/n]:";
    cin>>choice;      
   } 
   while(choice=='y');
 
   break;
   
   case 2:
   obj2.accept();
   do
   {
    cout<<"MENU\n1)Addition\n2)Multiplication\n3)Transpose\n4)Saddlepoint\n5)Back to above menu\nEnter your choice:";
    cin>>ch;
    switch(ch)
    {
     case 1:obj2.add();
     break;
    
     case 2:obj2.multiply();
     break;
    
     case 3:obj2.transpose();
     break;
    
     case 4:obj2.saddlepoint();
     break;
    
     case 5:break;
    }
    cout<<"Continue[y/n]:";
    cin>>choice; 
   }
   while(choice=='y');
   break;
   
   case 3:exit(0);
  
   cout<<"Continue[y/n]:";
   cin>>choice;
   if(choice=='n')
   break;
  }
 }
}    
   
 
 
 
OUTPUT:

MENU
1)int value
2)Float value
3)Exit
Enter your choice:1
Enter number of rows in matrix a:2
Enter number of rows in matrix a:2
Enter number of columns in matrix b:2
Enter number of columns in matrix b:2

Enter the elements of matrix 1:2
2
2
2

Enter the elements of matrix 2:1
0
0
1

MENU
1)Addition
2)Multiplication
3)Transpose
4)Saddlepoint
5)Back to above menu
Enter your choice:1

sum
32
23

Continue[y/n]:y

MENU
1)Addition
2)Multiplication
3)Transpose
4)Saddlepoint
5)Back to above menu
Enter your choice:2

Product
22
22
Continue[y/n]:y

MENU
1)Addition
2)Multiplication
3)Transpose
4)Saddlepoint
5)Back to above menu
Enter your choice:3

Transpose
22
22
Continue[y/n]:y

MENU
1)Addition
2)Multiplication
3)Transpose
4)Saddlepoint
5)Back to above menu
Enter your choice:4

Saddle point of the matrix is 2
Continue[y/n]:y

MENU
1)Addition
2)Multiplication
3)Transpose
4)Saddlepoint
5)Back to above menu
Enter your choice:5
Continue[y/n]:n

MENU
1)int value
2)Float value
3)Exit
Enter your choice:2
Enter number of rows in matrix a:2
Enter number of rows in matrix a:2
Enter number of columns in matrix b:2
Enter number of columns in matrix b:2

Enter the elements of matrix 1:1.33
26.11
9.11
6.77

Enter the elements of matrix 2:1
0
0
1
MENU
1)Addition
2)Multiplication
3)Transpose
4)Saddlepoint
5)Back to above menu
Enter your choice:1

sum
2.33 26.11
9.11 7.77
Continue[y/n]:y

MENU
1)Addition
2)Multiplication
3)Transpose
4)Saddlepoint
5)Back to above menu
Enter your choice:2

Product
1.33 26.11
9.11 6.77
Continue[y/n]:y

MENU
1)Addition
2)Multiplication
3)Transpose
4)Saddlepoint
5)Back to above menu
Enter your choice:3

Transpose
1.33  9.11
26.11 6.77
Continue[y/n]:y

MENU
1)Addition
2)Multiplication
3)Transpose
4)Saddlepoint
5)Back to above menu
Enter your choice:4

Saddle point of the matrix is 1.33
Continue[y/n]:y

MENU
1)Addition
2)Multiplication
3)Transpose
4)Saddlepoint
5)Back to above menu
Enter your choice:5
Continue[y/n]:n

MENU
1)int value
2)Float value
3)Exit
Enter your choice:3

 
