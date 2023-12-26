#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

vector<int> v(101); //to go
int n, m;
int MIN=99999;
int visit[101]={0};

void bfs()
{
    queue<pair<int, int> > q;
    q.push(make_pair(1, 0));
    v[1]++;
    while(!q.empty())
    {
        int cnt=q.front().second;
        int x=q.front().first;
        q.pop();
        int i;
        if(x==100)
        {
            if(cnt<MIN)
            {
                MIN=cnt;
            }
            break;
        }
        for(i=1;i<7;++i)
        {
            int dx=x+i;
            if(dx<=100&&visit[dx]!=1)
            {
                visit[dx]++;
                if(v[dx]==0)
                {
                    q.push(make_pair(dx, cnt+1));
                }
                else
                {
                    q.push(make_pair(v[dx], cnt+1));
                }
            }
        }
    }
}

int main()
{
    int i;
    cin>>n>>m;
    for(i=0;i<n+m;++i)
    {
        int a, b;
        cin>>a>>b;
        v[a]=b;
    }

    bfs();
    cout<<MIN;
}