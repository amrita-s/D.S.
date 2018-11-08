#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
main()
{
    node *head, *tail;
    head=NULL;
    tail=NULL;
    int n,i,data1,u;
    char ans;
    cout<<"Enter no. of nodes:";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter data to store at "<<i<<" node:";
        cin>>data1;
        node *temp=new node;
        temp->data=data1;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=tail->next;
        }
    }
    //insert at all places multiple times
    u:
    int pos;
    cout<<"Enter position to insert:";
    cin>>pos;
    node *a=new node;
    cout<<"Enter data to insert:";
    cin>>a->data;
    node *p;
    p=head;
    if(pos==1)
    {
        a->next=head;
        head=a;
    }
    else if(pos>n+1)
    {
        cout<<endl<<"Error cannot insert!"<<endl;
    }
    else
    {
       for(i=1;i<pos-1;i++)
       {
           p=p->next;
       }
       a->next=p->next;
       p->next=a;
    }
    cout<<"Do you want to insert more elements y or n?";
    cin>>ans;
    if(ans=='y')
    {
        p=head;
        n=0;
        while(p!=NULL)
        {
            p=p->next;
            n=n+1;
        }
        goto u;
    }

    //printing
    node *ptr;
    ptr=head;
    cout<<"Final list is:"<<endl;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
