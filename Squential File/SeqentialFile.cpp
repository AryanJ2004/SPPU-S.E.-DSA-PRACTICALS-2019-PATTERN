#include<fstream>
#include <iostream>
#include<string.h>
using namespace std;
struct stud
{
int rno;
char nm[10];
}s;
void create() {
    ofstream fout;
    int n;
    stud s;
    fout.open("stud1.txt", ios::out); // Open file for writing

    cout << "Enter the number of records: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter roll number and name: ";
        cin >> s.rno >> s.nm;
        fout << s.rno << "\t" << s.nm << endl; // Write record to file
    }

    fout.close(); // Close the file
}

void display() {
    ifstream fin;
    stud s;
    fin.open("stud1.txt", ios::in); // Open file for reading

    while (fin >> s.rno >> s.nm) { // Read until no more valid input
        cout << s.rno << "\t" << s.nm << endl; // Display the record
    }

    fin.close(); // Close the file
}
void search()
{
ifstream fin;
int fl,key;
cout<<"\nEnter number of element=";
cin>>key;
fin.open("stud1.txt",ios::in); //fin = read from file 
while(!fin.eof())
{
fin>>s.rno>>s.nm;
if(s.rno==key)
{
fl=1;
break;
}
}
if(fl==1)
cout<<"\nElement found"<<s.rno<<"\t"<<s.nm; else
cout<<"\nElement not found";
fin.close();
}
void delete_rec()
{
ifstream fin,fin1;
ofstream fout,fout1;
int key,flag=0;
cout<<"\n Enter the key to be deleted=";
cin>>key;
fin.open("stud1.txt",ios::in);//fin = read from file
fout.open("temp.txt",ios::out);//out = write while(!fin.eof())
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
fout1.open("stud1.txt",ios::out);
while(!fin1.eof())
{
fin1>>s.rno>>s.nm;
fout1<<endl<<s.rno<<s.nm;
}
fin1.close();
fout1.close();
if(flag!=1)
cout<<"\nRecord Not found!!";
else
display();
}
void update_rec() {
    ifstream fin("stud1.txt", ios::in); // Open the original file for reading
    ofstream fout("temp.txt", ios::out); // Open a temporary file for writing
    stud s;
    int key;
    bool flag = false; // To check if the record to update is found

    cout << "Enter the roll number to update: ";
    cin >> key;

    // Read from the original file and write to the temp file
    while (fin >> s.rno >> s.nm) {
        if (s.rno == key) { // If the record matches the key
            flag = true; // Set the flag to indicate the record was found
            cout << "Enter new roll number and name: ";
            cin >> s.rno >> s.nm; // Get the new values
        }
        fout << s.rno << "\t" << s.nm << endl; // Write to the temp file
    }

    fin.close(); // Close the original file
    fout.close(); // Close the temp file

    if (flag) { // If the record was found and updated
        // Now, write the contents of the temp file back to the original file
        ifstream fin1("temp.txt", ios::in); // Open the temp file for reading
        ofstream fout1("stud1.txt", ios::out); // Open the original file for writing

        while (fin1 >> s.rno >> s.nm) { // Read from the temp file
            fout1 << s.rno << "\t" << s.nm << endl; // Write back to the original file
        }

        fin1.close(); // Close the temp file
        fout1.close(); // Close the rewritten original file

        cout << "Record updated successfully." << endl; // Confirmation message
    } else { // If the record was not found
        cout << "Record not found." << endl;
    }
}
int main()
{
int ch;
do
{
cout<<"\n1.Create\n2.Dispaly\n3.Search\n4.Delete Record\n5.Update";
cout<<"\nEnter your choice==";
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
}while(ch<7);
}
