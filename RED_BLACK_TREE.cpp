//RED-BLACK TREE
/*

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class node
{
public:
    ll data;
    node *l; //left child
    node *r; //right child
    ll ht;   //height

}

//function to get height
ll
getHeight(node *h)
{
    if (h == NULL)
        return 0;
    return h->ht;
}

//function to create Node
node *createNode(int data)
{
    node *tmp = new node();
    tmp->data = data;
    tmp->height = 1;
    tmp->l = tmp->r = NULL;
    return tmp;
}

//function to get balance factor
ll getBalancefactor(node *nd)
{
    if (!nd)
        return 0;
    return (getHeight(nd->l) - getHeight(nd->r));
}

//function to insertion
node *insertion(node *nd, ll key)
{
    if (nd == NULL)
        return createNode(key);

    if (key < nd->data)
        nd->left = insertion(nd->left, key);
    else if (key > nd->data)
        nd->right = insertion(nd->right, key);
    else
        return nd;

    nd->ht = 1 + std::max(getHeight(nd->l), getHeight(nd->r));
}
int main()
{
}