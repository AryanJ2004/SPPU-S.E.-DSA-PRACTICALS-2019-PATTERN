#include<iostream>
using namespace std;


#define true 1
#define false 0
#define max 100
class node
{
public: //access specifier

int data,top,visit;//data members
node *left,*right;
node *root;
node()
{
    root=NULL;
    
}
node * create(node *root);
void insert(node *root,node *temp);
void dispmenu(node *root);

void recdispvlr(node *root);
void recdisplvr(node *root);
void recdisplrv(node *root);

void nonrecvlr(node *root);
void nonreclvr(node *root);

void nonreclrv(node *root);
void levelwisedisp(node *root);
int height(node* root);
int height(){return height(root);}
};

node * node::create(node *root)
{
node *temp;
char c;
do
{

temp=new node;
temp->left=NULL;
temp->right=NULL;
temp->visit=false;
cout<<"\nEnter the data : ";
cin>>temp->data;
if(root==NULL)
root=temp;
else
insert(root,temp);
cout<<"\n\n want to enter more nodes(y/n)";
cin>>c;
}while(c=='Y' || c=='y');

return root;
}

void node::insert(node *root,node *temp)
{
char ch;
cout<<"Insert data to left(l) or right(r) of "<<root->data;

cin>>ch;
if(ch=='l'||ch=='L')
{
if(root->left==NULL)
{
root->left=temp;
}
else
insert(root->left,temp);
}
if(ch=='r'||ch=='R')
{
if(root->right==NULL)
{
root->right=temp;

}
else
insert(root->right,temp);
}
}

void node::dispmenu(node *root)//vlr
{
    int ch;
    char ans;
    node *stack[100];
    do
    {
    cout<<"display binary tree \n\n1:RECURSIVE PREORDER\n2:RECURSIVE INORDER\n3:RECURSIVEPOSTORDER\n";
    cout<<"4:NON-RECURSIVE PREORDER\n5:NON-RECURSIVE INORDER\n6:NON-RECURSIVEPOSTORDER\n";
    cin>>ch;
    switch(ch)
    {
    case 1:
    cout<<"RECURCIVE PREORDER (VLR) TRAVERSEL\n";
    recdispvlr(root);
    break;
    case 2:

cout<<"RECURCIVE INORDER (LVR) TRAVERSEL\n";
recdisplvr(root);
break;
case 3:

cout<<"RECURCIVE POSTORDER (LRV) TRAVERSEL\n";

recdisplrv(root);
break;
case 4:
cout<<"NON-RECURCIVE PREORDER (VLR) TRAVERSEL\n";
nonrecvlr(root);
break;
case 5:
cout<<"NON-RECURCIVE INORDER (LVR) TRAVERSEL\n";
nonreclvr(root);
break;
case 6:
cout<<"NON-RECURCIVE POSTORDER (LRV) TRAVERSEL\n";
nonreclrv(root);
break;

default:
cout<<"invalid choice\n";

}
cout<<"\n\nDO U WANT TO CONTINUE DISPLAYING TREE.?(y/n)";

cin>>ans;
}while(ans=='y'||ans=='Y');
}

void node::recdispvlr(node *root)
{
if(root)
{ cout<<"\t"<<root->data;
recdispvlr(root->left);
recdispvlr(root->right);

}
}

void node::recdisplvr(node *root)
{
if(root)
{
recdisplvr(root->left);
cout<<"\t"<<root->data;
recdisplvr(root->right);
}
}

void node::recdisplrv(node *root)
{

if(root)
{

recdisplrv(root->left);
recdisplrv(root->right);
cout<<"\t"<<root->data;

}
}
void node::nonrecvlr(node *root)
{
node *stack[100],*temp;
int top=-1;
temp=root;
while(1)
{
while(temp)
{
top++;
stack[top]=temp;
cout<<temp->data<<"\n";
temp=temp->left;
}
if(top!=-1)
{
temp=stack[top];

top--;
// cout<<temp->data;
temp=temp->right;
}
else break;
}

}
void node::nonreclvr(node *root)
{
node *stack[100],*temp;
int top=-1;
temp=root;

while(1)
{
while(temp)
{
top++;
stack[top]=temp;
temp=temp->left;
}
if(top!=-1)
{
temp=stack[top];

top--;
cout<<temp->data;
temp=temp->right;
}
else break;
}
}

void node::nonreclrv(node *root)
{
node *stack[100],*temp;
int top=-1;
temp=root;

// node *oldTemp;

top++;
stack[top]=temp; //push root on stack first

while(top!=-1) //stack is not empty
{
if(temp->left!=NULL && temp->left->visit==false) //if left not null and not visite
{

//1. push left

//2. make left as current
top++;
stack[top]=temp->left; //push(temp->left);
temp=temp->left;

}

// if right is not null and not visited then push it and go to right

else if((temp->right!=NULL) && (temp->right->visit==false))
{
//1.push right
//2. make right as current

top++;
stack[top]=temp->right; // push(temp->right);
temp=temp->right;
}

//if node is last node i.e no right and left child or its both childeens are visited

if((temp->right==NULL && temp->left==NULL) ||((temp->right->visit==true)||(temp->left->visit==true)))

{

temp=stack[top]; // temp=pop();
top--;

cout<<"\t"<<temp->data;
temp->visit=true;
// pop again to point next element

temp=stack[top]; //temp=pop();
}

} //end of while

// } //while true

} // end of fun
void node::levelwisedisp(node *root)
{
node *que[max];
int front=-1;
int rear=-1;
node *temp=root;
front++;
rear++;
que[rear]=temp;
while(front<=rear)
{
temp=que[front];
if(temp!=NULL)
{
cout<<"\t"<<temp->data;
front++;
if(temp->left!=NULL)
que[++rear]=temp->left;
if(temp->right!=NULL)
que[++rear]=temp->right;
}
}
}
int node::height(node *root)
{
int l=0;
int r=0;
//node *temp=root;
//int count=0;
if(root==NULL)
{
 return 0;
}
l=height(root->left);
r=height(root->right);
if(l>r)
return l+1;
else
return r+1;
//cout<<"Height Of Tree Is:"<<count<<endl;
//return 0;
}
int main()
{
int i,ch;
char c,ans;

node p1;
do
{
cout<<"1:Create binary tree \n2:DISPLAY \n3:LEVELWISE DISPLAY\n4.HEIGHT OF TREE\n5.EXIT ";
cin>>ch;
switch(ch)
{
case 1:
// c='Y';
p1.root=p1.create(p1.root);
break;
case 2:
p1.dispmenu(p1.root);
break;
case 4:
cout<<"Height Of Tree Is:";
cout<<p1.height();
break;
case 5:

default:
cout<<"invalid choice\n";
case 3:
p1.levelwisedisp(p1.root);
} // switch
cout<<"\nWant To Continue Operations?(y/n)";
cin>>ans;
}while(ans=='y'||ans=='Y'); //do
return 0;

} //main
