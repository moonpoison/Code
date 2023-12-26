#include <iostream>
#include <vector>
using namespace std;
 
vector<int> v[2000];
bool vis[2000];
bool ans;
 
void dfs(int node, int depth) 
{
    if (depth == 4) 
    {
        ans = true;
        return;
    }
    vis[node] = true;
    for (int i = 0; i < v[node].size(); i++) 
    {
        int next = v[node][i];
        if (!vis[next] && !ans) dfs(next, depth + 1);
    }
    vis[node] = false;
}
 
int N, M;
int main() 
{
    cin >> N >> M;
    for (int i = 0; i < M; i++) 
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < N; i++) 
    {
        dfs(i, 0);
        if(ans) break;
    }
    cout << ans;
    return 0;
}