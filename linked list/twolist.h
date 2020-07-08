#include<bits/stdc++.h>
#include"other.h"
using namespace std;
typedef long long ll;
void intersection(NODE *h1,NODE *h2)
{
    vector<ll>v;
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data==h2->data)
        {
            v.push_back(h1->data);//<<" ";
            h1=h1->nxt;h2=h2->nxt;
        }
        else if(h1->data<h2->data)
            h1=h1->nxt;
        else
            h2=h2->nxt;
    }
    if(v.size()==0)
    {
        cout<<"\nIntersections :";
        for(ll i=0;i<v.size();i++)
            cout<<v[i]<<" ";
    }
    else
        cout<<"\nNO Common Elements";
}
NODE* merge2List(NODE *h1,NODE *h2)
{
    NODE *newlist=NULL,*a=NULL;
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data==h2->data)
        {
            if(newlist==NULL)
            {
                newlist=a=createNODE(h1->data);
            }
            else
            {
                a->nxt=createNODE(h1->data);
                a=a->nxt;
            }
            h1=h1->nxt;h2=h2->nxt;
        }
        else if(h1->data<h2->data)
        {
            if(newlist==NULL)
            {
                newlist=a=createNODE(h1->data);
            }
            else
            {
                a->nxt=createNODE(h1->data);
                a=a->nxt;
            }
            h1=h1->nxt;
        }
        else//h2->Data<h1->Data
        {
            if(newlist==NULL)
            {
                newlist=a=createNODE(h2->data);
            }
            else
            {
                a->nxt=createNODE(h2->data);
                a=a->nxt;
            }
            h1=h2->nxt;

        }
    }
    if(h1==NULL && h2!=NULL)//h2 exist but not h1
    {
        a->nxt=createNODE(h2->data);
        a=a->nxt;
        h2=h2->nxt;
    }
    if(h2==NULL && h1!=NULL)//h1 exist but not h2
    {
        a->nxt=createNODE(h1->data);
        a=a->nxt;
        h2=h2->nxt;
    }
    return newlist;

}
void twolist(NODE **h1,NODE **h2)
{
    ll opt,d;
    NODE *h3=NULL;
    while(1)
    {
        if(*h1==NULL || *h2==NULL)
        {
            cout<<"\n2 Lists Must be Present!";
            break;
        }
        cout<<"\n1:Intersecting elements\n2:merge 2 sorted list\n3:Adding 2 polynomial list\n0:Exit\nOpt:";
        cin>>opt;
        if(opt==0)
            break;
        switch(opt)
        {
            case 1:
                intersection(*h1,*h2);
                break;
            case 2:
                h3=merge2List(*h1,*h2);
                cout<<"\nMerged List ";display(h3);
                break;
        }
    }
}

