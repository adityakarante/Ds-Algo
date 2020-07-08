#include<iostream>
using namespace std;
typedef long long ll;
class NODE
{
public:
    ll data;
    class NODE *nxt;
};
void init(NODE **head)
{
    *head=NULL;
    (*head)->nxt=NULL;

}
 NODE *createNODE(ll d)
{
    NODE *ptr=new NODE;
    ptr->data=d;
    ptr->nxt=NULL;
    return ptr;
}
ll getCount(NODE **head)/*get count*/
{
    NODE *t=*head;
    ll cnt=0;
    while(t!=NULL)
    {
        cnt++;
        t=t->nxt;
    }
    return cnt;
}
bool isEmpty(NODE **head)/*check empty*/
{
    if(!(*head))
        return true;
    return false;
}
