#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(s.length()>=6&&s.length()<=9) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}