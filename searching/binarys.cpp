#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll iterativbinarysearch(ll a[],ll n,ll s)
{
    ll l=0,r=n-1,mid=l+(l+r)/2;
    while(l<=r)
    {
        mid=l+(l+r)/2;
        if(s==a[mid])
            return mid;
        else if(s<a[mid])
            r=mid-1;
        else
            l=mid+1;
    }
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
    i=iterativbinarysearch(a,n,s);
    if(i==-1)
        cout<<"\nNot found";
    else
        cout<<"\npos:"<<i;


}
