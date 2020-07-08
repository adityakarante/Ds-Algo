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
//Post order without recursion
void postOrder_by_2Stack(node *root)
{
    if(!root)
        return;
    stack<node*>tmp,ans;
    node *curr=root;
    tmp.push(curr);
    while(tmp.empty()==false)
    {
        curr=tmp.top();
        tmp.pop();
        ans.push(curr);
        if(curr->l)
            tmp.push(curr->l);
        if(curr->r)
            tmp.push(curr->r);


    }
    while(ans.empty()==false)
    {
        curr=ans.top();
        cout<<curr->data<<" ";
        ans.pop();
    }


}

//Preorder without recursion
void preOrderByStack(node *root)
{
    if(!root)
        return;
    stack<node*>s;
    node *curr=root;
    while(curr!=NULL || s.empty()==false)
    {
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            s.push(curr);
            curr=curr->l;
        }
        curr=s.top();
        s.pop();
        curr=curr->r;
    }

}

//inorder without recursion
void inorderByStack(node *root)
{
    if(!root)
        return;
    node *tmp=root;
    stack<node*>s;
    while(tmp!=NULL || !s.empty())
    {
        while(tmp!=NULL)
        {
            s.push(tmp);
            tmp=tmp->l;
        }
        tmp=s.top();
        cout<<tmp->data<<" ";
        s.pop();
        tmp=tmp->r;
    }
}

//Morris inorder traversal
void Morris(node *root)
{
    if(!root)
        return;
    node *curr,*pre;
    curr=root;
    while(curr!=NULL)
    {
        if(curr->l==N)
        {
            cout<<curr->data<<" ";
            curr=curr->r;
        }
        else
        {
            pre=curr->l;
            while(pre->r!=N && pre->r!=curr)
                pre=pre->r;

        }
        if(pre->r==NULL)
        {
            pre->r=curr;
            curr=curr->l;
        }
        else//done with traversal
        {
            pre->r=NULL;
            cout<<curr->data<<" ";
            curr=curr->r;

        }

    }
}
//replace each node by inorder predecessor and successor
void inorder_To_Replace(node *root,vector<ll>&v)
{
    if(root)
    {
        inorder_To_Replace(root->l,v);
        v.push_back(root->data);
        inorder_To_Replace(root->r,v);
    }

}
void to_Replace(node *root,vector<ll>&v,ll &index)
{
    if(root)
    {
        to_Replace(root->l,v,index);
          root->data=v[index-1]+v[index+1];
          index++;
        to_Replace(root->r,v,index);
    }
}
void replacebySum_predecessor_sucessor(node *root)
{
    if(!root)
        return;
    vector<ll>v;
    //creating vector of inorder traversal
    v.push_back(0);
    inorder_To_Replace(root,v);
    v.push_back(0);
    //replacing
    ll index=1;
    to_Replace(root,v,index);
}

//print Inorder sucessor of give node
void inorderSuccessor(node *root,ll key)
{
    cout<<"inside function";
    int flg=0;
    if(!root)
        return;
    stack<node*>s;
    node *curr=root;
    while(curr!=NULL || !s.empty())
    {
        while(curr!=NULL)
        {
            //cout<<"\nPushing :"<<curr->data;
            s.push(curr);
            curr=curr->l;
        }
        curr=s.top();

        if(flg)
        {
            cout<<"next inorder successor of "<<key<<" is "<<curr->data<<" ";
            flg=0;
            break;
        }
       s.pop();
       cout<<"\npopping :"<<curr->data;
        if(curr->data==key)//now its next  content inside stack will be inorder successor of this
        {
            //cout<<"\nmatching :"<<curr->data;
            flg=1;
        }
        curr=curr->r;

    }
    //means matched but it is last node
    if(flg==1)
    {
            cout<<"Inorder successor of "<<key <<" is NULL";
    }


}
//nth inorder of tree
void nthInorder(node *root,ll &no)
{
    if(root && no>0)
    {
        nthInorder(root->l,no);
        no--;
        //cout<<"now n is"<<no;
        if(no==0)
            cout<<"\nDATA: "<<root->data;
        nthInorder(root->r,no);
    }
}
//lelvel order traversal
void levelOrder(node *root)
{
    if(!root)
        return;
    queue<node*>q;
    node *curr=root;
    q.push(curr);
    while(!q.empty())
    {
        curr=q.front();
        cout<<curr->data<<" ";
        q.pop();
        if(curr->l)
            q.push(curr->l);
        if(curr->r)
            q.push(curr->r);
    }

}
//level order traversal in spiral way
//method 1 by 2 stack
void spiral_method_1(node *root)
{
    stack<node*>s1,s2;
    if(!root)
        return;
    s1.push(root);
    node *curr;
    while(s1.empty()==false || s2.empty()==false )
    {
        while(s1.empty()==false )
        {
            curr=s1.top();
            s1.pop();
            cout<<curr->data<<" ";
            if(curr->l)
                s2.push(curr->l);
            if(curr->r)
                s2.push(curr->r);
        }
        cout<<"\n";
        while(s2.empty()==false )
        {
            curr=s2.top();
            s2.pop();
             cout<<curr->data<<" ";
             if(curr->r)
                s1.push(curr->r);
            if(curr->l)
                s1.push(curr->l);


        }
          cout<<"\n";
    }
}
//method 2 by dequeue
void spiral_method_2(node *root)
{
    if(!root)
        return;
    deque<node*>q;
    q.push_back(NULL);
    q.push_front(root);
    node *curr;
    while(q.size()>1)
    {
        while(curr!=NULL)
        {
            curr=q.front();
             q.pop_front();
            cout<<curr->data<<" ";
            //adding left and right child at bottom of queue
            if(curr->l)
                q.push_back(curr->l);
            if(curr->r)
                q.push_back(curr->r);

        }
        curr=q.back();
        while(curr!=NULL)
        {
            curr=q.back();
            cout<<curr->data<<" ";
            q.pop_back();
            //adding right & left child at bottom of queue
            if(curr->r)
                q.push_front(curr->r);
            if(curr->l)
                q.push_front(curr->l);
        }

    }
}
//method 3 by dequeue and count
void spiral_method_3(node *root)
{
    ll levelcnt=0,currentcnt=0;
    node *curr;
    deque<node*>q;
    q.push_back(root);
    {
        curr=q.front();
        q.pop_front();
    }
}


//level order traversal line by line
void level_line_By_line(node *root)
{
    if(!root)
        return ;
    queue<node*>q;
    node *curr=root;
    q.push(curr);
    ll size_of_q;
    while(q.empty()==false)
    {
        size_of_q=q.size();
            while(size_of_q>0)
            {
                curr=q.front();
                cout<<curr->data<<" ";
                if(curr->l)
                    q.push(curr->l);
                if(curr->r)
                    q.push(curr->r);
                q.pop();
                //decreasing count
                size_of_q--;
            }
            cout<<endl;
    }
}
//Level order traversal with direction change after every two levels
//using one queue and one stack
void levelOrder_by_direction_change_for_every_2_level(node *root)
{
    if(!root)
        return ;
    queue<node*>q;
    stack<node*>s;
    ll cnt=2;

}
//reverse level order traversal
//by stack and queue
void reverse_Level_Oreder(node *root)
{
     if(!root)
        return;
    queue<node*>q;
    node *curr=root;
    q.push(curr);
    stack<ll>s;
    while(!q.empty())
    {
        curr=q.front();
        s.push(curr->data);
        q.pop();
        if(curr->r)
            q.push(curr->r);
        if(curr->l)
            q.push(curr->l);

    }
    while(s.empty()==false)
    {
        cout<<s.top()<<" ";
        s.pop();
    }

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
    cout<<endl;
   postOrder_by_2Stack(root);
}
