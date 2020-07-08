 #include<bits/stdc++.h>
#include "twolist.h"
/*
classlocation.h -> ins.h ->display.h->deletion.h->other.h-> ->twolist.h
*/
typedef long long ll;
using namespace std;
int main()
{
    system("color B0");
    NODE *head=NULL;
    NODE *h1=NULL,*h2=NULL;
    //init(&head);
    ll  opt,d;
    while(1)
    {
        cout<<"\n1:INSERTION\n2:DELETION\n3:DISPLAY & SORT\n4:OTHER\n5:2list operations\n0:EXIT\nOPTION:\n";
        cin>>opt;
        if(opt==0)
            break;
        switch(opt)
        {
            case 1:
                insertion(&head);
                break;
            case 2:
                deletion(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                other(&head);
                break;
            case 5:
                cout<<"\nEnter count of data for 1st list";
                cin>>opt;
                cout<<"\nEnter data: ";
                while(opt--)
                {
                    cin>>d;
                    addEnd(&h1,d);

                }
                cout<<"\nEnter count of data for 2nd list";
                cin>>opt;
                cout<<"\nEnter data: ";
                while(opt--)
                {
                    cin>>d;
                    addEnd(&h2,d);

                }
                twolist(&h1,&h2);
                break;


        }
    }
}
