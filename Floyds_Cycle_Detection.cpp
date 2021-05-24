#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *t)
{
    for(int i=0;t!=NULL;i++){
        cout<<t->data<<" ";
        t=t->next;
        if(i==20) break;
    }
    cout<<endl;
}



node * floydsCycleDetection(struct node *head)
{
    int i,j,flag=0;

    struct node *tortoise,*hare;
    tortoise=head;
    hare=head;

    for(i=0; tortoise!=NULL && hare!=NULL;i++){
        tortoise=tortoise->next;
        if (hare->next==NULL) break;
        hare=hare->next->next;
        if(tortoise==hare) {flag=1; break;}
    }
    if(flag==0) return NULL;

    cout<<"Number of Iteration to confirm existing loop: "<<i+1<<endl;

    hare=head;
    for(j=0;tortoise!=hare;j++){
        tortoise=tortoise->next;
        hare=hare->next;
    }

    cout<<"Distance from head to starting loop node: "<<j<<endl;

    return hare;
}


int main()
{
    struct node *head,*t,*new_node,*l;
    
  
    // create a graph for your choice. I created a graph with cycle with the code from line (58-71). Any linked list graph will work
    int n,value;
    cout<<"Number of Nodes: "; cin>>n;
    cout<<"Enter the Node values: ";

    for(int i=0;i<n;i++){
        new_node=(struct node*)malloc(sizeof(struct node));
        cin>>new_node->data;
        new_node->next=NULL;

        if(i==0) {head=new_node; t=head;}
        else {t->next=new_node; t=t->next;}
        if(i==4) l=t;  // saved the node i wanted to start the cycle from. any node will work
    }
    t->next=l; // simply pointed the last node towards the saved node to create a cycle
    
    traverse(head);

    struct node *scycle=floydsCycleDetection(head);

    cout<<"Starting node of the cycle: "<<scycle->data;

    return 0;
}
