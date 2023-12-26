#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int ax[4]={0, 0, -1, 1};
int ay[4]={1, -1, 0, 0};
int v[1001][1001]={0};
int arr[1001][1001]={0};
int re[1001][1001]={0};
int n, m;

void bfs(int sx, int sy)
{
	queue<pair<int, int> > q;
	q.push(make_pair(sx, sy));
	v[q.front().first][q.front().second]=1;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		int i, j;
		for(i=0;i<4;++i)
		{
			int dx=x+ax[i];
			int dy=y+ay[i];
			if(dx>=0&&dx<n&&dy>=0&&dy<m)
			{
				if(arr[dx][dy]==1&&v[dx][dy]==0)
				{
					q.push(make_pair(dx, dy));
					re[dx][dy]=re[x][y]+1;
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
			if(arr[i][j]==2)
			{
				a=i;
				b=j;
			}
		}
	}
	bfs(a, b);
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if(v[i][j]==0&&arr[i][j]==1)
			{
				cout<<-1<<' ';
			}
			else
			{
				cout<<re[i][j]<<' ';
			}
		}
		cout<<endl;
	}
}