#include<iostream>
using namespace std;

int a, b, c;
long long q;
long long pow(int b)
{
    if(b==0) return 1;
    if(b==1) return a%c;
    q=pow(b/2)%c;
    if(b%2==0) return q*q%c;
    return q*q%c*a%c;
}

int main()
{
    cin>>a>>b>>c;
    cout<<pow(b);
}