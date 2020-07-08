#include<bits/stdc++.h>
using namespace std;
class Qnode
{
    int data;

public:
      Qnode *next;
    Qnode(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    int getData()
    {
        return this->data;
    }
};
class Myqueue
{
    Qnode *f,*rear;
public:
    Myqueue()
    {
        f=NULL;
        rear=NULL;
    }
    void Myqueue_push(int d)
    {
        Qnode *tmp=new Qnode(d);
        if(f==NULL)
        {
            f=rear=tmp;
            return;
        }
        else
        {
            rear->next=tmp;
            rear=tmp;
        }
    }
    void Myqueue_pop()
    {
        if(f==NULL && rear==NULL)
            cout<<"\nEmpty";
        else
        {
            cout<<endl<<f->getData()<<"removed ";
            Qnode *tmp=f;
            delete tmp;
            f=f->next;
        }
    }
    void display()
    {
        Qnode *tmp=f;
        cout<<"\ndata:\n";
        while(tmp!=NULL)
        {
            cout<<tmp->getData()<<" ";
            tmp=tmp->next;
        }
    }
};
int main()
{
        Myqueue obj;
        obj.Myqueue_push(1);
        obj.Myqueue_push(2);
        obj.Myqueue_push(3);
        obj.Myqueue_push(4);
        obj.display();
        obj.Myqueue_pop();
        obj.display();
        obj.Myqueue_pop();
        obj.Myqueue_pop();
        obj.Myqueue_pop();
        obj.display();
}

