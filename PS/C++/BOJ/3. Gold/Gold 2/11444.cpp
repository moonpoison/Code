/*
0.      0
1.      1
2k.     f(n/2)(f(n/2+1)+f(n/2-1))
2k+1.   f((n+1)/2)^2|f((n-1)/2)^2
*/
#include<iostream>
#include<map>
#define div 1000000007;
using namespace std;

long long n;
map<long long, long long> m;
long long dp(long long a)
{
    if(a==0) return 0;
    if(a==1) return 1;
    if(a==2) return 1;
    if(m.count(a)>0) return m[a]; //키값에 저장된게 있으면 반환
    if(a%2==0)//홀짝반환 및 맵에 값 저장
    {
        long long s=a/2;
        long long tmp1=dp(s-1);
        long long tmp2=dp(s);
        m[a]=((2LL*tmp1+tmp2)*tmp2)%div;//integer overflow 방지용 2대신 2LL먼저 곱하기(이거때매 1시간쓴듯..)
        return m[a];
    }
    else
    {
        long long s=(a+1)/2;
        long long tmp1=dp(s);
        long long tmp2=dp(s-1);
        m[a]=(1LL*tmp1*tmp1+tmp2*tmp2)%div;
        return m[a]; 
    }
}

int main()
{
    cin>>n;
    cout<<dp(n)%1000000007;
}