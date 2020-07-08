#include<bits/stdc++.h>
using namespace std;
#define ll long long
//main class
class node
{
public:
    ll data;
    node *l;
    node *r;
};

//to create node
node *createNode(int d)
{
    node *tmp=new node();
    tmp->l=NULL;
    tmp->r=NULL;
    tmp->data=d;
    return tmp;
}

//to insert
void insert(node **rt,int d)
{
    node *tp=*rt;
    if(*rt==NULL)
    {
      //  cout<<endl<<"root"<<d;
        *rt=createNode(d);
        return;
    }
    queue<node*>q;
    q.push(tp);
    while(!q.empty())
    {
        tp=q.front();
        q.pop();
        if(tp->l==NULL)
        {
          //  cout<<endl<<"left of: "<<tp->data<<" "<<d;
            tp->l=createNode(d);
            break;
        }
        else
            q.push(tp->l);
        if(tp->r==NULL)
        {
          //  cout<<endl<<"right of: "<<tp->data<<" "<<d;
            tp->r=createNode(d);
            break;
        }
        else
            q.push(tp->r);
    }
}
//________________________________________all inorder_____________________________________________
//recursion
void normalInorder(node *rt)
{
    if(rt)
    {
        normalInorder(rt->l);
        cout<<rt->data<<" ";
        normalInorder(rt->r);
    }
}
void stack_Inorder(node *rt)
{
    if(!rt)
        return;
    node *tp=rt;
    stack<node*>s;
    while(tp!=NULL || s.empty()==false)
    {
        //if left exist then go to left
        while(tp!=NULL)
        {
            s.push(tp);
            tp=tp->l;
        }

        tp=s.top();
        s.pop();
        cout<<tp->data<<" ";
        //go to right and repeat same process
        tp=tp->r;
    }
}
void morrisInorder(node *rt)
{
    if(!rt)
        return;
    node *curr=rt;
    node *pre;
    while(curr!=NULL)
    {
        if(curr->l==NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->r;
        }
        else//left not null
        {
            pre=curr->l;
            while(pre->r!=NULL && pre->r!=curr)
            {
                pre=pre->r;
            }
            if(pre->r==NULL)
            {
                pre->r=curr;
                curr=curr->l;
            }
            else
            {
                pre->r=NULL;
                cout<<curr->data<<" ";
                curr=curr->r;
            }
        }
    }
}

//_______________________________preorde traversal__________________
void normal_Preorder(node *rt)
{
    if(rt)
    {
        cout<<rt->data<<" ";
        normal_Preorder(rt->l);
        normal_Preorder(rt->r);
    }
}
void stack_Preorder(node *rt)
{
    if(!rt)
        return;
    node *curr=rt;
    stack<node*>s;
    while(curr!=NULL || s.empty()==false )
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

//_______________________postOrder_______________________
void stack_PostOrder(node *rt)//????????????????????????????????????????????
{
    if(rt==NULL)
        return;
    stack<node*>s;
    s.push(rt);
    node *curr=rt;
    while(curr!=NULL || s.empty()==false)
    {


    }
}
void normal_PostOrder(node *rt)
{
    if(rt)
    {
        normal_PostOrder(rt->l);
        normal_PostOrder(rt->r);
        cout<<rt->data<<" ";
    }
}
//find max element
int max_Element(node *rt)
{
    int Max=INT_MIN;
    if(!rt)
        return Max;
    if(!rt->l && !rt->r)
        return rt->data;
    int ldata=max_Element(rt->l);
    int rdata=max_Element(rt->r);
    //finding max from left and right
    if(ldata>rdata)
        Max=ldata;
    else
        Max=rdata;

    //checking max with current node
    if(Max<rt->data)
        Max=rt->data;
    return Max;
}
//find max without Recursion
int max_Element_No_Recursion(node *rt)
{
    int Max=INT_MIN;
    if(!rt)
        return Max;
    int ldata,rdata;
    queue<node*>q;
    node *curr=rt;
    q.push(rt);
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        if(curr->l)
        {
            ldata=curr->l->data;
            q.push(curr->l);
        }
        if(curr->r)
        {
            rdata=curr->l->data;
            q.push(curr->r);
        }
        //find max from left and right
        if(ldata > rdata)
            Max=ldata;
        else
            Max=rdata;
        //compare with root
        if(curr->data > Max)
            Max=curr->data;


    }
    return Max;

}
//search Element
bool searchElement(node *rt,ll d)
{
    if(!rt)
        return false;
    bool ans=false;
    queue<node*>q;
    node *curr=rt;
    q.push(rt);
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        if(curr->data==d)
        {
            ans=true;
            break;
        }
        if(curr->l)
            q.push(curr->l);
        if(curr->r)
            q.push(curr->r);
    }
    return ans;

}
//Size of binary tree(total no of nodes present inside binary tree)
//Size with recursion
int tree_Size(node *rt)
{
    //if null return 0
    if(!rt)
        return 0;
    //if exist
    return 1+tree_Size(rt->l)+tree_Size(rt->r);
}
//size of  tree without recursion
int tree_Size_No_Resursion(node *rt)
{
    int cnt=0;
    if(!rt)
        return cnt;
    queue<node*>q;
    node *curr=rt;
    q.push(rt);
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        cnt++;
        if(curr->l)
            q.push(curr->l);
        if(curr->r)
            q.push(curr->r);
    }
    return cnt;
}
//reverse level Order traversal
//use stack
//push root then right  & then left
void level_Order_Reverse(node *rt)
{
    if(!rt)
        return;
    queue<node*>q;
    node *curr=rt;
    q.push(rt);
    stack<node*>s;
    s.push(curr);//pushing root
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        if(curr->r)
        {
            s.push(curr->r);
            q.push(curr->r);
        }
        if(curr->l)
        {
            s.push(curr->l);
            q.push(curr->l);
        }


    }
    cout<<"\nReverse Level Order Traversal: ";
    while(s.empty()==false)
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
}
//delete tree
void delete_all(node *rt)
{
    if(rt)
    {
        delete_all(rt->l);
        delete_all(rt->r);
        delete rt;//delete node
    }
}
void delete_Tree(node **rt)
{
    delete_all(*rt);
    *rt=NULL;//assign null to root
}
//Height of Binary Tree
ll height_Of_Tree(node *rt)
{
    if(rt==NULL)
        return 0;
    ll lheight=height_Of_Tree(rt->l);
    ll rheight=height_Of_Tree(rt->r);
    if(lheight > rheight)
        return 1+lheight;
    return 1+rheight;
}
//height with no recursion
ll height_No_Recursion(node *rt)
{
    ll height=0;
    if(!rt)
        return height;
    queue<node*>q;
    q.push(rt);
    node *tmp;
    ll sizeof_queue;
    while(!q.empty())
    {
        //store size of queue(no of nodes at level)
        sizeof_queue=q.size();
        while(sizeof_queue>0)
        {
            tmp=q.front();
            q.pop();
            if(tmp->l)
                q.push(tmp->l);
            if(tmp->r)
                q.push(tmp->r);
            sizeof_queue--;
        }
        height++;
    }
    return height;
}
//find deepest node in tree
void deep_Node(node *rt)
{
    if(!rt)
        return ;
    queue<node*>q;
    q.push(rt);
    node *tmp;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(tmp->l)
            q.push(tmp->l);
        if(tmp->r)
            q.push(tmp->r);
    }
    //deepest node is last node in level Order traversal
    cout<<endl<<"Deep node: "<<tmp->data;
}
//Delete node in binary tree ??????????????
void delete_Node()
{


}
//Count of full nodes without recursion
//The set of all nodes with both left and right children are called full nodes.
ll count_Of_Full_Nodes(node *rt)
{
    ll cnt=0;
    if(!rt)
        return cnt;
    queue<node*>q;
    node *curr=rt;
    q.push(rt);
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        if(curr->l)
            q.push(curr->l);
        if(curr->r)
        {
            q.push(curr->r);
            //as right satisfy we have to check only left again
            if(curr->l)
                cnt++;
        }
    }
    return cnt++;
}
//Count of Half nodes without recursion
//The set of all nodes with either left or right children but not both are called Half nodes
ll count_Of_Half_Nodes(node *rt)
{
    ll cnt=0;
    if(!rt)
        return cnt;
    queue<node*>q;
    node *curr=rt;
    q.push(rt);
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        if(curr->l)
        {
            q.push(curr->l);
            if(!curr->r)//if not right
                cnt++;
        }
        if(curr->r)
        {
            q.push(curr->r);
            if(!curr->l)//if no left child
                cnt++;
        }
    }
    return cnt;
}
//Check whether 2 trees have identical structure
bool check_2_Identical(node *f,node *s)
{
    if(!f && !s)
        return true;
    if(!f || !s)
        return false;
    return( (f->data==s->data) &&check_2_Identical(f->l,s->r) && check_2_Identical(f->r,s->l));

}
//Diameter of Binary tree
ll Max_data(ll a,ll b)
{
    return a>b ? a:b;
}

ll diameter_Of_Tree(node *rt)
{
    if(!rt)
        return 0;
    ll l_height=height_Of_Tree(rt->l);
    ll r_height=height_Of_Tree(rt->r);
    //Some time diameter of  binary tree does not pass through root
    return Max_data(
                        l_height+r_height+1/*diameter through root*/  ,
                        Max_data(diameter_Of_Tree(rt->l),diameter_Of_Tree(rt->r))//max from diameter of left and right
                );
}

//Find Level that has max sum in binary tree
ll level_That_Has_Max_Sum(node *rt)
{
    if(!rt)//if no tree exist
        return -1;
    ll sum_that_level=0;//to calculate sum at particular level
    ll level=1;//to keep track of levels
    ll ans=0;//ans
    ll max_sum=INT_MIN;
    ll no_node_at_level=0;//to calculate nodes at that level
    node *curr=NULL;
    queue<node*>q;
    q.push(rt);
    while(!q.empty())
    {
        no_node_at_level=q.size();
        sum_that_level=0;
        while(no_node_at_level--)
        {
            curr=q.front();
            sum_that_level+=curr->data;
            q.pop();
            if(curr->l)
                q.push(curr->l);
            if(curr->r)
                q.push(curr->r);
        }
        if(sum_that_level>max_sum)
        {
            max_sum=sum_that_level;
            ans=level;
        }
        level++;

    }
    //cout<<"max sum level: "<<ans;
    return ans;
}

//print all root-leaf paths  ??????????????????????????????????????????????????????????
void printVector(vector<ll>&v)
{
    cout<<endl;
    ll len=v.size();
    for(ll i=0;i<len;i++)
        cout<<"[ "<<v[i]<<" ]=>";
    cout<<"[ NULL ]";

    //removing that node
    v.pop_back();

}
void print_Path(node *rt,vector<ll>&v)
{
    if(rt==NULL)
        return;
    //while visiting 1st push node in vector
    v.push_back(rt->data);
    //if leaf node then print path upto this
    if(!rt->l && !rt->r)
        printVector(v);
    else
    {
        print_Path(rt->l,v);
        print_Path(rt->r,v);
    }

}
//Sum of all elements in tree
ll sum_Of_All(node *rt)
{
    if(!rt)
        return 0;
    if(!rt->l && !rt->r)//if leaf return data
        return rt->data;
    return rt->data+sum_Of_All(rt->l)+sum_Of_All(rt->r);
}
//sum with no recursion
ll sum_Of_All_No_Recursion(node *rt)
{
    ll sum=0;
    if(!rt)
        return sum;
    queue<node*>q;
    q.push(rt);
    node *curr=NULL;
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        sum+=curr->data;
        if(curr->l)
            q.push(curr->l);
        if(curr->r)
            q.push(curr->r);

    }
    return sum;

}
//Convert given tree into its mirror
//Mirror of a tree is another tree with left and right children of all non-leaf nodes interchanged.
node* make_Mirror(node *rt)
{

    if(rt)
    {
        make_Mirror(rt->l);
        make_Mirror(rt->r);
        node *tp=rt->l;
        rt->l=rt->r;
        rt->r=tp;
    }
    return rt;
}
//print Ancenstor of given node
bool print_Ancenstor(node *rt,ll key)
{
    if(rt==NULL)
        return false;
    if(rt->data==key)
    {
        cout<<rt->data<<" ";
        return true;
    }
    if(print_Ancenstor(rt->l,key) || print_Ancenstor(rt->r,key) )
    {
         cout<<rt->data<<" ";
        return true;
    }
    return false;

}

//top view of tree
/*
step 1 :
    calculate horizontal distance for each node and create map of it
    map=> [ node | horizontal_distance ]
step 2:
    do level order traversal and go level by level
    create map =>[horizontal_distance | value_of_node ]
    if data all ready present inside map do not update
    if not present then insert
*/
//function to calculate horizontal distance
void calHorizontalDistance(node *rt,int hd,map<node*,int>&m)
{
    if(rt==NULL)
        return ;
    m[rt]=hd;
    calHorizontalDistance(rt->l,hd-1,m);
    calHorizontalDistance(rt->r,hd+1,m);
}
void topView(node* rt)
{
    if(!rt)
        return;
    map<node*,int>node__to_hod;
    calHorizontalDistance(rt,0,node__to_hod);

    map<int,int>hod_to_val;
    queue<node*>q;
    node *curr;
    int horizontal_distance;
    int no_nodes_at_level=0;
    q.push(rt);
    while(q.empty()==false)
    {
        no_nodes_at_level=q.size();
        for(int i=0;i<no_nodes_at_level;i++)
        {
            curr=q.front();
            q.pop();
            horizontal_distance=node__to_hod[curr];
            if(hod_to_val[horizontal_distance]==0)
            {
                hod_to_val[horizontal_distance]=curr->data;
            }
            if(curr->l)
                q.push(curr->l);
            if(curr->r)
                q.push(curr->r);
        }
    }

     //printing top view
     map<int,int>::iterator it=hod_to_val.begin();
     for(;it!=hod_to_val.end();++it)
     {
         cout<<it->second<<" ";
     }


}
//Bottom view
/*
step 1 :
    calculate horizontal distance for each node and create map of it
    map=> [ node | horizontal_distance ]
step 2:
    do level order traversal and go level by level
    create map =>[horizontal_distance | value_of_node ]
    if data all ready present inside map  update
    if not present then insert
*/
//function to calculate horizontal distance
void bottomView(node* rt)
{
    if(!rt)
        return;
    map<node*,int>node__to_hod;

    //to calculate horizontal distance use function at top view
    calHorizontalDistance(rt,0,node__to_hod);

    map<int,int>hod_to_val;
    queue<node*>q;
    node *curr;
    int horizontal_distance;
    int no_nodes_at_level=0;
    q.push(rt);
    map<int,int>::iterator it;
    while(q.empty()==false)
    {
        no_nodes_at_level=q.size();
        for(int i=0;i<no_nodes_at_level;i++)
        {
            curr=q.front();
            q.pop();
            horizontal_distance=node__to_hod[curr];

            //if not present then insert if present then update
            hod_to_val[horizontal_distance]=curr->data;


            if(curr->l)
                q.push(curr->l);
            if(curr->r)
                q.push(curr->r);
        }
    }

     //printing top view
     it=hod_to_val.begin();
     for(;it!=hod_to_val.end();++it)
     {
         cout<<it->second<<" ";
     }


}
//Vertical traversal of tree
/*
step 1 :
    calculate horizontal distance for each node and create map of it
    map=> [ node | horizontal_distance ]
step 2:
    do level order traversal and go level by level
    create map =>[horizontal_distance | list of nodes with horizontal distance ]
*/
void verticalTraversal(node *rt)
{
    if(!rt)
        return;
    map<node*,int>node__to_hod;

    //to calculate horizontal distance use function at top view
    calHorizontalDistance(rt,0,node__to_hod);

    //declare horizontal distance and list of nodes
    map<int,list<int> >hod_to_list;
    queue<node*>q;
    node *curr;
    int horizontal_distance;
    int no_nodes_at_level=0;
    q.push(rt);

    while(q.empty()==false)
    {
        no_nodes_at_level=q.size();
        for(int i=0;i<no_nodes_at_level;i++)
        {
            curr=q.front();
            q.pop();
            horizontal_distance=node__to_hod[curr];

            //insert node inside map
            hod_to_list[horizontal_distance].push_back(curr->data);

            if(curr->l)
                q.push(curr->l);
            if(curr->r)
                q.push(curr->r);
        }
    }

     map<int,list<int> >::iterator it;
     cout<<"\nVertical Traversal\n";
     for(it=hod_to_list.begin();it!=hod_to_list.end();++it)
     {
            for(list<int>::iterator lit=hod_to_list[it->first].begin();lit!=hod_to_list[it->first].end();++lit)
            {
                cout<<*lit<<" ";
            }
            cout<<endl;
     }

}
int main()
{
    system("color B0");
    ll t,n;
    cin>>t;
    node *rt=NULL;
    while(t--)
    {
        cin>>n;
        insert(&rt,n);
    }
    cout<<endl;
    normalInorder(rt);
    //cin>>n;
    cout<<endl;
   verticalTraversal(rt);




}
