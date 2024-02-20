#include <iostream>
using namespace std;

class nodeth
{
public:
	int data,thleft,thright;
	nodeth *left,*right;
	nodeth()
	{
		thleft=0;
		thright=0;
	}
	nodeth *create(nodeth *root);
	void insert(nodeth *root,nodeth *temp);
	void display(nodeth *root);
	void display1(nodeth *root);
	nodeth *header=NULL;
};

nodeth *nodeth::create(nodeth *root)
{
	nodeth *temp;
	char ans;
	do
	{
		temp=new nodeth;
		cout<<"Enter Data:"<<endl;
		cin>>temp->data;
		temp->left=temp->right=NULL;
		if(root==NULL)
		{
			root=temp;
			root->left=root->right=header;
			root->thleft=root->thright=1;
		}
		else
			insert(root,temp);
		cout<<"Do You Want To Add Another Node?"<<endl;
		cin>>ans;

	}while(ans=='y'||ans=='Y');
	return root;
}

void nodeth::insert(nodeth *root,nodeth *temp)
{
	char ch;
	cout<<"\n\nDo You Want To Insert To Left Or Right(l or r)"<<root->data<<endl;
	cin>>ch;
	if(ch=='l'||ch=='L')
	{
		if(root->thleft==1)
		{
			temp->left=root->left;
			root->left=temp;
			temp->right=root;
			root->thleft=0;
			temp->thleft=temp->thright=1;

		}
		else
		{
			insert(root->left,temp);
		}
	}
	else if(ch=='r'|| ch=='R')
	{
		if(root->thright=1)
		{
			temp->right=root->right;
			root->right=temp;
			temp->left=root;
			root->thright=0;
			temp->thright=temp->thleft=1;
		}
		else
		{
			insert(root->right,temp);
		}
	}
}

void nodeth::display(nodeth *root)
{
	nodeth *temp=root;
	int flag=0;
	do
	{
		while(flag==0 && temp->thleft==0)
		{
			temp=temp->left;
		}
		cout<<"\t"<<temp->data;
		if(temp->thright==0)
			flag=0;
		else
			flag=1;
		temp=temp->right;
	}while(temp!=NULL);
}

int main()
{
	nodeth *root=NULL;
	int ch;
	char ch1;
	nodeth th1;
	do
	{
		cout<<"\n\n1.Create Threaded Binary Tree\n\n2.Inorder Display\n\n3.Preorder Display\n\n4.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			root=th1.create(root);
			break;
		case 2:
			cout<<"\nInorder Threaded Binary Tree"<<endl;
			th1.display(root);
			break;
		//case 3:
		//	cout<<"\n\nPreorder Threaded Binary Tree"<<endl;
		//	th1.display1(root);
		//	break;
		case 4:
			break;
		}
			cout<<"\nDo You Want To Continue"<<endl;
			cin>>ch1;
	}while(ch1=='Y'||ch1=='y');
	return 0;
	
}

