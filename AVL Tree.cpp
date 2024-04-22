#include<iostream>
using namespace std;

class node {
public:
    int data;
    int bf;
    node *left;
    node *right;
    node *root;

    node() {
        root = NULL;
    }

    node* insert(int data, int *c_flag);
    node* create(node *root, int data, int *c_flag);
    void display(node *root);
};

node *node::insert(int data, int *c_flag) {
    root = create(root, data, c_flag);
    return(root);
}

node *node::create(class node *root, int data, int *c_flag) {
    class node *t1,*t2;
    if(root == NULL) {
        root = new node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->bf = 0;
        *c_flag = 1;
        return(root);
    }
    if(data < root->data) {
        root->left = create(root->left, data, c_flag);
        if(*c_flag == 1) {
            switch(root->bf) {
                case -1:
                    root->bf=0;
                    break;
                case 0:
                    root->bf = 1;
                    break;
                case 1:
                    t1 = root->left;
                    if(t1->bf == 1) {
                        cout<<"\nLL rotation";
                        root->left = t1->right;
                        t1->right = root;
                        root->bf = 0;
                        root = t1;
                    } else {
                        cout<<"\nLR Rotation";
                        t2 = t1->right;
                        t1->right = t2->left;
                        t2->left = t1;
                        root->left = t2->right;
                        t2->right = root;
                        if(t2->bf == -1)
                            t1->bf = 1;
                        else
                            t1->bf = 0;
                        if(t2->bf == 1)
                            root->bf = -1;
                        else
                            root->bf = 0;
                        root = t2;
                    }
                    root->bf = 0;
                    *c_flag = 0;
                    break;
            }
        }
    }
    if(data > root->data) {
        root->right = create(root->right, data, c_flag);
        if(*c_flag == 1) {
            switch(root->bf) {
                case 1:
                    root->bf=0;
                    break;
                case 0:
                    root->bf = -1;
                    break;
                case -1:
                    t1 = root->right;
                    if(t1->bf == -1) {
                        cout<<"\nRR rotation";
                        root->right = t1->left;
                        t1->left = root;
                        root->bf = 0;
                        root = t1;
                    } else {
                        cout<<"\nRL Rotation";
                        t2 = t1->left;
                        t1->left = t2->right;
                        t2->right = t1;
                        root->right = t2->left;
                        t2->left = root;
                        if(t2->bf == 1)
                            t1->bf = -1;
                        else
                            t1->bf = 0;
                        if(t2->bf == -1)
                            root->bf = 1;
                        else
                            root->bf = 0;
                        root = t2;
                    }
                    root->bf = 0;
                    *c_flag = 0;
                    break;
            }
        }
    }
    return(root);
}

void node::display(node *root) {
    if(root!=NULL) {
        display(root->left);
        cout<<root->data<<"\t";
        display(root->right);
    }
}

void main() {
    node t;
    node *root;
    int data;
    char ch;
    int *c_flag;

    do {
        cout<<"\nEnter data";
        cin>>data;
        root = t.insert(data, c_flag);
        cout<<"\n\nAVL TREE:";
        t.display(root);
        cout<<"\n\nDo u want to continue:";
        cin>>ch;
    } while(ch=='y'|| ch=='Y');
}
