#include<iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    int count;
    Node *child[10];
};


class Tree
{
    public:
        Node *root;
        Tree()
        {
            root=NULL;
        }
        void createnode();
        void displaytree();
};


int main()
{
    int ch;
    Tree t;
    while(true)
    {
        cout<<"\n\n1.Create Tree "<<endl;
        cout<<"2.Display Tree "<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"Enter Choice:";
        cin>>ch;
        switch (ch)
        {
            case 1: t.createnode();
                break;
            case 2:t.displaytree();
                break;
            case 0: exit(0);
                break;
            default:    cout<<"Wrong Choice!";
        }
    }
    return 0;
}


void Tree::createnode()
{
    root=new Node;
    
    cout<<"Enter The Name Of The Book:- ";
    cin.ignore();
    getline(cin,root->name);
    
    cout<<"Enter No Of Chapters In Book:- ";
    cin>>root->count;
    
    for(int i=0;i<root->count;i++)
    {
        root->child[i]=new Node;
        cout<<"\tEnter The Name Of Chapter: "<<i+1<<":- ";
        cin.ignore();
        getline(cin,root->child[i]->name);
        
        cout<<"\tEnter No Of Sections In Chapter:"<<root->child[i]->name<<":- ";
        cin>>root->child[i]->count;
        
        for(int j=0;j<root->child[i]->count;j++)
        {
            root->child[i]->child[j]=new Node;
            cout<<"\t\tEnter The Name Of The Section:"<<j+1<<":- ";
            cin.ignore();
            getline(cin,root->child[i]->child[j]->name);
            
        }
    }
}


void Tree::displaytree()
{
    cout<<"\n\n================Index================\n\n";
    cout<<"Book\t\tChapter\t\tSection"<<endl;
    cout<<root->name<<endl;
    for(int i=0;i<root->count;i++)
    {
        cout<<"\t\t"<<root->child[i]->name<<endl;
        for(int j=0;j<root->child[i]->count;j++)
        {
            cout<<"\t\t\t\t"<<root->child[i]->child[j]->name<<endl;
        }
        cout<<"\t\t-------------------------"<<endl;
    }
}
