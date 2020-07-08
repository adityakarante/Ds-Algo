#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Aqueue
{
public:
    ll f,r,si_ze,capacity;
    ll *a;
};
void init(Aqueue *q,ll  n)
{
    q->f=0;q->r=n-1;
    q->s=0;q->capacity=n;
    q->a=new ll(n);
}
 bool isEmpty(Aqueue *q)
{
    if(q->s==0)
        return true;
    return false;
}
bool isFull(Aqueue *q)
{
    if(q->s==q->capacity)
        return true;
    return false;
}
void inQueue(Aqueue *q,ll d)
{
    q->arr[++r]=n;
    q->s++;
}
ll deQueue(Aqueue *q)
{
        ll d=q->arr[f];


}
int main()
{
    Aqueue q;
    ll n;
    cin>>n;
    init(&q,n);




}
