#include<bits/stdc++.h>
using namespace std;
void test()
{
    long long int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    long long int x11=x2-x1;
    long long int y11=y2-y1;
    long long int x21=x3-x1;
    long long int  y21=y3-y1;
    long long int  area=x11*y21-x21*y11;
    if(area==0)
    {
        cout<<"TOUCH"<<endl;

    }
    else if(area<0)
    {
        cout<<"RIGHT"<<endl;

    }else
    {
        cout<<"LEFT"<<endl;

    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        test();
    }
}