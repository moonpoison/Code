#include<iostream>
using namespace std;
int main()
{
    int n, a[6], b, c;
    cin>>n;
    for(int i=0;i<6;++i)
        cin>>a[i];
    cin>>b;
    cin>>c;
    int T=0, p1, p2;
    for(int i=0;i<6;++i)
    {
        T+=(a[i]/b)+1;
        if(a[i]%b==0) T-=1;
    }
    p1=n/c; p2=n%c;
    cout<<T<<endl<<p1<<' '<<p2;
}