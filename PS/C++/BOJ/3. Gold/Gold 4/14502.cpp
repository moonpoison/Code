#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int n, m;
int arr[8][8]={0};
int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};
int tmp[8][8];
int cnt=0;

void mcopy(int (*a)[8], int (*b)[8])//배열복사
{
    int i, j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            a[i][j]=b[i][j];
        }
    }
}

void bfs()//본함수
{
    int arr2[8][8];
    mcopy(arr2, tmp);
    queue<pair<int, int> > q;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(arr2[i][j]==2)
            {
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty())
    {
        int ax=q.front().first;
        int ay=q.front().second;
        q.pop();
        for(int i=0;i<4;++i)
        {
            int x=ax+dx[i];
            int y=ay+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m)
            {
                if(arr2[x][y]==0)
                {
                    arr2[x][y]=2;
                    q.push(make_pair(x, y));
                }
            }
        }
    }
    int c=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(arr2[i][j]==0)
            {
                c++;
            }
        }
    }
    cnt=max(cnt, c);
}

void wall(int a)
{
    if(a==3)
    {
        bfs();
        return;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j) 
        {
            if(tmp[i][j]==0)
            {
                tmp[i][j]=1;
                wall(a+1);
                tmp[i][j]=0;
            }
        }
    }
}

int main()
{
    //입력부
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
            if(arr[i][j]==0)
            {
                mcopy(tmp, arr);
                tmp[i][j]=1;
                wall(1);
                tmp[i][j]=0;
            }
        }
    }

    //출력부
    cout<<cnt;
}