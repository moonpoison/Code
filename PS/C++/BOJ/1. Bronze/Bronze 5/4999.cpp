#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s[2];
    cin>>s[0]>>s[1];
    if(s[0].size()>=s[1].size())
    {
        cout<<"go";
    }
    else
    {
        cout<<"no";
    }
}