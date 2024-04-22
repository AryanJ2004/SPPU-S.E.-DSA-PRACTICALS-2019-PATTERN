#include<iostream>
using namespace std;

#define true 1
#define false 0
#define max 100

class node
{
public:
    int data, top, visit;
    node *left, *right, *root;

    node()
    {
        root = NULL;
    }

    node *create(node *root);
    void insert(node *root, node *temp);
    void dispmenu(node *root);

    void recdispvlr(node *root);
    void recdisplvr(node *root);
    void recdisplrv(node *root);

    void nonrecvlr(node *root);
    void nonreclvr(node *root);
    void nonreclrv(node *root);
};

node *node::create(node *root)
{
    node *temp;
    char c;
    do
    {
        temp = new node;
        temp->left = NULL;
        temp->right = NULL;
        temp->visit = false;
        cout << "\nEnter the data : ";
        cin >> temp->data;
        if (root == NULL)
            root = temp;
        else
            insert(root, temp);
        cout << "\n\nWant to enter more nodes? (y/n): ";
        cin >> c;
    } while (c == 'Y' || c == 'y');
    return root;
}

void node::insert(node *root, node *temp)
{
    char ch;
    cout << "Insert data to left (l) or right (r) of " << root->data << ": ";
    cin >> ch;
    if (ch == 'l' || ch == 'L')
    {
        if (root->left == NULL)
        {
            root->left = temp;
        }
        else
            insert(root->left, temp);
    }
    if (ch == 'r' || ch == 'R')
    {
        if (root->right == NULL)
        {
            root->right = temp;
        }
        else
            insert(root->right, temp);
    }
}

void node::dispmenu(node *root)
{
    int ch;
    char ans;
    do
    {
        cout << "Display binary tree:\n\n1: RECURSIVE PREORDER\n2: RECURSIVE INORDER\n3: RECURSIVE POSTORDER\n";
        cout << "4: NON-RECURSIVE PREORDER\n5: NON-RECURSIVE INORDER\n6: NON-RECURSIVE POSTORDER\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "RECURSIVE PREORDER (VLR) TRAVERSAL\n";
            recdispvlr(root);
            break;
        case 2:
            cout << "RECURSIVE INORDER (LVR) TRAVERSAL\n";
            recdisplvr(root);
            break;
        case 3:
            cout << "RECURSIVE POSTORDER (LRV) TRAVERSAL\n";
            recdisplrv(root);
            break;
        case 4:
            cout << "NON-RECURSIVE PREORDER (VLR) TRAVERSAL\n";
            nonrecvlr(root);
            break;
        case 5:
            cout << "NON-RECURSIVE INORDER (LVR) TRAVERSAL\n";
            nonreclvr(root);
            break;
        case 6:
            cout << "NON-RECURSIVE POSTORDER (LRV) TRAVERSAL\n";
            nonreclrv(root);
            break;
        default:
            cout << "Invalid choice\n";
        }
        cout << "\n\nDo you want to continue displaying the tree? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}

void node::recdispvlr(node *root)
{
    if (root)
    {
        cout << "\t" << root->data;
        recdispvlr(root->left);
        recdispvlr(root->right);
    }
}

void node::recdisplvr(node *root)
{
    if (root)
    {
        recdisplvr(root->left);
        cout << "\t" << root->data;
        recdisplvr(root->right);
    }
}

void node::recdisplrv(node *root)
{
    if (root)
    {
        recdisplrv(root->left);
        recdisplrv(root->right);
        cout << "\t" << root->data;
    }
}

void node::nonrecvlr(node *root)
{
    node *stack[100], *temp;
    int top = -1;
    temp = root;
    while (1)
    {
        while (temp)
        {
            top++;
            stack[top] = temp;
            cout << temp->data << "\n";
            temp = temp->left;
        }
        if (top != -1)
        {
            temp = stack[top];
            top--;
            temp = temp->right;
        }
        else
            break;
    }
}

void node::nonreclvr(node *root)
{
    node *stack[100], *temp;
    int top = -1;
    temp = root;
    while (1)
    {
        while (temp)
        {
            top++;
            stack[top] = temp;
            temp = temp->left;
        }
        if (top != -1)
        {
            temp = stack[top];
            top--;
            cout << temp->data;
            temp = temp->right;
        }
        else
            break;
    }
}

void node::nonreclrv(node *root)
{
    node *stack[100], *temp;
    int top = -1;
    temp = root;
    top++;
    stack[top] = temp;
    while (top != -1)
    {
        if (temp->left != NULL && temp->left->visit == false)
        {
            top++;
            stack[top] = temp->left;
            temp = temp->left;
        }
        else if ((temp->right != NULL) && (temp->right->visit == false))
        {
            top++;
            stack[top] = temp->right;
            temp = temp->right;
        }
        if ((temp->right == NULL && temp->left == NULL) || ((temp->right->visit == true) || (temp->left->visit == true)))
        {
            temp = stack[top];
            top--;
            cout << "\t" << temp->data;
            temp->visit = true;
            temp = stack[top];
        }
    }
}

int main()
{
    int ch;
    char ans;
    node p1;
    do
    {
        cout << "1: Create binary tree \n2: Display \n3: Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            p1.root = p1.create(p1.root);
            break;
        case 2:
            p1.dispmenu(p1.root);
            break;
        case 3:
            break;
        default:
            cout << "Invalid choice\n";
        }
        cout << "\nWant to continue operations? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}
