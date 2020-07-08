#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
1)Inorder traversal on binary search tree give sorted list

*/
//main class
class bstnode
{
public:
    ll data;
    bstnode *l;
    bstnode *r;
};
//to create node
bstnode *createNode(int d)
{
    bstnode *tmp=new bstnode();
    tmp->l=NULL;
    tmp->r=NULL;
    tmp->data=d;
    return tmp;
}
//insertion
bstnode* b_search_tree_insertion(bstnode *rt,ll key)
{
    if(rt==NULL)
    {
        rt=createNode(key);
    }
    if(rt->data  > key)
    {

        rt->l=b_search_tree_insertion(rt->l,key);
        //cout<<endl<<rt->data<<" left-child: "<<rt->l->data<<endl;
    }
    if(rt->data < key)
    {
        rt->r=b_search_tree_insertion(rt->r,key);
        //cout<<endl<<rt->data<<" right-child: "<<rt->r->data<<endl;
    }
    return rt;

}
//_______________________________________Deletion__________________________________

bstnode* b_search_tree_deletion(bstnode *rt,ll key)
{
    if(rt==NULL)
    {
        cout<<"\nNo elements present inside tree";
    }
    else if(key < rt->data)
    {
        rt->l=b_search_tree_deletion(rt->l,key);
    }
    else if(key >  rt->data)
    {
        rt->r=b_search_tree_deletion(rt->r,key);
    }
    else
    {//found

        if(rt->l && rt->r)
        {
            bstnode* left_rightmost=rt->l;
            //finding rightmost child on left subtree( largest in left sub tree)
            while(left_rightmost->r!=NULL)
                left_rightmost=left_rightmost->r;
            //assign value to current node
             rt->data=left_rightmost->data;

             //delete largest left subtree
             rt->l=b_search_tree_deletion(rt->l,rt->data);

        }
        else//if only one child
        {
                bstnode *tp=rt;
                if(rt->l==NULL)//if only right child
                    rt=rt->r;
                if(rt->r==NULL)//if only left child
                    rt=rt->l;
                delete tp;
        }

    }
    return rt;

}
//___________________________________________Inorder_____________________________
void b_search_tree_inorder(bstnode *rt)
{
    if(rt)
    {
        b_search_tree_inorder(rt->l);
        cout<<rt->data<<" ";
        b_search_tree_inorder(rt->r);
    }
}


ll b_search_tree_Max(bstnode *rt)
{
    if(rt==NULL)
        return INT_MIN;
    if(rt->r==NULL)
        return rt->data;
    return b_search_tree_Max(rt->r);
/*
Time Complexity: O(n), in worst case (when BST is a right skew tree).
Space Complexity: O(n), for recursive stack.
*/
}
ll b_search_tree_Max_non_recursive(bstnode *rt)
{
    if(rt==NULL)
        return INT_MIN;
    bstnode *curr=rt;
    while(curr->r!=NULL)
    {
        curr=curr->r;
    }
    //return rightmost node in binary search tree
    return curr->data;

/*
Time Complexity: O(n). //if skew worst case
Space Complexity: O(1).
*/
}



int main()
{
    system("color B0");
    ll t,n;
    cin>>t;
    bstnode *rt=NULL;
    while(t--)
    {
        cin>>n;
        rt=b_search_tree_insertion(rt,n);

    }
    cout<<endl;
    b_search_tree_inorder(rt);

    cout<<endl<<endl<<"Root data: "<<rt->data;

}



