//all problems of karumanchi and solutions

#include<bits/stdc++.h>
using namespace std;
#define ll long long


//____________________________Problems and Solutions________________________
//Q 11 given queue of integer and count k reverse first k
void question11(queue<ll>&q,ll k)
{
    if(q.size()==0 || k>q.size())//if q is empty or k more than queue size
        return ;
    else if(k>0)
    {
        stack<ll>s;
        for(ll i=0;i<k;i++)
        {
            s.push(q.front());
            q.pop();
        }
        while(s.empty()==false)
        {
            q.push(s.top());
            s.pop();
        }
        for(ll i=0;i<q.size()-k;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
}
//Q9 Given a stack of integers, how do you check whether each successive pair of numbers in the stack is consecutive or not










void display(queue<ll>q)
{
    cout<<endl;
    while(q.empty()==false)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main()
{
        queue<ll>q;
        ll t,n;
        cin>>t;
        while(t--)
        {
            cin>>n;
            q.push(n);
        }
        display(q);
        cout<<"\n\nEnter no: ";
        cin>>n;
        question11(q,n);
        display(q);

}
