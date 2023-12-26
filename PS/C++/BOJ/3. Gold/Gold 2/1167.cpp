#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<pair<int, int> > v[100001];//start, end, cost
bool vis[100001]={false};
int n;
int ans=0;
int node=0;

void dfs(int a, int dis)//start distance
{
    if(vis[a]) return;
    if(ans<dis)
    {
        ans=dis;
        node=a;
    }
    vis[a]=true;
    for(int i=0;i<v[a].size();++i)
    {
        dfs(v[a][i].first, v[a][i].second+dis);
    }
}

int main()
{
    cin>>n;
    int i;
    for(i=0;i<n;++i)
    {
        int a, b, c;
        cin>>a>>b;
        while(b!=-1)
        {
            cin>>c;
            v[a].push_back({b, c});
            cin>>b;
        }
    }
    dfs(1, 0);
    memset(vis, false, sizeof(vis));
    ans=0;
    dfs(node, 0);
    cout<<ans;
}