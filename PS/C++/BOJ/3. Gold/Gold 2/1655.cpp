#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> v;

int check()
{
    sort(v.begin(), v.end());
    if(v.size()%2==0)
    {
        return v[v.size()/2-1];
    }
    else
    {
        return v[v.size()/2];
    }
}

int main()
{
    cin>>n;
    int i;
    for(i=0;i<n;++i)
    {
        int a;
        cin>>a;
        v.push_back(a);
        cout<<check()<<endl;
    }
    return 0;
}