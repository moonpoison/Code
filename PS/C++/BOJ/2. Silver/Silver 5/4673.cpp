#include<iostream>
using namespace std;

int self(int a)
{
    int cnt=0;
    while(a!=0)
    {
        cnt+=(a%10);
        a/=10;
    }
    return cnt;
}

int main()
{
    int a[10001]={0};
    int i;
    for(i=1;i<10001;++i)
    {
        int b=self(i);
        if(i+b<=10000)
        {
            a[i+b]++;
        }
        if(a[i]==0)
        {
            cout<<i<<endl;
        }
    }
}