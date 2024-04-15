#include<bits/stdc++.h>
using namespace std;

map<char, pair<char, char>> t;
void preorder(char node)//전위순회
{
    cout<<node;
    if(t[node].first!='.') preorder(t[node].first);
    if(t[node].second!='.') preorder(t[node].second);
}
void inorder(char node)//중위순회
{
    if(t[node].first!='.') inorder(t[node].first);
    cout<<node;
    if(t[node].second!='.') inorder(t[node].second);
}
void postorder(char node)//후위순회
{
    if(t[node].first!='.') postorder(t[node].first);
    if(t[node].second!='.') postorder(t[node].second);
    cout<<node;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        char a, b, c;
        cin>>a>>b>>c;
        t[a].first=b;
        t[a].second=c;
    }
    preorder('A');
    cout<<'\n';
    inorder('A');
    cout<<'\n';
    postorder('A');
}