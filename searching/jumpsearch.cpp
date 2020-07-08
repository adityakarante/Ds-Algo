
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int minelement(ll a,ll b)
{
    if(a>b)
        return a;
    return b;

}

ll jumpSearch(ll a,ll n,ll s)
{
    ll step=sqrt(n);
    ll prev=0;
    while(a[minelement(step,n)-1]<s)
    {
        prev=step;
        step+=sqrt(n);
        if(prev>=n)
            return -1;
    }
    while(a[prev]<s)
    {
        prev++;
        if(prev=minelement(step,n))
            return -1;
    }
    if(a[prev]==s)
        return prev;
    return -1;
}
int main()
{
    ll n,i,s;
    cout<<"Cnt:";
    cin>>n;
    ll a[n];
    cout<<"\nElements\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    sort(a,a+n);
    cout<<"\n Enter element to search: ";cin>>s;
    i=jumpSearch(a,n,s);
    if(i==-1)
        cout<<"\nNot found";
    else
        cout<<"\npos:"<<i;


}
