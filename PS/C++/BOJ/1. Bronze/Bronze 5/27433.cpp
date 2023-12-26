#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i;
    unsigned long long int a=1;
    for(i=1;i<=n;++i)
    {
        a*=i;
    }
    cout<<a;
}