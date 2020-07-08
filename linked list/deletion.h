/*
deletebegin(),deleteEnd(),delete_node_at_particular_position(),
delete_1st_occurence_of_key(),delete_all_ocurence_of_key(),
*/
#include<bits/stdc++.h>
#include "display.h"
//#include<unordered_set>
void deletion(NODE **head);
void delBegin(NODE **head)/*at begin*/
{
        NODE *t=*head;
        *head=t->nxt;
        delete t;
}
void delEnd(NODE **head)/*at end*/
{
        NODE *a=*head,*b=NULL;
        while(a->nxt!=NULL)
        {
            b=a;
            a=a->nxt;
        }
        b->nxt=NULL;
        delete a;
}
void deleAtPos(NODE **head,ll pos)/*at particular position*/
{
        ll cnt=getCount(head);
    if(pos<1 || pos>cnt)
    {
        cout<<"\nInvalid position";
        return;
    }
    else if(pos==1)
        delBegin(head);
    else if(pos==cnt)
        delEnd(head);
    else
    {
         ll i=1;
         NODE *a=*head,*b;
         while(i<pos)
         {
             b=a;
             a=a->nxt;
             i++;
         }
         b->nxt=a->nxt;
         delete a;
    }

}
void delAll(NODE **head)/*all*/
{
    NODE *t=*head,*b;
    while(t->nxt!=NULL)
    {
        b=t;
        t=t->nxt;
        delete b;
    }
    delete t;
    *head=NULL;

}
void del1stOcc(NODE **head,ll d)/*delete 1st occurence of data*/
{
    NODE *a=*head,*b;
    if(a->data==d)
    {
        delBegin(head);
        return ;
    }
    while(a->nxt!=NULL)
    {
        b=a;
        a=a->nxt;
        if(a->data==d)
            break;
    }
    b->nxt=a->nxt;
    delete a;
}
void delAllOccurence(NODE **head,ll d)
{
    NODE *a=*head,*b=NULL;
    while(a!=NULL && a->data==d)
    {
        *head=a->nxt;
        delete a;
        a=*head;
    }
    while(a!=NULL)
    {
        while(a!=NULL && a->data!=d)
        {
            b=a;
            a=a->nxt;
        }
        if(a==NULL)
            return;
        b->nxt=a->nxt;
        delete  a;
        a=b->nxt;
    }

}
void removeDuplicate(NODE **head)
{
    NODE *a=*head,*b=NULL;
    while(a!=NULL && a->nxt!=NULL)
    {
        b=a;
        a=a->nxt;
        if(b->data==a->data)
        {
            b->nxt=a->nxt;
            delete a;
            a=b;
        }
    }
}
void delAlternate(NODE **head)
{
    if((*head)->nxt==NULL)
        return;
    else
    {
        NODE *curr=*head,*next=NULL;
        while(curr!=NULL && curr->nxt!=NULL)
        {
            next=curr->nxt;
            curr=curr->nxt->nxt;
            delete next;
        }
    }
}
void removeDuplicateUnsorted(NODE **head)
{
    set<ll>s;
    NODE *a=*head,*b=NULL;
    while(a!=NULL)
    {
        if(s.find(a->data)!=s.end())
        {
            b->nxt=a->nxt;
            delete a;
        }
        else
        {
            s.insert(a->data);
            b=a;
        }
        a=b->nxt;
    }
}
void deletion(NODE **head)
{
    ll opt,d,pos;
    while(1)
    {
        if(isEmpty(head))
        {
            cout<<"\nEmpty List";
            return ;
        }
        cout<<"\n1:delete at begin\n2:delete at End\n3:At particular position\n4:Complete List";
        cout<<"\n5:1st occurence of data\n6:All occurence of data\n7:Remove duplicate\n8:Remove duplicate from unsorted list";
        cout<<"\n9:Delete Alternate nodes(wrong)\n100:display\nExit(0)\nOPT:";
        cin>>opt;
        if(opt==0)
            break;
        switch(opt)
        {
            case 1:
                delBegin(head);
                break;
            case 2:
                delEnd(head);
                break;
            case 3:
                cout<<"\nEnter position";
                cin>>pos;
                deleAtPos(head,pos);
                break;
            case 4:
                delAll(head);
                break;
            case 5:
                cout<<"\nEnter data to delete";
                cin>>d;
                del1stOcc(head,d);
                break;
            case 6:
                cout<<"\nEnter data to delete";
                cin>>d;
                delAllOccurence(head,d);
                break;
            case 7:
                removeDuplicate(head);break;
            case  8:
                    removeDuplicateUnsorted(head);break;
            case 9:
                    delAlternate(head);break;
            case 100:display(*head);
                break;



        }
    }
}

