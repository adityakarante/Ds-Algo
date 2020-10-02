#include<stdio.h>
#include<stdlib.h>
#define M 5
struct queue
{
    int arr[M];
    int fr,rr;
}q;

void init()
{
    q.rr=-1;
    q.fr=0;
}

int isempty()
{
    return (q.rr<q.fr);
}

void insert(int d)
{
    if(q.rr==M-1)//q.fr==0;
    {
        printf("\nOverflow\n");
        return ;
    }
    else
    {
        q.rr++;
        q.arr[q.rr]=d;
    }
}

int removeque()
{
    return (q.arr[q.fr++]);
}

void display()
{
    int i;
    if(isempty())
    {
        printf("Empty queue");
        return ;
    }
    printf("Queue data");
    for(i=q.fr;i<=q.rr;i++)
        printf("%4d",q.arr[i]);
}

//max from the subarray of size k
/*#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int i;
        deque<int>q(k);
        for( i=0;i<k;i++)
        {
            while((!q.empty())&&a[i]>=a[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        for(;i<n;i++)
        {
            cout<<a[q.front()]<<" ";
            while(!q.empty()&&q.front()<=i-k)
            {
                q.pop_front();
            }
            while(!q.empty()&&a[i]>=a[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        cout<<a[q.front()]<<endl;
    }
    return 0;
}*/
void main()
{
    int opt,d;
    init();
    while(1)
    {
        printf("\nQueue data structure\n1.insert\n2.remove\n3.display\n4.exit\noption\n");

        scanf("%d",&opt);
        if(opt>3)
            break;

        switch(opt)
        {
            case 1:
                    printf("\nEnter Data");
                    scanf("%d",&d);
                    insert(d);
                    break;
            case 2:
                    if(isempty())
                        printf("\nUnderflow\n");
                    else
                        printf("data %d",removeque());
                    break;
            case 3:
                    display();
                    break;
        }



    }
}
