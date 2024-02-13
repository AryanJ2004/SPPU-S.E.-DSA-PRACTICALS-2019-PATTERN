//============================================================================
// Name        : binary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define true 1
#define false 0

class node
{
public:
	int data,top,visit;
	node *left,*right;
	node *create(node *root);
	void insert(node *root,node *temp);
	void dispmenu(node *root);
	void recdispvlr(node *root);
	void recdisplvr(node *root);
	void recdisplrv(node *root);
	void nonrecdispvlr(node *root);
	void nonrecdisplvr(node *root);
	void nonrecdisplrv(node *root);
};

node *node::create(node *root)
{
	node *temp;
	char c;
	do
	{
		temp=new node;
		temp->left=NULL;
		temp->right=NULL;
		temp->visit=false;
		cout<<"Enter Data:"<<endl;
		cin>>temp->data;
		if(root==NULL)
		{
			root=temp;
		}
		else
		insert(root,temp);
		cout<<"Do You Want To Insert More Node(Y/N)"<<endl;
		cin>>c;
	}while(c=='y'||c=='Y');
	return root;
}

void node::insert(node *root,node *temp)
{
	char ch;
	cout<<"Insert Data To Left(l) Or Right(r) Of"<<root->data;
	cin>>ch;
	if(ch=='l' ||ch=='L')
	{
		if(root->left==NULL)
			root->left=temp;
		else
			insert(root->left,temp);
	}
	if(ch=='r'||ch=='R')
	{
		if(root->right==NULL)
			root->right=temp;
		else
			insert(root->right,temp);
	}

}

void node::dispmenu(node *root)
{
	int ch;
	char ans;
	node *stack[100];
	do
	{
		cout<<"Display Binary Tree\n\n1.Recursive Preorder\n2.Recursive Inorder\n3.Recursive Postorder\n";
		cout<<"4.Non-recursive Preorder\n5.Non-recursive Inorder\n6.Non-recursive Postorder\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Recursive Preorder (VLR) Traversal\n";
			recdispvlr(root);
			break;
		case 2:
			cout<<"Recursive Inorder LVR Traversal\n";
			recdisplvr(root);
			break;
		case 3:
			cout<<"Recursive Postorder LRV Traversal\n";
			recdisplrv(root);
			break;
		case 4:
			cout<<"Non-Recursive Preorder (VLR) Traversal\n";
			nonrecdispvlr(root);
			break;

		case 5:
			cout<<"Non-Recursive Inorder LVR Traversal\n";
			nonrecdisplvr(root);
			break;
		case 6:
			cout<<"Non-Recursive Postorder LRV Traversal\n";
			nonrecdisplrv(root);
			break;
		default:
			cout<<"Invalid Choice\n";
		}
		cout<<"\n\nDo You Want To Continue(y/n)";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
}

void node::recdispvlr(node *root)
{
	if(root)
	{
		cout<<"\t"<<root->data;
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

void node::nonrecdispvlr(node *root)
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
			temp=temp->right;
		}
		else break;
	}
}

void node::nonrecdisplvr(node *root)
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

void node::nonrecdisplrv(node *root)
{
	node *stack[100],*temp;
	int top=-1;
	temp=root;
	top++;
	stack[top]=temp;
	while(top!=-1)
	{
		if(temp->left!=NULL && temp->left->visit==false)
		{
			top++;
			stack[top]=temp->left;
			temp=temp->left;
		}

		else if((temp->right!=NULL)&&(temp->right->visit==false))
		{
			top++;
			stack[top]=temp->right;
			temp=temp->right;
		}
		if((temp->right==NULL && temp->left==NULL)||((temp->right->visit==true)||(temp->left->visit==true)))
		{
			temp=stack[top];
			top--;
			cout<<"\t"<<temp->data;
			temp->visit=true;
			temp=stack[top];
		}
	}
}

int main()
{
	int i,ch;
	char c,ans;
	node p1,*root = new node;
	root->left=root->right=NULL;
	do
	{
		cout<<"1.Create Binary Tree\n2.Display\n3.Exit";
		cin>>ch;
		switch(ch)
		{
		case 1:
			root=p1.create(root);
			break;
		case 2:
			p1.dispmenu(root);
			break;
		case 3:
			break;
		default:
			cout<<"Invalid Choice\n";
		}
		cout<<"Want To Continue Operations On Tree?(y/n)";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	return 0;
}

