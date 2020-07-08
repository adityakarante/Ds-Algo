/*
classlocation.h -> traversal.h -> check.h -> summation.h -> other.h -> lca.h
*/
#include<bits/stdc++.h>
#include"lca.h"
typedef long long ll;
using namespace std;
void insertion(node **root,ll d)
{
    node *tmproot=*root,*tmp=NULL;
    //new node created
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=d;
    newnode->l=newnode->r=NULL;

    if(tmproot==NULL)//if tmproot is null means tree is empty
    {
        *root=newnode;
        return;
    }
    queue<node*>q;//queue is created
    q.push(tmproot);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(tmp->l!=NULL)
            q.push(tmp->l);
        else
        {
            tmp->l=newnode;
            queue<node*>emptyqueue;
            swap(q,emptyqueue);
            return;
        }
        if(tmp->r!=NULL)
            q.push(tmp->r);
        else
        {
            tmp->r=newnode;
            queue<node*>emptyqueue;
            swap(q,emptyqueue);
            return;
        }


    }
}


int main()
{
    system("color B0");
    node *root=NULL;
    ll opt,d,x;
    while(1)
    {
        cout<<"\n1:Create tree\n2:Traversal\n3:ToCheck\n4:Summation\n5:Other\n6:LCA\n0:Exit\nOpt: ";
        cin>>opt;

        if(opt>6 || opt==0)
            break;
        switch(opt)
        {
            case 1:
                cout<<"\nEnter count of values ";
                cin>>x;
                cout<<"\nEnter values: ";
                while(x--)
                {
                    cin>>d;
                    insertion(&root,d);
                }
                break;
            case 2:
                traversal(&root);
                break;
            case 5:
                other(&root);
                break;


        }

    }
 }
 /*
 void nonrecursivePreorder(node *root)
{
    node *tmp;
    std::stack<node*>s;
    while(1)
    {
         while(root!=nullptr)
        {
            cout<<root->data<<" ";
            s.push(root);
            root=root->l;
        }
        if(s.empty())
            break;
        root=s.top();
        root=root->r;
        s.pop();
    }


}
void nonrecursiveIneorder(node *root)
{
    node *tmp;
    std::stack<node*>s;
    while(1)
    {
         while(root!=nullptr)
        {
            s.push(root);
            root=root->l;
        }
        if(s.empty())
            break;
        root=s.top();
        cout<<root->data<<" ";
        root=root->r;
        s.pop();
    }


}
//max function
int findmax(node* root)
{
   int max=INT_MIN,ldata,rdata;
   if(root)
   {
       ldata=findmax(root->l);
       rdata=findmax(root->r);
       if(ldata>rdata)
            max=ldata;
        else
            max=rdata;
        if(root->data>max)
            max=root->data;
   }
    return max;
}
//max without recursion
int maxFind(node* root)
{
    queue<node*>q;
    node *tmp;
    int max=INT_MIN;
    if(root!=nullptr)
    {
        q.push(root);
        // cout<<q.size();
        while(!q.empty())
        {
            tmp=q.front();
            q.pop();
            if(tmp->data>max)
                max=tmp->data;
            // q.pop();
            if(tmp->l)
                q.push(tmp->l);
            if(tmp->r)
                q.push(tmp->r);
        }
    }

    return max;
}
//search
bool Search(node* root,int s)
{
    queue<node*>q;
    node *tmp;

    if(root!=nullptr)
    {
        q.push(root);
        // cout<<q.size();
        while(!q.empty())
        {
            tmp=q.front();
            q.pop();
            if(tmp->data==s)
                return true;
            // q.pop();
            if(tmp->l)
                q.push(tmp->l);
            if(tmp->r)
                q.push(tmp->r);
        }
    }

    return false;
}
//size of tree
int sizeOfTree(node *root)
{
    if(root)
    {
        return 1+sizeOfTree(root->l)+sizeOfTree(root->r);
    }
}
//level order traversal
void levelOrder(node* root)
{
    queue<node*>q;
    node *tmp;
    if(root!=nullptr)
    {
        q.push(root);
        // cout<<q.size();
        while(!q.empty())
        {
            tmp=q.front();
            q.pop();
            cout<<tmp->data<<" ";
            // q.pop();
            if(tmp->l)
                q.push(tmp->l);
            if(tmp->r)
                q.push(tmp->r);
        }
    }

}
//levelOreder reverse
void levelOrederReverse(node *root)
{
    //first insert left child in stack and then right child
    node *tmp;
    stack<int>s;
    queue<node*>q;
    if(root)
    {
        q.push(root);
        while(!q.empty())
        {
            tmp=q.front();
            s.push(tmp->data);
            q.pop();
            if(tmp->r)
                q.push(tmp->r);
            if(tmp->l)
                q.push(tmp->l);
        }

    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
//delete tree
void deleteTree(node* root)
{
    if(root)
    {
        deleteTree(root->l);
        deleteTree(root->r);
        free(root);
    }

}
//leaves count
int leavescount(node* root)
{
    int cnt=1;
    node *tmp;
    queue<node*>q;
    if(root)
    {
        q.push(root);
        while(!q.empty())
        {
            tmp=q.front();
            q.pop();
            if(tmp->l ||tmp->r)
            {
                if(tmp->l)
                    q.push(tmp->l);
                if(tmp->r)
                    q.push(tmp->r);
            }
            else//both child are not present
                cnt++;

        }
    }
    return cnt;
}
//count of complete node
int countFullNode(node* root)
{
    int cnt=0;
    node *tmp;
    // here -1 represnt blank node
    //example  2 node tree 1 as root and 2 as left child and right child is blank
    //    1
   //    / \
    //   2  -1


    queue<node*>q;
    if(root)
    {
        q.push(root);
        while(!q.empty())
        {
            tmp=q.front();
            q.pop();
            if(tmp->l && tmp->r)
                if(tmp->r->data!=-1 && tmp->l->data!=-1)
                    cnt++;
            if(tmp->r)
                q.push(tmp->r);
            if(tmp->l)
                q.push(tmp->l);
        }
    }
    return cnt;
}
//count of half nodes
int countHalfNode(node* root)
{
    int cnt=0;
    node *tmp;
    // here -1 represnt blank node
    //example  2 node tree 1 as root and 2 as left child and right child is blank
    //    1
   //    / \
    //   2  -1


    queue<node*>q;
    if(root)
    {
        q.push(root);
        while(!q.empty())
        {
            tmp=q.front();
            q.pop();
            if(tmp->l && tmp->r)
                if(tmp->r->data!=-1 &&tmp->l->data==-1 || tmp->r->data==-1 &&tmp->l->data!=-1)
                    cnt++;
            if(tmp->r)
                q.push(tmp->r);
            if(tmp->l)
                q.push(tmp->l);
        }
    }
    return cnt;
}
//delete node from b Tree
void deleteDeepNode(node* root,node* deepnode)//to delete deep node
{
    queue<node*>q;
    q.push(root);
    node* tmp;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(tmp==deepnode)
        {
            tmp=NULL;
            free(tmp);
            return;
        }
            if(tmp->l)
            {
                if(tmp->l==deepnode)
                {
                    tmp->l=NULL;
                    free(deepnode);
                    return;
                }
                else
                    q.push(tmp->l) ;
            }
            if(tmp->r)
            {
                if(tmp->r==deepnode)
                {
                    tmp->r=NULL;
                    free(deepnode);
                    return;
                }
                else
                    q.push(tmp->r) ;
            }


    }
}
node* deletenode(node *root,int  d)//to find node to delete and deep node
{
    if(root==NULL)
        return NULL;
    if(root->l==NULL && root->r==NULL)
    {
            if(root->data==d)
                return NULL;
            else
                return root;
    }
    queue<node*>q;
    node *deepnode,*todel;

    q.push(root);

    while(!q.empty())
    {
        deepnode=q.front();
        q.pop();
        if(deepnode->data==d)
            todel=deepnode;
        if(deepnode->l)
            q.push(deepnode->l);
        if(deepnode->r)
            q.push(deepnode->r);

    }
    if(todel!=NULL)
    {
        int tmp=deepnode->data;//storing deep node data in temporary variable
        deleteDeepNode(root,deepnode);//deleting deep node data
        todel->data=tmp;//replacing data of node to be deleted by deep node data
    }
    return root;


//diameter of tree
int height(Node *root)//to find height
{
    if(root==NULL)
        return 0;
    int l=height(root->left),r=height(root->right);
    if(l>r)
        return l+1;
    return r+1;
}
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;

}
int diameter(Node* root)
{
    if(root==NULL)
        return 0;
    int ans;
    int hl=height(root->left),hr=height(root->right);
    ans=max(hr+hl+1,max(diameter(root->left),diameter(root->right)));
    //some times diameter not present at root so max of diameter of left and right subtree
    return ans;

    // Your code here
}


//Max sum for level
int levelMaxSum(node *root)
{
    if(root==NULL)
        return 0;
    queue<node*>q;
    node *tmp;
    int sum=0,max=INT_MIN;
    q.push(root);
    int cnt=0;
    while(!q.empty())
    {
        cnt=q.size();
        sum=0;
        while(cnt--)
        {
            tmp=q.front();
            sum+=tmp->data;
            if(tmp->l)
                q.push(tmp->l);
            if(tmp->r)
                q.push(tmp->r);
            q.pop();
        }
        if(sum>max)
            max=sum;
    }
    return max;
}


//30)Modify a binary tree to get preorder traversal using right pointers only
void specifi_Level_Order(node *root)
{
    if(root==NULL)
        return;
    node *curr1,*curr2=NULL;
    std::queue<node*>q;
    cout<<root->data<<" ";
    if(root->l)
    {
        q.push(root->l);
        //  cout<<root->l->data<<" ";
    }
     if(root->r)
     {
         q.push(root->r);
        // cout<<root->r->data<<" ";
     }


    while(!q.empty())
    {
        curr1=q.front();
        q.pop();
        curr2=q.front();
        q.pop();
        cout<<curr1->data<<" "<<curr2->data<<" ";
        if(curr1->l)
        {
            q.push(curr1->l);
        }
        if(curr2->r)
        {
          q.push(curr2->r);
        }
        if(curr1->r)
        {
            q.push(curr1->r);
        }
        if(curr2->l)
        {
            q.push(curr2->l);
        }


    }


}
//27)density of binary tree
int density(node *root,int &size)
{
    if(root==NULL)
       return 0;

     int lh=density(root->l);
     int rh=density(root->r);

     size++;

    return l>r ? l+1:r+1;


}


 */

