#include<iostream>
using namespace std;
int main()
{
    int a, b;
    while(1)
    {
        cin>>a>>b;
        if(!a&&!b)
        {
            return 0;
        }
        if(a<=b)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
}