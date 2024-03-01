#include <iostream>
using namespace std;
struct treenode
{
	int data;
	treenode *left;
	treenode *right;
	
};

treenode *insert(treenode *node ,int data)
{
	if(node==NULL)
	{
		treenode *temp;
		temp=new treenode;
		temp->data=data;
		temp->left=temp->right=NULL;
		return temp;
	}
	if(data>(node->data))
	{
		node->right=insert(node->right,data);
	}
	else if(data<(node->data))
	{
		node->left=insert(node->left,data);
	}
	return node;
}

treenode *findmin(treenode *node)
{
	if(node==NULL)
	{
		return NULL;
	}
	if(node->left)
		return findmin(node->left);
	else
		return node;
}

treenode *findmax(treenode *node)
{
	if(node==NULL)
	{
		return NULL;
	}
	if(node->left)
		return findmax(node->right);
	else
		return node;
}

void inorder(treenode *root)
{
if(root)
{
	inorder(root->left);
	cout<<"\t"<<root->data;
	inorder(root->right);
}
}

int main()
{
	treenode *root=NULL,*temp;
	int ch,n;
	cout<<"Enter The Number Of Elements To Insert?"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Element To Be Inserted"<<endl;
		cin>>ch;
		root=insert(root,ch);
	}
	cout<<"ELEMENTS IN TREE ARE:"<<endl;
	inorder(root);
	return 0;
	
}
