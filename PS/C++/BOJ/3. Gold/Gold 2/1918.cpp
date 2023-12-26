#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s;
    stack<char> a;
    cin>>s;

    for(int i=0;i<s.size();++i)
    {
        if(s[i]>='A'&&s[i]<='Z') cout<<s[i];
        else
        {
            if(s[i]=='(') a.push(s[i]);
            else if(s[i]=='*'||s[i]=='/')
            {
                while(!a.empty()&&(a.top()=='*'||a.top()=='/'))
                {
                    cout<<a.top();
                    a.pop();
                }
                a.push(s[i]);
            }
            else if(s[i]=='+'||s[i]=='-')
            {
                while(!a.empty()&&a.top()!='(')
                {
                    cout<<a.top();
                    a.pop();
                }
                a.push(s[i]);
            }
            else if(s[i]==')')
            {
                while(!a.empty()&&a.top()!='(')
                {
                    cout<<a.top();
                    a.pop();
                }
                a.pop();
            }
        }
    }
    while(!a.empty())
    {
        cout<<a.top();
        a.pop();
    }
}