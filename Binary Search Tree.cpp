#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left=NULL,*right=NULL;
};

class BST
{
    public:
    Node *root;
    BST()
    {
        root=NULL;
    }
    void insert();
    void display_inorder(Node *root);
    int min();
    int longest_path(Node *nd);
    void search(int x);
    void mirror(Node *root);
};

void BST::insert()
{
    int n;
    cout<<"ENTER THE VALUE :";
    cin>>n;
    
    Node *temp=new Node;
    temp->data=n;
    
    if(root==NULL)
    {
        root = temp;
        return;
    }
    
    Node *trav=root;
    
    while(true)
    {
        if(trav->data>n)
            if(trav->left==NULL)
            {
                trav->left=temp;
                return;
            }
            else
                trav=trav->left;
        else
            if(trav->right==NULL)
            {
                trav->right=temp;
                return;
            }
            else
                trav=trav->right;
    }
}

void BST::display_inorder(Node *root)
{
    if(root == NULL)   
        return;
    display_inorder(root->left);
    cout<<root->data<<" ";
    display_inorder(root->right);
}

int BST::min()
{
    if(root==NULL)
        return -1;
    Node *trav=root;
    while(trav->left!=NULL)
        trav=trav->left;
    return trav->data;
}

int BST::longest_path(Node *nd)
{
    if(nd == NULL)
        return 0;

    int ll = longest_path(nd->left);
    int lr = longest_path(nd->right);

    return 1 + max(ll,lr);
}

void BST::search(int x)
{
    Node *trav=root;
    while(trav!=NULL)
    {
        if(trav->data==x)
        {
            cout<<"DATA FOUND"<<endl;
            return;
        }
        else if(trav->data>x)
            trav=trav->left;
        else
            trav=trav->right;
    }
    cout<<"DATA NOT FOUND"<<endl;
}

void BST::mirror(Node *root)
{
    if(root==NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    Node *temp=root->left;
    root->left=root->right;
    root->right=temp;
}

int main ()
{

    BST b;
    int ch;
    do
    {
        cout<<"\n=====================MENU=====================\n";
        cout<<"1.INSERT NODE\n2.DISPLAY INORDER OF THE TREE\n3.FIND NUMBER OF NODES IN LONGEST PATH FROM ROOT\n4.MINIMUM DATA VALUE FOUND IN THE TREE\n5.MIRROR TREE\n6.SEARCH A NODE BY VALUE\n0.EXIT\n";
        cout<<"\nENTER YOUR CHOICE :";
        cin>>ch;
        switch (ch)
        {
    	    case 1:
        	    b.insert();
        	    break;

    	    case 2:
    	        cout << "\nINORDER TRAVERSAL : ";
                b.display_inorder (b.root);
                cout << endl;
                break;

            case 3:
                cout << "NUMBER OF NODES IN LONGEST PATH FROM ROOT : ";
                cout << b.longest_path (b.root) << endl;
                break;

            case 4:
                cout<<"MINIMUM DATA VALUE FIND IN THE TREE : "<<b.min()<<endl;
                break;

            case 5:
                b.mirror(b.root);
                cout<<"TREE AFTER MIRROR : ";
                b.display_inorder(b.root);
                b.mirror(b.root);
                break;

            case 6:
                cout<<"ENTER THE VALUE TO SEARCH :";
                int val;
                cin>>val;
                b.search(val);
                break;

            case 0:
                break;
      }
    }while (ch != 0);
  }
