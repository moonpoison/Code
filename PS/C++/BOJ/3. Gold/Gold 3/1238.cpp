#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

#define endl "\n"
#define N 1001
#define MAX 9999999
using namespace std;

int n, m, x;
vector<pair<int, int>> arr[N];
int cost[N];
int cost2[N];
int ans=0;

void func(int a)
{
    cost[a]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, a});
    while(!q.empty())
    {
        int val=q.top().first;
        int cur=q.top().second;
        q.pop();
        if(cost[cur]<val)
            continue;
        for(int i=0;i<arr[cur].size();++i)
        {
            int next_val=val+arr[cur][i].first;
            int next=arr[cur][i].second;
            if(cost[next]>next_val)
            {
                cost[next]=next_val;
                q.push({next_val, next});
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m>>x;
    for(int i=0;i<m;++i)
    {
        int a, b, c;
        cin>>a>>b>>c;
        arr[a].push_back({c, b});
    }
    for(int i=1;i<=n;++i)
    {
        if(i!=x)
        {
            memset(cost, MAX, sizeof(cost));
            func(i);
            cost2[i]=cost[x];
        }
    }
    memset(cost, MAX, sizeof(cost));
    func(x);
    
    for(int i=1;i<=n;++i)
    {
        if(i!=x&&ans<cost[i]+cost2[i]) ans=cost[i]+cost2[i];
    }
    cout<<ans;
}