#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a, b, c;
    cin>>a>>b>>c;
    int ans;
    if(a[0]<='9'&&a[0]>='0') ans=stoi(a)+3;
    else if(b[0]<='9'&&b[0]>='0') ans=stoi(b)+2;
    else if(c[0]<='9'&&c[0]>='0') ans=stoi(c)+1;
    
    if(ans%3==0&&ans%5==0) cout<<"FizzBuzz";
    else if(ans%3==0) cout<<"Fizz";
    else if(ans%5==0) cout<<"Buzz";
    else cout<<ans;
}