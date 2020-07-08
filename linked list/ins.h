#include<bits/stdc++.h>
#include "classlocation.h"
using  namespace std;
typedef long long ll;

void addBegin(NODE **head,ll d)/*at begin*/
{
    NODE *tmp=createNODE(d);
    tmp->nxt=*head;
    *head=tmp;
}
void addEnd( NODE **head,ll d)/*at end*/
{
    NODE *t=createNODE(d);
    if(*head==NULL)
    {
        *head=t;
    }
    else
    {
        NODE *tmp=*head;
        while(tmp->nxt!=NULL)
            tmp=tmp->nxt;
        tmp->nxt=t;
    }

}
void addAtPos(NODE **head,ll d,ll pos)/*at particular position*/
{

    ll cnt=getCount(head);
    if(pos<1 || pos >(cnt+1))
        return;
    else if(pos==1)
        addBegin(head,d);
    else if(pos==cnt+1)
        addEnd(head,d);
    else
    {
         NODE *t=createNODE(d),*a=*head,*b=NULL;
         ll i=0;
         while(i<pos)
         {
             b=a;
             a=a->nxt;
             i++;
        }
        b->nxt=t;
        t->nxt=a;
    }

}
void insertion(NODE **head)
{
    ll opt,d,pos;
    while(1)
    {
        cout<<"\n1:Insert at begin\n2:Insert at End\n3:At particular position\nExit(0)\nOPT:";
        cin>>opt;
        if(opt==0)
            break;
        switch(opt)
        {
            case 1:
                cout<<"\nEnter data";
                cin>>d;
                addBegin(head,d);
                break;
            case 2:
                cout<<"\nEnter data";
                cin>>d;
                addEnd(head,d);
                break;
            case 3:
                cout<<"\nEnter data & position";
                cin>>d>>pos;
                addAtPos(head,d,pos);
                break;
        }
    }

}


