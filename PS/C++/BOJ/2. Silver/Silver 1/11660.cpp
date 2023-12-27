#include<iostream>
#define endl "\n"
using namespace std;

int a[1025][1025];
int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    int i, j;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            int q;
            cin>>q;
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+q;
        }
    }
    int x1, x2, y1, y2;
    for(i=0;i<m;++i)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1]<<endl;
    }
}