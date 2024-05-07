#include<iostream>
using namespace std;
class graph1
{
public:
int data;
graph1 *next;
graph1 *create(int n);
void disp(graph1 *head,int n);
void DFS( graph1 *graph,int i,int[],int); void BFS( graph1 *graph,int
i,int[],int n); int search(graph1 *graph,int i,int n); };
int main()
{
graph1 *head=NULL,*arr[20];
graph1 g;
int n,n1,ch1,i,visited[5],key;
char ans1;
do
{
cout<<"\n\n1.CREATE A GRAPH \n\n2.DISPLAY GRAPH\n\n3.DFS\n\n4.BFS"; cout<<"\n\nEnter the choice";
cin>>ch1;
switch(ch1)
{
case 1:
cout<<"\nEnter no of nodes=";
cin>>n;
cout<<"\nEnter the vertices";
head=g.create(n);
break;
case 2:
g.disp(head,n);
break;
case 3:
cout<<"\nEnter no of nodes from search=";
cin>>n1;
for(i=0;i<n;i++)
visited[i]=0;
g.DFS(head,n1,visited,n);
break;
case 4:
cout<<"\nEnter no of nodes from search="; cin>>n1;
for(i=0;i<n;i++)
visited[i]=0;
g.BFS(head,n1,visited,n);
break;
case 5:
exit(0);
}
cout<<"\n\ndo u want 2 cont";
cin>>ans1;
}while(ans1=='y' || ans1=='Y');
}
graph1 * graph1 :: create(int n)
{
int i;
graph1 *newnode,*temp;
graph1 *graph;
char ans;
graph= new graph1[n];
for(i=0;i<n;i++)
{
(graph+i)->next=NULL;
cin>>(graph+i)->data;
}
for(i=0;i<n;i++)
{
while((graph+i)!=NULL)
{
cout<<"\nadjacent(y/n)to "<<(graph+i)->data; cin>>ans;
if(ans=='n')
break;
newnode= new graph1;
cin>>newnode->data;
newnode->next=NULL;
temp=(graph+i);
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}//end of outer while
} //end of outer for
return(graph);
}
void graph1 ::disp(graph1 *graph,int n) {
int i;
graph1 *temp;
for(i=0;i<n;i++)
{
temp=graph+i;
cout<<"\n";
while(temp!=NULL)
{
cout<<"\t "<<temp->data;
temp=temp->next;
}
cout<<"-->NULL";
}
}
void graph1 :: DFS(graph1 *graph,int key,int visited[],int n) {
graph1 *p;
// int p;
int i,k;
i=search(graph,key,n);
// visited[key]=1;
visited[i]=1;
p=graph+i;
cout<<"\n"<<p->data;
// p=p->next;
while(p!=NULL)
{
i=search(graph,p->data,n);
if(visited[i]==0)
DFS(graph,p->data,visited,n);
p=p->next;
}
}
int graph1::search(graph1 *graph,int key,int n) {
for(int i=0;i<n;i++)
{
if((graph+i)->data==key)
{
return(i);
}
}
}
void graph1:: BFS( graph1 *graph,int key,int visited[],int n) {
int q[30];
int i,front=-1,rear=-1,vst;
graph1 *temp,*p;
i=search(graph,key,n);
visited[i]=1;
temp=graph+i;
q[++rear]=temp->data;
cout<<"\n "<<temp->data;;
while(front!=rear)
{
temp->data=q[++front];
i=search(graph,temp->data,n);
for(temp=(graph+i);temp!=NULL;temp=temp->next) {
i=search(graph,temp->data,n);
if(visited[i]==0)
{
q[++rear]=temp->data;
visited[i]=1;
cout<<"\n"<<temp->data;
}//end if
}//end for
}//end while
}//end func
