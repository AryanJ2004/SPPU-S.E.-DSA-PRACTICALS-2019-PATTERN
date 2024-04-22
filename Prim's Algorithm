#include<iostream>
using namespace std;

#define SIZE 10

int main()
{
int n,i,j,cost[10][10],min,visit[10],s,row,col,total=0,ne=1;
cout<<"Enter number of nodes==(enter the offices in different cities)";
cin>>n;

for(i=1;i<=n;i++)
{
    visit[i]=0;     //all node visited is 0   
}

cout<<"\n Enter cost adjacency matrix(Enter matrix )";

for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        cin>>cost[i][j];
        
    if(cost[i][j]==0)
    cost[i][j]=999;
    }
}

cout<<"Egdes of minimum spanning tree";
cout<<"\nenter the starting vertex:";
cin>>s;

visit[s]=1;

while(ne<n)         //if ne=1<4
{
    min=999;
    for(i=1;i<=n;i++)   //fix row..
    {

        if(visit[i]==1)
         {
            for(j=1;j<=n;j++)
                {
                    if(cost[i][j]<min && visit[j]==0)
                        {
                                    min=cost[i][j];
                                    row=i;
                                    col=j;
                        }//end of inner if

                }//end of inner for
             }//end if
    }//end for i
if(row!=col)
{
   ne++;
    cout<<"\negde=="<<row<<"  to  "<<col<<"=="<<min;
    visit[row]=visit[col]=1;
    total+=min;

}//end if

}//end while
cout<<"\n Minimum cost="<<total;
return 0;
}


