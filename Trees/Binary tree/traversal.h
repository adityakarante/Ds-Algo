#include<bits/stdc++.h>
#include "classlocation.h"
using namespace std;
//by inorder using stack
void inOrder(node *h)
{
    stack<node*>s;
    while(1)
    {
        while(h)
        {
            s.push(h);
            h=h->l;
        }
        if(s.empty())
            break;
        h=s.top();s.pop();
        cout<<h->data<<" ";//after popoing process current element
        h=h->r;

    }
     stack<node*>extra;
    swap(extra,s);
 /*   if(h)
    {
        inOrder(h->l);
        cout<<h->data<<" ";
        inOrder(h->r);
    }*/
}
//inorder by morris way
void Morris(node *root)
{
    if(root==NULL)//if null then return
        return;
    node *current=root,*pred;
    while(current!=NULL)
    {
        //if no left then print and go to right
        if(current->l==NULL)
        {
            cout<<current->r;
            current=current->r;
        }
        else//if current has left
        {
            //find predecessor
            pre=current->l;
            while(pred->r!=NULL && pre->r!=current)
                pred=pred->r;

            if(pred->r==NULL)
            {
                    pred->r=current
                    current=current->l;
            }


        }

    }
}
void preOrder(node *h)
{
    stack<node*>s;
    while(1)
    {
        while(h)
        {
            cout<<h->data<<" ";//process current node;
            s.push(h);
            h=h->l;//if left exist go to left
        }
        if(s.empty())
            break;
        h=s.top();s.pop();
        h=h->r;
    }
    stack<node*>extra;
    swap(extra,s);
    /*if(h)
    {
        cout<<h->data<<" ";
        preOrder(h->l);
        preOrder(h->r);
    }*/
}
void postOreder(node *h)
{
    if(h)
    {
        postOreder(h->l);
        postOreder(h->r);
        cout<<h->data<<" ";
    }
}
void levelOrder(node **root)
{
    if(*root==NULL)
        return;
    node *curr=*root;
    queue<node*>q;
    q.push(curr);
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->l)
            q.push(curr->l);
        if(curr->r)
            q.push(curr->r);
    }

}
void levelOrderReverse(node *root)
{
    node *tmp=root;
    queue<node*>q;
    stack<node*>s;
    if(root)
        q.push(root);
    while(!q.empty())
    {
        tmp=q.front();q.pop();
        if(tmp->r)//first right
            q.push(tmp->r);
        if(tmp->l)//2nd left
            q.push(tmp->l);
        s.push(tmp);//stack used
    }
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
}
void traversal(node **head)
{
    node *h=*head;
    ll opt;
    while(1)
    {
        cout<<"\n1:Inorder\n2:Preorder\n3:Postorder\n4:Level Order\n5:LEVER ORDER REVERSE\n0:Exit\n:Opt: ";
        cin>>opt;
        if(opt==0)
            break;
        switch(opt)
        {
            case 1:
                inOrder(h);break;
            case 2:
                preOrder(h);break;
            case 3:
                postOreder(h);break;
            case 4:
                levelOrder(head);break;
            case 5:
                levelOrderReverse(h);break;
        }
    }

}
//replace each node by sum of predecessor and successor
//setp 1:first createa array
//step 2: assign array
//function for setp 1
void createArray(node * root,vector<ll>&v)
{
    if(root==NULL)
        return;
    if(root->l)
        createArray(root->l,v);
    v.push_back(root->data);
    if(root->r)
        createArray(root->r,v);

}
//function for step 2
void assignSum(node *root,vector<ll>v,ll &index)
{
    if(root==NULL)
        return;
    if(root->l)
        assignSum(root->l,v,index);

    //assign previous and next value and increment index
    root->data=v[index-1]+v[index+1];
    index++;

    if(root->r)
        assignSum(root->r,v,index);
}
//calling function
void  replacebySum_predecessor_sucessor(node *root)
{
    if(root==NULL)
        return ;
    std::vector<ll>v;
    v.push_back(0);

    createArray(root,v);

    v.push_back(0);

    ll index=1;
    assignSum(root,v,index);
}
//here ends




//to find nth node of inorder traversal
void nthInorder(node *root,ll n)
{
    static ll cnt=0;
    if(root==NULL)
        return;

    if(cnt<=n)
    {
        if(root->l)
            nthInorder(root->l,n);
            cnt++;
        if(cnt==n)
            cout<<endl<<cnt<<"nth inorder: "<<root->data;
        if(root->r)
            nthInorder(root->r,n);
    }

}






//inorder without recursion and with stack
//inorder without stack and without recursion
void inorderMorris(node *root)
{
    if(root==NULL)
        return;
    node *curr=root,*pre;
    while(curr!=NULL)
    {
        if(curr->l==NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->r;
        }
        else//if current left exist
        {
            //find inorder predecessor (rightmost on left subtree)
            pre=curr->l;
            while(pre->r!=NULL && pre->r!=curr)
                pre=pre->r;

            //if right of innorder predecessor not exist
            if(pre->r==NULL)
            {
                pre->r=curr;
                curr=curr->l;
            }

            else
            {
                pre=NULL;
                cout<<curr->data<<" ";
                curr=curr->r;
            }
        }
    }
}


void inorderByStack(node *root)
{
    cout<<"Insidde function";

    stack<node*>s;
    node* present;
    if(root==NULL)
        return;
    present=root;
    while(present!=NULL || s.empty()==false )
    {
        //go upto left
        while(present!=NULL)
        {
            s.push(present);
            present=present->l;
        }

        present=s.top();
        s.pop();
        cout<<present->data<<" ";

        present=present->r;


    }


}



//to chekc continous or not
bool isContinous(node *root)
{
    //if null
    if(root==NULL)
        return true;
    //if leaf return true
    else if(root->l==NULL && root->r==NULL)
        return true;
    //if only right child then check and go to right child
    else if(root->l==NULL)
        return (abs(root->data - root->r->data)==1) && isContinous(root->r);
    //if only left child then check and go to left child
    else if(root->r==NULL )
        return (abs(root->data - root->l->data)==1) && isContinous(root->l);
    //if both childs then check both
    else
    {
        return
        abs(root->data - root->l->data)==1  &&  isContinous(root->l)  &&
        abs(root->data - root->r->data)==1 &&  isContinous(root->r)  ;
    }


}

// to delete node from binary tree
void deleteNode(node *root,int d)
{
    if(root==NULL)
        return;
    else if(root->l==NULL && root->r==NULL)
    {
        if(root->data==d)
        {
            root=NULL;
        }
        return;
    }
    node *tmp;node *deep,*todelnode;
    ll deepnodedata;
    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        tmp=q.front();

        q.pop();
        if(tmp->data==d)
            todelnode=tmp;
        if(tmp->l)
            q.push(tmp->l);
        if(tmp->r)
            q.push(tmp->r);


    }
    //now last node in queue is deep node
    deep=tmp;
    cout<<"\nDeepnode data"<<deep->data;
    if(todelnode)
    {
        //replacing node data with deepnode data
        todelnode->data=deep->data;
        queue<node*>qdeep;
        qdeep.push(root);
        while(!qdeep.empty())
        {
            tmp=qdeep.front();
            qdeep.pop();
            if(tmp==deep)
            {
                tmp=NULL;
                free(deep);
                break;
            }
            if(tmp->l)
            {
                if(tmp->l==deep)
                {
                    tmp->l=NULL;
                    free(deep);
                    break;
                }
                else
                    qdeep.push(tmp->l);
            }
            if(tmp->r)
            {
                if(tmp->r==deep)
                {
                    tmp->r=NULL;
                    free(deep);
                    break;
                }
                else
                    qdeep.push(tmp->r);
            }



        }
    }


}

