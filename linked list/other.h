/*
getcount(),isEmpty(),search,get middle,get nth last,get nth node
number of times value come in list
*/
#include<bits/stdc++.h>
#include "deletion.h"
using namespace std;
typedef long long ll;

bool searchElement(NODE **head,ll d)/*search*/
{
    NODE *a=*head;
    if(a==NULL)
        return false;
    if(a->data==d)
        return true;

    return searchElement(&(a->nxt),d);
}
ll getNthElement(NODE **head,ll pos)/*get nth element*/
{
        ll cnt=0;
        NODE *a=*head;
        while(a!=NULL)
        {
            cnt++;
            if(cnt==pos)
                return a->data;
        a=a->nxt;
        }

}
ll getnthElementLast(NODE **head,ll pos)/*get nth element from last*/
{

        NODE *a=*head,*b=*head;
        while(pos)
        {
            a=a->nxt;
            pos--;
        }
        while(a!=NULL)
        {
            a=a->nxt;
            b=b->nxt;
        }
        return b->data;
}
ll getmiddle(NODE **head)
{
    //2 pointers method
    NODE *s=*head,*f=*head;
    while(f!=NULL && f->nxt!=NULL)
    {
        f=f->nxt->nxt;
        s=s->nxt;
    }
    return s->data;


}
ll getCountOfValue(NODE **head,ll d)
{
    if(*head==NULL)
        return 0;
    else if((*head)->data==d)
        return 1+getCountOfValue(&((*head)->nxt),d);
    return getCountOfValue(&((*head)->nxt),d);
}
bool isPalindrome(NODE **head)
{
    stack<ll>s;
    NODE *a=*head;
    while(a!=NULL)
    {
        s.push(a->data);
        a=a->nxt;
    }
    a=*head;
    while(a!=NULL && !s.empty())
    {
        if(a->data==s.top())
        {
            a=a->nxt;
            s.pop();
        }
        else
            break;
    }
    if(!a)
        return true;
    return false;
}
void movelast2front(NODE **head)
{
    NODE *curr=*head,*prev,*h=*head;
    if(curr->nxt!=NULL)
    {
        while(curr->nxt!=NULL && curr!=NULL)
        {
            prev=curr;
            curr=curr->nxt;
        }
        *head=curr;
        if(curr!=h->nxt)
        {


            curr->nxt=h->nxt;
        prev->nxt=h;

        }
        else
        {
            *head=curr;
            curr->nxt=h;
            //h->nxt=NULL;

        }
        h->nxt=NULL;

    }



}
void pairWiseSwap(NODE **head)
{
    NODE *a=*head;
    while(a!=NULL && a->nxt!=NULL)
    {
        a->data=(a->nxt->data)+(a->data)-((a->nxt->data)=(a->data));
        a=a->nxt->nxt;
    }

}
void segregateE_O(NODE **head)
{
    NODE *a=*head,*b=NULL,*prev;
    while(a->nxt!=NULL)
    {
        if(a->data&1)//if odd
        {
            addEnd(&b,a->data);
            if(a==*head)//if head
            {
                delBegin(head);
                a=*head;
            }
            else
            {
                prev->nxt=a->nxt;
                delete a;
                a=prev;
            }
        }
        prev=a;
        a=a->nxt;
    }
    a->nxt=b;

}
void reverseList(NODE **head)
{
    NODE *prev=NULL,*curr=*head,*next;
    while(curr!=NULL)
    {
        next=curr->nxt;
        curr->nxt=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}
void rotateanticlock(NODE **head,ll k)
{
    ll len=getCount(head),rem=0;
    vector<ll>a;
    NODE *tmp=*head,*curr,*prev;
    while(tmp!=NULL)
    {
        len++;
        tmp=tmp->nxt;
    }
    rem=len%k;
    if(k>=len)
    {
        if(rem & 1)
             reverseList(head);
        else
             ;
    }
    curr=*head;prev=NULL;
    while(k>0)
    {
        a.push_back(curr->data);
        prev=curr;
        curr=curr->nxt;
        k--;
        delete prev;
    }
    *head=curr;
    while(curr->nxt!=NULL)
        curr=curr->nxt;
    for(ll i=0;i<a.size();i++)
    {
        curr->nxt=createNODE(a[i]);
        curr=curr->nxt;
    }
}
void MakeMiddleHead(NODE **head)
{
    NODE *prev=*head,*s=*head,*f=*head;
    while(f!=NULL && f->nxt!=NULL)
    {
        prev=s;
        s=s->nxt;
        f=f->nxt->nxt;
    }
    prev->nxt=prev->nxt->nxt;
    s->nxt=*head;
    *head=s;
}
void other(NODE **head)
{
    ll opt,d,pos;
    while(1)
    {
        cout<<"\n1:isEmpty\n2:number of nodes\n3:Search";
        cout<<"\n4:get nth element\n5:get nth from last \n6:get middle\n7:number of time element occur\n8:isPalindrome\n9:move last element to front";
        cout<<"\n10:pairwise swap\n11:Segregate even and odd\n12:Reverse\n13:rotate anticlockwise\n14:Make Middle as Head\nExit(0)\nOPT:";
        cin>>opt;
        if(opt==0)
            break   ;
        switch(opt)
        {
            case 1:
                if(isEmpty(head))
                    cout<<"\nEmpty List";
                else
                    cout<<"\nNot Empty";
                break;
            case 2:
                cout<<"\nNumber of nodes:"<<getCount(head);
                break;
            case 3:
                cout<<"\nEnter no to search: ";
                cin>>d;
                if(!searchElement(head,d))
                    cout<<"NOT";
                cout<<" Found";
                break;
            case 4:
                cout<<"\nEnter position of element which you want";
                cin>>pos;
                if(pos<1 || pos>getCount(head))
                    cout<<"\nINVLID INPUT!";
                else
                    cout<<endl<<pos<<" element: "<<getNthElement(head,pos);
                break;
            case 5:
                cout<<"\nEnter position from last";
                cin>>pos;
                if(pos<1 || pos>getCount(head))
                    cout<<"\nINVLID INPUT!";
                else
                    cout<<endl<<pos<<"from last: "<<getnthElementLast(head,pos);
                break;
            case 6:
                cout<<endl<<"Middle: "<<getmiddle(head);
                break;
            case 7:
                cout<<"\nEnter no to find occurence of it";
                cin>>d;
                cout<<endl<<d<<" occur "<<getCountOfValue(head,d)<<" time";
                break;
            case 8:
                if(isPalindrome(head))
                    cout<<"\nPalindrome";
                else
                    cout<<endl<<"\nNot palindrome";
                break;
            case 9:
                movelast2front(head);
                break;
            case 10:
                pairWiseSwap(head);
                break;
            case 11:
                segregateE_O(head);
                break;
            case 12:
                reverseList(head);
                break;
            case 13:
                    cout<<"\nEnter how many nodes to rotate: ";
                    cin>>d;
                    rotateanticlock(head,d);
                    break;
            case 14:
                    MakeMiddleHead(head);
                    break;


        }
    }

}
