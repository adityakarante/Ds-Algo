#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N NULL
struct node {
    int data;
    node *r;
    node *l;
};
node * create(int d)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->l=tmp->r=NULL;
    tmp->data=d;
    return tmp;
}
void insert(node **root,ll d)
{
    node *tmp;
    if(*root==NULL)
    {
        *root=create(d);
         return;
    }
    queue<node*>q;
    q.push(*root);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(!tmp->l)
        {
            tmp->l=create(d);
            break;
        }
        else
            q.push(tmp->l);
        if(!tmp->r)
        {

            tmp->r=create(d);
            break;
        }
        else
            q.push(tmp->r);
    }

}
//1)Check for Children Sum Property in a Binary Tree
int children_Sum(node *root)
{
    if(root==NULL || (root->l==NULL && root->r==NULL))
        return 1;
    else
    {
        ll ldata=0,rdata=0;
        if(root->l)
            ldata=root->l->data;
        if(root->r)
            rdata=root->r->data;
        if((root->data==ldata+rdata) && children_Sum(root->l) && children_Sum(root->r))
            return 1;
        else
            return 0;


    }
}
//2)Check sum of Covered and Uncovered nodes of Binary Tree
int add_Left_Part(node *root)
{
    if(root->l )
    {
        return root->data+add_Left_Part(root->l);
    }
    else if(root->l==NULL && root->r)
    {
        return root->data+add_Left_Part(root->r);
    }

    return 0;



}
int add_Right_Part(node *root)
{
    if(root->r)
    {
        return root->data+add_Right_Part(root->r);
    }
    else if(root->r==NULL && root->l)
    {
        return root->data+add_Right_Part(root->l);
    }
    return 0;

}
int add_Internal_Left(node *root)
{
    if(root->l && root->r)
        return


}
int add_Internal_Right(node *root)
{

}
int check_Sum_Covered_Uncovered(node *root)
{
    if(root==NULL)
        return 0;
    int rootdata=root->data;
    if(rootdata+add_Left_Part(root->left)+add_Right_Part(root->r)==add_Internal(root->l)+add_Internal(root->r))
        return 1;
    return 0;

}

int main()
{
    node *root=NULL;
    ll t,n;
    cout<<"Enter count and nodes: "<<endl;
    cin>>t;
    while(t--)
    {
        cin>>n;
        insert(&root,n);
    }
    if(children_Sum(root))
        cout<<"YES";
    else
        cout<<"NO";

}
