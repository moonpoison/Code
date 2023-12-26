#include<iostream>
#include<string>
using namespace std;
int check(string s)
{
    int i;
    for(i=0;i<s.size();++i)
    {
        char c=s[i];
        int j=i+1, n;
        while(1)
        {
            if(c!=s[j]||j>=s.size())
            {
                n=j;
                break;
            }
            ++j;
        }
        for(j=n;j<s.size();++j)
        {
            if(c==s[j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    string s[n];
    int ans=0;
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        if(check(s[i]))
        {
            ans++;
        }
    }
    cout<<ans;
}