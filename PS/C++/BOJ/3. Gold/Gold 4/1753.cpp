#include<iostream>
#include<queue>
#include<vector>
#define INF 1000000
using namespace std;

int n, m;
vector<pair<int, int> > v[300001];
int cost[20001];

void dfs(int a)
{
    cost[a]=0;
    priority_queue<pair<int, int>> q;
    q.push({0, a});
    while(!q.empty())
    {
        int cur=q.top().second;
        int val=-q.top().first;
        q.pop();
        if(cost[cur]<val) 
        {
            continue;
        }
        for(int i=0;i<v[cur].size();++i)
        {
            int next=v[cur][i].second;
            int next_val=val+v[cur][i].first;
            if(cost[next]>next_val)
            {
                cost[next]=next_val;
                q.push({-next_val, next});
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int k;
    cin>>k;
    int i, j;
    for(i=0;i<m;++i)
    {
        int a, b, c;
        cin>>a>>b>>c;
        v[a].push_back({c, b});
        
    }
    for(i=1;i<=n;++i)
    {
        cost[i]=INF;
    }

    dfs(k);

    for(i=1;i<n+1;++i)
    {
        if(cost[i]==INF)
            cout<<"INF"<<" ";
        else
            cout<<cost[i]<<" ";
    }
}