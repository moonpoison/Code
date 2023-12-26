#include<iostream>
#include<vector>
#include<queue>

#define endl "\n"
#define node 1010
#define INF 999999999

using namespace std;

vector<pair<int, int>> v[node];
vector<int> pathv;
int path[node];
int cost[node];
int S, E;

void dyc(int a)
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
        for(int i=0;i<v[cur].size();++i)
        {
            int next=v[cur][i].second;
            int next_val=v[cur][i].first+val;
            if(cost[next]>next_val)
            {
                path[next]=cur;
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
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int a, b, c;
        cin>>a>>b>>c;
        v[a].push_back({c, b});
    }
    cin>>S>>E;
    for(int i=1;i<=n;++i)
        cost[i]=INF;
    dyc(S);
    cout<<cost[E]<<endl;
    int tmp=E;
    while(tmp)
    {
        pathv.push_back(tmp);
        tmp=path[tmp];
    }
    cout<<pathv.size()<<endl;
    for(int i=pathv.size()-1;i>=0;--i)
        cout<<pathv[i]<<' ';
}