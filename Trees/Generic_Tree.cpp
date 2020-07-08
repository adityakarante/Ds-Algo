#include<bits/stdc++.h>
using namespace std;
#define ll long long
class genericnode
{
public:
    ll data;
    genericnode *firstchild;
    genericnode *nextSibling;
};

//sum of all nodes
ll sum_Of_All(genericnode *rt)
{
    if(!rt)
        return 0;
    return rt->data+sum_Of_All(rt->firstchild)+sum_Of_All(rt->nextSibling);
}
int main()
{

}
