#include<iostream>
#include<queue>
using namespace std;

long long a, b;
long long ans=0;

void bfs()
{
    queue<pair<long long, long long>> q;
    q.push({a, 1});
    while(!q.empty())
    {
        pair<long long, long long> p=q.front();
        q.pop();
        if(p.first==b)
        {
            ans=p.second;
            return;
        } 
        if(p.first*2<=b) q.push({p.first*2, p.second+1});
        if(p.first*10+1<=b) q.push({p.first*10+1, p.second+1});
    }
    ans--;
}

int main()
{
    cin>>a>>b;
    bfs();
    cout<<ans;
}