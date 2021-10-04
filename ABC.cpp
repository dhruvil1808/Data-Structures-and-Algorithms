#include<iostream>
using namespace std;
class part_time
{
int a,b,c;
public:
void readp();
int calcp(int);
};
class full_time
{
int a,b,c;
public:
void readf();
int calcf(int);
};
class employee:public part_time,public full_time
{
int balance,sal,age,maxage;
public:
void read();
void choice();
};


void part_time::readp()
{
    cout<<"enter max cred, credit cost, credit yearly";
    cin>>a>>b>>c;
}
void full_time::readf()
{
    cout<<"enter max cred, credit cost, credit yearly";
    cin>>a>>b>>c;
}

int part_time::calcp(int money)
{
    int x=money/b;
    if(x<=c)
    {cout<<"in 1";
        cout<<(a/x);
        return(a/x);
    }
}
int full_time::calcf(int money)
{
    int x=money/b;
    if(x<=c)
    {
        return(a/x);
    }
}


void employee::read()
{
    cout<<"enter balance salary age and maxage";
    cin>>balance>>sal>>age>>maxage;
    readp();
    readf();


}
void employee::choice()
{
    int money=sal/2;
    int x;
    int ch;
    cin>>ch;
    cout<<ch<<"\n";
    if(ch==1)
    {
        
      x=calcp(money); 
    }
    else if(ch==2)
    {
      x=calcf(money); 
    }
    else
    {
        cout<<"invalid\n";
    }
    int c=maxage-x;
    balance=balance+(x*money)+(c*sal);
    //cout<<balance<<"\n";
    //cout<<c<<"\n";

}

int main()
{
    employee e;
    e.read();
    e.choice();
}