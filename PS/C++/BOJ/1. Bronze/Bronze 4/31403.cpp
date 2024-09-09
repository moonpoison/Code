#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    string a, b, c;
    cin>>a>>b>>c;
    int ans1, ans2;
    ans1=stoi(a)+stoi(b)-stoi(c);
    ans2=stoi(a)*pow(10, b.length())+stoi(b)-stoi(c);
    cout<<ans1<<endl<<ans2;
}