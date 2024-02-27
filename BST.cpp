
//======================================INCOMPLETE PROGRAM==============================

#include <iostream>
using namespace std;
struct node
{
    int key;
    int data;
    struct node *left,*right;
    
};

class stack
{
    struct node *data[20];
    int top;
    public:
    stack()
    {
        top=-1;
    }
    void push(struct node*);
    struct node *pop();
    int isEmpty();
    
};

class BST
{
    struct node *root;
    struct node *findmin(struct node*);
    struct node *findmax(struct node*);
    void swapper(struct node*);
    int height_of_tree(sturct node*);
    struct node *createnode();
    public:
    BST()
    {
        root=NULL;
    }
    void createTree();
    void insertnode();
    void non_rec_inorder();
    int searchtree(int);
    struct node *findmin1()
    {
        struct node *min=findmin(root);
        return min;
    }
    struct node *findmax1()
    {
        struct node *max=findmax(root);
        return max;
    }
    void swapper1()
    {
        swapper(root);
    }
    void deleteNode1(int key)
    {
        root=deletenode(root,key);
    }
    void height_of_tree1()
    {
        int height=height_of_tree(root);
        return height;
    }
};

void BST::createTree()
{
    int n;
    cout<<"Enter How Many Nodes You Want To Enter:?"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        insertnode();
    }
}
struct node* BST::createnode()
{
    struct node *newNode=new node;
    cout<<"Enter Data"<<endl;
    cin>>newNode->data;
    newNode->left=newNode->right=NULL;
    return (newNode);
}

void BST::insertnode()
{
    struct node *newNode=createnode();
    if(root==NULL)
    root=newNode;
    else
    {
        struct node *old;
        struct node *temp=root;
        while(temp!=NULL)
        {
            if(newNode->data<temp->data)
            {
                old=temp;
                temp=temp->left;
            }
            else
            {
                old=temp;
                temp=temp->right;
            }
            
        }
        if(newNode->data<old->data)
        old->left=newNode;
        else
        old->right=newNode;
    }
}

void BST::non_rec_inorder()
{
    stack stk;
    struct node *temp=root;
    if(temp==NULL)
    {
        cout<<"\nTree Is Empty"<<endl;
    }
    while(temp!=NULL)
    {
        stk.push(temp);
        temp=temp->left;
    }
    while(!stk.isEmpty())
    {
        struct node *ele=stk.pop();
        cout<<ele->data<<" ";
        ele=ele->right;
        while(ele!=NULL)
        {
            stk.push(ele);
            ele=ele->left;
        }
    }
}

void stack::push(struct node *ele)
{
    top++;
    data[top]=ele;
}

struct node *stack::pop()
{
    struct node* ele=data[top];
    top--;
    return ele;
}

int stack::isEmpty()
{
    if(top==-1)
    return 1;
    return 0;
}

int BST::searchtree(int key)
{
    struct node *temp=root;
    if(temp==NULL)
    {
        cout<<"Tree Is Empty"<<endl;
        
    }
    while(temp!=NULL)
    {
        if(temp->data==key)
        return 1;
        if(temp->data>key)
        temp=temp->left;
        else
        temp=temp->right;
    }
    return 0;
    }
    
struct node* BST::findmin(struct node *temp)
{
    struct node *old;
    while(temp!=NULL)
    {
        old=temp;
        temp=temp->right;
    }
    return old;
}
