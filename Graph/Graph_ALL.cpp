
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxs = 1e6+6;
vector<int>g[maxs];
bool vis[maxs];



void dfs(ll k)
{
    if(!vis[k])
    {
        vis[k]=true;
        cout<<k<<" ";
        for(ll i=0;i<g[k].size();i++)
        {
            if(!vis[g[k][i]])
                dfs(g[k][i]);
        }
    }
}

int main()
{
    ll t,v,e,x,y,i;
    //Enter vertices and edges
    cin>>v>>e;


    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin>>x;
    dfs(x);


}

