#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c;
        cin>>a>>b;
        c=a;
        int i, j;
        for(i=0;i<b;++i)
        {
            cin>>a>>a;
        }
        cout<<c-1<<endl;
    }
}