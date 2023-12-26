#include<iostream>
#include<utility>
#include<queue>
using namespace std;

int n, m;
char arr[601][601];
int v[601][601]={0};
int ax[4]={0, 0, 1, -1};
int ay[4]={1, -1, 0, 0};
int re=0;

void bfs(int a, int b)
{
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    v[a][b]++;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int i;
        for(i=0;i<4;++i)
        {
            int dx=x+ax[i];
            int dy=y+ay[i];
            if(dx>=0&&dx<n&&dy>=0&&dy<m)
            {
                if(arr[dx][dy]!='X'&&v[dx][dy]==0)
                {
                    if(arr[dx][dy]=='P')
                    {
                        re++;
                    }
                    q.push(make_pair(dx, dy));
                    v[dx][dy]++;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    int i, j;
    int a, b;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='I')
            {
                a=i;
                b=j;
            }
        }
    }
    bfs(a, b);
    if(re==0)
    {
        cout<<"TT";
    }
    else
    {
        cout<<re;
    }
}