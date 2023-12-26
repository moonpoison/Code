#include<iostream>
#include<algorithm>
using namespace std;//max(dp[i-1][k-w[i]]+v[i], dp[i-1][k])
int n, k;
int w[101]={0};
int v[101]={0};
int DP[101][100001]={0};

void dp()
{
    int i, j;
    for(i=1;i<=k;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(w[j]>i)
            {
                DP[j][i]=DP[j-1][i];
            }
            else
            {
                DP[j][i]=max(DP[j-1][i-w[j]]+v[j], DP[j-1][i]);
            }
        }
    }
}

int main()
{
   cin>>n>>k;
   for(int i=1;i<=n;++i)
    {
        cin>>w[i]>>v[i];
    }
    dp();
    cout<<DP[n][k];
}