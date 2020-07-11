#include <bits/stdc++.h>
using namespace std;
//wrong implementation
typedef long long ll;
class Cqueue
{
public:
    ll f, r, size;
    ll *a;
};
//functio to initalize
void init(Cqueue *q, ll n)
{
    q->f = q->r = -1;
    q->size = n;
    q->a = new ll[n];
}
bool isEmpty(Cqueue *q)
{
    if (q->size == 0)
        return true;
    return false;
}
bool isFull(Cqueue *q)
{
    if (q->r == q->size)
        return true;
    return false;
}
void inQueue(Cqueue *q, ll d)
{
    if ((q->f == 0 && q->r == q->size - 1) || (q->r == q->f % q->size - 1))
        cout << "Queue is full";
    else if (q->f == -1) //if first element
    {
        q->f = q->r = 0;
        q->a[q->r] = d;
        cout<<"\n1:added: "<<d<<" at index "<<q->r;
    }
    else if (q->r = q->size-1 && q->f != 0)
    {
        q->r = 0;
        q->a[q->r] = d;
        cout << "\n2:added: " << d << " at index " << q->r;
    }
    else
    {
        int index=q->r;
        index++;
        (q->r)+=1;
        q->a[index] = d;
        cout << "\n3:added: " << d << " at index " << q->r<<" "<<index;
    }
}
ll deQueue(Cqueue *q)
{
    if (q->f == -1)
    {
        cout << "Queue is empty";
        return INT_MIN;
    }
    ll data = q->a[q->f];
    q->a[q->f] = -1; //set to -1
    if (q->f == q->r)
    {
        q->f = q->r = -1;
    }
    else if (q->f == q->size - 1)
    {
        q->f = 0;
    }
    else
    {
        q->f++;
    }
    return data;
}
void display(Cqueue *q)
{
    if (q->f == -1)
    {
        cout << "Empty Queue";
    }
    cout << "\nDATA:\n";
    if (q->f <= q->r)
    {
        cout<<endl<<q->f<<" "<<q->r<<endl;
        for (int i = q->f; i<=q->r; ++i)
            cout << i<<" "<<q->a[i] << "\n";
    }
    else
    {
        for (int i = q->f; i < q->size; i++)
            cout << q->a[i];
        for (int i = 0; i <= q->r; i++)
            cout << q->a[i];
    }
}
int main()
{
    Cqueue q;
    Cqueue *ptr = &q;
    ll no = 5; //size of queue is 5
    init(ptr, no);
    //add 1 2 3 4 5
    inQueue(&q, 1);
    inQueue(&q, 2);
    inQueue(&q, 3);
    inQueue(&q, 4);
    inQueue(&q, 5);
    //queue => 1 2 3 4 5
    display(&q);

    deQueue(&q);
    deQueue(&q);
    //queue=> | | | 3| 4| 5|

    inQueue(&q, 6);
    inQueue(&q, 7);
    //            f        r
    //Queue=> |6 |7 | 3| 4| 5|

    display(ptr);
}
