#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

#define endl "\n"
using namespace std;

int n, m;
vector<int> v;
int arr[9];
int visit[9]={0};
set<vector<int>> s;

void dfs(int a)
{
    if(a==m)
    {
        vector<int> q;
        for(int i=0;i<m;++i)
            q.push_back(arr[i]);
        s.insert(q);
    }
    else
    {
        for(int i=0;i<v.size();++i)
        {
            if(!visit[i])
            {
                visit[i]++;
                arr[a]=v[i];
                dfs(a+1);
                visit[i]--;
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    dfs(0);
    for(auto vector:s)
    {
        for(auto tmp:vector)
        {
            cout<<tmp<<' ';
        }
        cout<<endl;
    }
}