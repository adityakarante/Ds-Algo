
#include<bits/stdc++.h>
#include "summation.h"
using namespace std;
typedef long long ll;

ll getMax(node *root)
{
    ll ans=INT_MIN,left,right;
    if(root)//root!=NULL
    {
        left=getMax(root->l);
        right=getMax(root->r);
        if(left<right)
            ans=right;
        else
            ans=left;
        if(ans<root->data)
            ans=root->data;

    }
    return ans;

}
ll getMin(node *root)
{
    ll ans=INT_MAX,left,right;
    if(root)
    {
        left=getMin(root->l);
        right=getMin(root->r);
        if(right<left)
            ans=right;
        else
            ans=left;
        if(ans>root->data)
            ans=root->data;
    }
    return ans;
}
bool Search(node *root,ll d)
{
    if(root==NULL)
        return false;
    else
    {
        if(root->data==d)
            return true;
        else
        {
            bool tmp=Search(root->l,d);
            if(tmp)
                return tmp;
            else
                return Search(root->r,d);
        }
    }
    return false;
}
ll sizeOfTree(node *head)
{
    if(head==NULL)
        return 0;
    return sizeOfTree(head->l)+1+sizeOfTree(head->r);
}

//to delete entire tree
void deleteTree(node **head)
{//using preorder traversal
    if(*head)
    {
        deleteTree(&(*head)->r);//delete right 1st
        deleteTree(&(*head)->l);//delete left 2d
        free(*head);//after deleting childs then delete parent
    }

}

//to get height
ll getHeight(node *head)
{
    if(head)
    {
        ll left=getHeight(head->l);
        ll right=getHeight(head->r);
        if(left>right)
            return ++left;
        else
            return ++right;
    }
    return 0;
}


//to delete particular node
void deleteNode(node **head)
{
    node *tmp=*head;
    queue<node*>q;

}

void other(node **root)
{
    ll opt,d;
    while(1)
    {
        cout<<"\n1:Max\n2:Min\n3:Searchn4:Size of Tree\n5:Delete Tree\n6:Height of Tree\n7:Delete particular node\n0:Exit";
        cin>>opt;
        if(opt==0)
            break;
        switch(opt)
        {
            case 1:
                cout<<"\nMAX: "<<getMax(*root);break;
            case 2:
                cout<<"\nMIN: "<<getMin(*root);break;
            case 3:
                cout<<"\nEnter element to search:";
                cin>>d;
                if(Search(*root,d))
                    cout<<"\nFound";
                else
                    cout<<"\nNot Found";
                break;
            case 4:
                cout<<"\nSize of Tree: "<<sizeOfTree(*root);
                break;
            case 5:
                deleteTree(root);
                *root=NULL;
                break;
            case 6:
                cout<<"\nHeight of Tree: "<<getHeight(*root);
                break;
        }
    }
}
