#include<iostream>
#include<cstring>

#define endl "\n"
#define MAX 999999999
#define node 101
using namespace std;

int n, m;
int dp[node][node];

void fluid(int a)
{
    int i, j;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(i!=a&&j!=a)
            {
                if(dp[i][j]>dp[a][j]+dp[i][a])
                {
                    dp[i][j]=dp[a][j]+dp[i][a];
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    fill(dp[0], dp[node], MAX);
    for(int i=1;i<=n;++i)
        dp[i][i]=0;
    for(int i=0;i<m;++i)
    {
        int a, b, c;
        cin>>a>>b>>c;
        if(dp[a][b]>c)
            dp[a][b]=c;
    }
    for(int i=1;i<=n;++i)
    {
        fluid(i);
    }
    for(int i=1;i<=n;++i)
    {   
        for(int j=1;j<=n;++j)
        {
            if(dp[i][j]==MAX) cout<<0<<' ';
            else cout<<dp[i][j]<<' ';
        }    
        cout<<endl;
    }
}