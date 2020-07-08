#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,e,i,x,y;
    cin>>v>>e;
    map<int,vector<int> >g;
    map<int,bool>visited;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    map<int,vector<int> >::iterator it;
    for(it=g.begin();it!=g.end();++it)
    {
        cout<<"[ "<<it->first<<" ]";
        for(vector<int>::iterator it1=g[it->first].begin();it1!=g[it->first].end();++it1)
        {
            cout<<"=> "<<*it1;
        }
        cout<<endl;
    }
}
