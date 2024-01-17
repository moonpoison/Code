#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    int a=2;
    while(1)
    {
        if(n-i>0)
        {
            n-=i;
            if(a==2) a=1;
            else a=2;
        }
        else break;
        ++i;
    }
    if(a==1) cout<<1+(n-1)<<'/'<<i-(n-1);
    else cout<<i-(n-1)<<'/'<<1+(n-1);
}