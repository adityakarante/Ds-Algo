/*
display(),
*/
#include<bits/stdc++.h>
#include "ins.h"
using  namespace std;

typedef long long ll;
void normaldisplay(NODE *head)
{
    if(isEmpty(&head))
    {
        cout<<"\nEmpty List";
        return ;
    }
    NODE *tmp=head;
    if(tmp)
        cout<<"DATA: ["<<tmp->data<<"]";
    tmp=tmp->nxt;
    while(tmp!=NULL)
    {
        cout<<" -> ["<<tmp->data<<"]";
        tmp=tmp->nxt;
    }
    cout<<"-> NULL";

}
void reverseDisplay(NODE *h)
{

    if(h==NULL)
        return;
    reverseDisplay(h->nxt);
    cout<<"["<<h->data<<"] ->"<<" ";
}
/*void insertionSort(NODE *head)
{
    NODE *prev=head,*curr=head->nxt;
    if(prev->nxt==NULL)
        return;
    else
    {
        for(;curr!=NULL;curr=curr->nxt)
        {
            for()
        }
    }

}*/
void display(NODE *h)
{
    ll opt;
    while(1)
    {
        cout<<"\n1:Normal display\n2:Reverse\n0:Exit\nOpt: ";
        cin>>opt;
        if(opt==0)
            break;
        switch(opt)
        {
            case 1:
                normaldisplay(h);break;
            case 2:
                cout<<"\nData: ";
                reverseDisplay(h);
                cout<<"NULL";break;
            case 3:
                 ;
                //insertionSort(h);
        }
    }


}
