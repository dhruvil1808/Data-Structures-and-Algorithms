#include<iostream>
using namespace std;
class ABC;
class XYZ;
class XYZ
{
    private:
      int temp;
    public:
      bool search(ABC &);
     XYZ()
     {
       temp=5;
     }
};
class ABC
{
    private:
      int x;
    public:
    
      friend bool XYZ::search(ABC &);
      ABC(int a)
      {
          x=a;
      }
};
bool XYZ::search(ABC &a)
{
  int f=a.x;
    if (f==temp)
    return true;
    else 
    return false;
}



int main()
{ 
    int a;bool c;
    cout<<"enter: ";
    cin>>a;
    ABC b(a);
    XYZ x;
    c=x.search(b);
    cout<<c;
    return 0;
}