/*
Connected component= if we choose any 2 nodes from
component there is path from one node to another node

for non directed graph we have weekly connected component
and for directed graph we have strongly connected component
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxs = 1e6+6;
//vector<int>g[maxs];
//bool vis[maxs]

dfs(ll k,vector<int>g[],int vis[])
{
    if(vis[k]==0)
    {
        vis[k]=1;
       // cout<<k<<" ";
        for(ll i=0;i<g[k].size();i++)
        {
            if(vis[g[k][i]]==0)
                dfs(g[k][i],g,vis);
        }
    }
}

int main()
{
    ll v,e,x,y;
    cin>>v>>e;
    vector<int>g[v+1];
    int vis[v+1]={0};
    ll con_comp=0;
    for(ll i=0;i<e;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(ll i=1;i<maxs;i++)
    {
        if(vis[i]==0)
        {
             dfs(i,g,vis);
             con_comp++;
        }

    }
    cout<<"\nConnected components: "<<con_comp;
}
