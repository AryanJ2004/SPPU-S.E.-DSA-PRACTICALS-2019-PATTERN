#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

struct stud
{
int rno;
char nm[10];
}s;

void create()
{
ofstream fout;
int n,i;
fout.open("stud.txt",ios::out);
cout<<"\nEnter The Number of records="<<endl;
cin>>n;
for(i=0;i<n;i++)
{
cout<<"\nEnter The Roll No And Name="<<endl;
cin>>s.rno>>s.nm;
fout<<endl<<s.rno<<"\t"<<s.nm;
}
}

void display()
{
ifstream fin;
fin.open("stud.txt",ios::in);
while(!fin.eof())
{
fin>>s.rno>>s.nm;
cout<<"\n"<<s.rno<<"\t"<<s.nm;
}
fin.close();
}

void search()
{
ifstream fin;
int fl,key;
cout<<"\nEnter roll Number of element which you want to search =";
cin>>key;
fin.open("stud.txt",ios::in);
while(!fin.eof())
{
	fin>>s.rno>>s.nm;
if(s.rno==key)
{
fl=1;
break;
}
if(fl==1)
cout<<"Element Found\n"<<s.rno<<"\t"<<s.nm;
else
cout<<"\nElement Not Found"<<endl;
fin.close();
}
}
void delete_rec()
{
ifstream fin,fin1;
ofstream fout,fout1;
int key,flag=0;
cout<<"\nEnter key To Be Deleted";
cin>>key;
fin.open("stud.txt",ios::in);
fout.open("temp.text",ios::out);
while(!fin.eof())
{
fin>>s.rno>>s.nm;
if(key==s.rno)
{
flag=1;
}
else
fout<<endl<<s.rno<<s.nm;
}
fin.close();
fout.close();
fin1.open("temp.txt",ios::in);
fout.open("stud1.txt",ios::out);
while(!fin.eof())
{
fin1>>s.rno>>s.nm;
fout1<<endl<<s.rno<<s.nm;
}
fin1.close();
fout1.close();

if(flag!=1)
cout<<"\nRecourd Not Found";
else
display();
}


void update_rec()
{
ifstream fin,fin1;
ofstream fout,fout1;
int key,flag=0;
cout<<"\nEnter The Key To Be Updated";
cin>>key;
fin.open("stud.txt",ios::in);
fout.open("temp.txt",ios::out);
while(!fin.eof())
{
fin>>s.rno>>s.nm;
if(key==s.rno)
{
flag=1;
cout<<"\nEnter New Record"<<endl;
cin>>s.rno>>s.nm;
fout<<endl<<s.rno<<s.nm;
}
else
fout<<endl<<s.rno<<s.nm;
}

fin.close();
fout.close();
fin.open("stud.txt",ios::in);
fout.open("temp.text",ios::out);
while(!fin.eof())
{
fin>>s.rno>>s.nm;
fout1<<endl<<s.rno<<s.nm;
}
fin1.close();
fout1.close();
if(flag!=1)
cout<<"\nRecord Not Found"<<endl;
else
display();
}
int main()
{
int ch;
do{
cout<<"\n1.Create\n2.Display\n3.Search\n4.Delete\n5.Update Record";
cout<<"\nEnter The Choice="<<endl;
cin>>ch;
switch(ch)
{
case 1:create();
	break;
case 2:display();
break;
case 3:search();
break;
case 4:delete_rec();
break;
case 5:update_rec();
break;
}
}while(ch<6);
return 0;
}


