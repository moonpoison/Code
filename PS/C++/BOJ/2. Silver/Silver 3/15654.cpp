#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"
using namespace std;

int n, m;
vector<int> v;
int arr[9];
int visit[9]={0};

void dfs(int a)
{
    if(a==m)
    {
        for(int i=0;i<m;++i)
            cout<<arr[i]<<' ';
        cout<<endl;
        return;
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
}