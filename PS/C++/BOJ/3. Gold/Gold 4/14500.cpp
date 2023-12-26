#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int ax[4]={0, 0, 1, -1};
int ay[4]={1, -1, 0, 0};
int n, m;
int arr[500][500]={0};
int visit[500][500]={0};
int MAX=0;

void check(int x, int y, int cnt, int score)
{
    if(cnt==4)
    {
        if(MAX<score)
        {
            MAX=score;
        }
        return;
    }
    int i, j;
    for(i=0;i<4;++i)
    {
        int dx=x+ax[i];
        int dy=y+ay[i];
        if(dx>=0&&dx<n&&dy>=0&&dy<m&&visit[dx][dy]!=1)
        {
            visit[dx][dy]=1;
            check(dx, dy, cnt+1, score+arr[dx][dy]);
            visit[dx][dy]=0;
        }
    }
    if(x-1>=0&&x+1<n&&y+1<m)
    {
        MAX=max(MAX, arr[x-1][y]+arr[x][y+1]+arr[x][y]+arr[x+1][y]);
    }
    if(x-1>=0&&x+1<n&&y-1>=0)
    {
        MAX=max(MAX, arr[x-1][y]+arr[x][y-1]+arr[x][y]+arr[x+1][y]);
    }
    if(y-1>=0&&y+1<m&&x+1<n)
    {
        MAX=max(MAX, arr[x][y-1]+arr[x][y+1]+arr[x][y]+arr[x+1][y]);
    }
    if(y-1>=0&&y+1<m&&x-1>=0)
    {
        MAX=max(MAX, arr[x][y-1]+arr[x][y+1]+arr[x][y]+arr[x-1][y]);
    }
}

int main()
{
    cin>>n>>m;
    int i, j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            cin>>arr[i][j];
        }
    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            visit[i][j]=1;
            check(i, j, 1, arr[i][j]);
            visit[i][j]=0;
        }
    }
    cout<<MAX;
}