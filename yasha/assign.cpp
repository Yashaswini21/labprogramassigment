#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<stdlib.h>
#include<string.h>
using namespace std;
class program
{
	public: char usn[30],name[30],sec[10],buffer[45];char randomnum[5];
};
fstream file1,file2;
program s;
void  pack()
{
	file1.open("program.txt",ios::app);
	if(!file1)
	{
		cout<<"\tunable to open the file!!!\t\n";
		exit(0);
	}
	cout<<"\n";
	cout<<"----------------------------------------------------------------------\n";
	cout<<"\t\tEnter the details to store\t\n";
	cout<<"\t\tEnter the USN :  ";
	cin>>s.usn;
	cout<<"\t\tEnter the NAME:  ";
	cin>>s.name;
	cout<<"\t\tEnter the Sem and section:  ";
	cin>>s.sec;
	cout<<"\t\tEnter the Program you got:   ";
	cin>>s.randomnum;
	cout<<"\n";
	strcpy(s.buffer,s.usn);
	strcat(s.buffer,"\t");
	strcat(s.buffer,s.name);
	strcat(s.buffer,"\t");
	strcat(s.buffer,s.sec);
	strcat(s.buffer,"\t");
	strcat(s.buffer,s.randomnum);
	strcat(s.buffer,"\n");
	file1<<s.buffer;
	file1.close();
}
void display()
{
	file1.open("program.txt",ios::in);
	if(!file1)
	{
		cout<<"\t\tunable to open the file!!!\t\n";
		exit(0);
	}
	cout<<"\t\tUSN\t\tNAME\t\tSEM_SEC\tPROGRAM\n";
	while(!file1.eof())
	{
		file1.getline(s.usn,30,'\t');
		file1.getline(s.name,30,'\t');
		file1.getline(s.sec,10,'\t');
		file1.getline(s.randomnum,5,'\n');
		cout<<"\t\t"<<s.usn<<"\t"<<s.name<<"\t"<<s.sec<<"\t"<<s.randomnum<<"\n";
	}
	file1.close();
}
void search()
{
	char usn[20];
	file1.open("program.txt",ios::in);
	if(!file1)
	{
		cout<<"\t\tunable to open the file!!!\t\n";
		exit(0);
	}
	cout<<"\t\tEnter the USN to search:  \t ";
	cin>>usn;
	while(!file1.eof())
	{
		file1.getline(s.usn,30,'\t');
		file1.getline(s.name,30,'\t');
		file1.getline(s.sec,10,'\t');
		file1.getline(s.randomnum,5,'\n');
		if(strcmp(s.usn,usn)==0)
		{
			cout<<"\t\tHey  "<<s.usn<<"  You had got "<<s.randomnum<<"\n";
			file1.close();
			return;
		}
	}
	cout<<"\n";
	cout<<"\tWRONG USN PLEASE CHECK!!!!\t\n";
	file1.close();
}
void changeofprogram()
{
	char buffer[45],usn[20];
	int i,count;
	program s[20];
	file1.open("program.txt",ios::in);
	if(!file1)
	{
		cout<<"\t\tunable to open the file!!!\t\n";
		exit(0);
	}
	cout<<"\t\tEnter the  USN to change\t:";
	cin>>usn;
	count=0;
	while(!file1.eof())
	{
		file1.getline(s[count].usn,30,'\t');
		file1.getline(s[count].name,30,'\t');
		file1.getline(s[count].sec,10,'\t');
		file1.getline(s[count].randomnum,5,'\n');
		count++;
	}
	for(i=0;i<count;i++)
	{
		if(strcmp(s[i].usn,usn)==0)
		{
			cout<<"\t\tPrevious program \t:"<<s[i].randomnum<<"\n";
			cout<<"\n";
			cout<<"\t\tEnter the details to store\t\n";
			cout<<"\t\tEnter the USN :  ";
			cin>>s[i].usn;
			cout<<"\t\tEnter the NAME:  ";
			cin>>s[i].name;
			cout<<"\t\tEnter the Sem and section:  ";
			cin>>s[i].sec;
			cout<<"\t\tEnter the new Program you got:   ";
			cin>>s[i].randomnum;
			cout<<"\n";
			break;
		}
	}
	if(i==count)
	{
		cout<<"\t\tWRONG USN CHECK PLEASE\n";
		return;
	}
	file1.close();
	file1.open("program.txt",ios::out);
	if(!file1)
	{
		cout<<"\t\tunable to open the file!!!\t\n";
		exit(0);
	}
	for(i=0;i<count;i++)
	{
		strcpy(s[i].buffer,s[i].usn);
		strcat(s[i].buffer,"\t");
		strcat(s[i].buffer,s[i].name);
		strcat(s[i].buffer,"\t");
		strcat(s[i].buffer,s[i].sec);
		strcat(s[i].buffer,"\t");
		strcat(s[i].buffer,s[i].randomnum);
		strcat(s[i].buffer,"\n");
		file1<<s[i].buffer;
	}
	file1.close();
}
void  pack1()
{
	file2.open("st.txt",ios::app);
	if(!file2)
	{
		cout<<"\tunable to open the file!!!\t\n";
		exit(0);
	}
	cout<<"\n";
	cout<<"----------------------------------------------------------------------\n";
	cout<<"\t\tEnter the details to store\t\n";
	cout<<"\t\tEnter the USN :  ";
	cin>>s.usn;
	cout<<"\t\tEnter the NAME:  ";
	cin>>s.name;
	cout<<"\t\tEnter the Sem and section:  ";
	cin>>s.sec;
	cout<<"\t\tEnter the Program you got:   ";
	cin>>s.randomnum;
	cout<<"\n";
	strcpy(s.buffer,s.usn);
	strcat(s.buffer,"\t");
	strcat(s.buffer,s.name);
	strcat(s.buffer,"\t");
	strcat(s.buffer,s.sec);
	strcat(s.buffer,"\t");
	strcat(s.buffer,s.randomnum);
	strcat(s.buffer,"\n");
	file2<<s.buffer;
	file2.close();
}
void display1()
{
	file2.open("st.txt",ios::in);
	if(!file2)
	{
		cout<<"\t\tunable to open the file!!!\t\n";
		exit(0);
	}
	cout<<"\t\tUSN\t\tNAME\t\tSEM_SEC\tPROGRAM\n";
	while(!file2.eof())
	{
		file2.getline(s.usn,30,'\t');
		file2.getline(s.name,30,'\t');
		file2.getline(s.sec,10,'\t');
		file2.getline(s.randomnum,5,'\n');
		cout<<"\t\t"<<s.usn<<"\t"<<s.name<<"\t"<<s.sec<<"\t"<<s.randomnum<<"\n";
	}
	file2.close();
}
void search1()
{
	char usn[20];
	file2.open("st.txt",ios::in);
	if(!file2)
	{
		cout<<"\t\tunable to open the file!!!\t\n";
		exit(0);
	}
	cout<<"\t\tEnter the USN to search:  \t ";
	cin>>usn;
	while(!file2.eof())
	{
		file2.getline(s.usn,30,'\t');
		file2.getline(s.name,30,'\t');
		file2.getline(s.sec,10,'\t');
		file2.getline(s.randomnum,5,'\n');
		if(strcmp(s.usn,usn)==0)
		{
			cout<<"\t\tHey  "<<s.usn<<"  You had got "<<s.randomnum<<"\n";
			file2.close();
			return;
		}
	}
	cout<<"\n";
	cout<<"\tWRONG USN PLEASE CHECK!!!!\t\n";
	file2.close();
}
void changeofprogram1()
{
	char buffer[45],usn[20];
	int i,count;
	program s[20];
	file2.open("st.txt",ios::in);
	if(!file2)
	{
		cout<<"\t\tunable to open the file!!!\t\n";
		exit(0);
	}
	cout<<"\t\tEnter the  USN to change\t:";
	cin>>usn;
	count=0;
	while(!file2.eof())
	{
		file2.getline(s[count].usn,30,'\t');
		file2.getline(s[count].name,30,'\t');
		file2.getline(s[count].sec,10,'\t');
		file2.getline(s[count].randomnum,5,'\n');
		count++;
	}
	for(i=0;i<count;i++)
	{
		if(strcmp(s[i].usn,usn)==0)
		{
			cout<<"\t\tPrevious program \t:"<<s[i].randomnum<<"\n";
			cout<<"\n";
			cout<<"\t\tEnter the details to store\t\n";
			cout<<"\t\tEnter the USN :  ";
			cin>>s[i].usn;
			cout<<"\t\tEnter the NAME:  ";
			cin>>s[i].name;
			cout<<"\t\tEnter the Sem and section:  ";
			cin>>s[i].sec;
			cout<<"\t\tEnter the new Program you got:   ";
			cin>>s[i].randomnum;
			cout<<"\n";
			break;
		}
	}
	if(i==count)
	{
		cout<<"\t\tWRONG USN CHECK PLEASE\n";
		return;
	}
	file2.close();
	file2.open("st.txt",ios::out);
	if(!file2)
	{
		cout<<"\t\tunable to open the file!!!\t\n";
		exit(0);
	}
	for(i=0;i<count;i++)
	{
		strcpy(s[i].buffer,s[i].usn);
		strcat(s[i].buffer,"\t");
		strcat(s[i].buffer,s[i].name);
		strcat(s[i].buffer,"\t");
		strcat(s[i].buffer,s[i].sec);
		strcat(s[i].buffer,"\t");
		strcat(s[i].buffer,s[i].randomnum);
		strcat(s[i].buffer,"\n");
		file2<<s[i].buffer;
	}
	file2.close();
}	
	
int main()
{
	int ch,sub;
	file1.open("program.txt",ios::app);
	file1.close();
	file2.open("st.txt",ios::app);
	file2.close();
	char usn1[30];
	srand(time(0));
	int max,y;
	cout<<"\n";
	cout<<"----------------------------------------------------------------------\n";
	cout<<"\n";
	cout<<"\t\t1.FILE STRUCTURES LABORATORY\n\t\t2.SOFTWARE TESTING\n\t\t3.EXIT\n";
	cout<<"\n";
	cout<<"----------------------------------------------------------------------\n";
	cout<<"\t\tEnter the Subject\t:";
	cin>>sub;
	cout<<"\n";
	switch(sub)
	{
		case 1:max=9;cout<<"----------FILE STRUCTURES LABORATORY EXAMINATION 2021/22--------------\n";
		for(;;)
		{
			cout<<"----------------------------------------------------------------------\n";
			cout<<"\t\t1.ASSIGN PROGRAM\n\t\t2.DISPLAY THE DETAILS\n\t\t3.SEARCH BY USN\n\t\t4.CHANGE OF PROGRAM\n\t\t5.EXIT\t\n";
			cout<<"\n";
			cout<<"----------------------------------------------------------------------\n";
			cout<<"\t\tEnter the Choice\t:";
			cin>>ch;
			cout<<"\n";
			cout<<"----------------------------------------------------------------------\n";
			cout<<"\n";
			switch(ch)
			{
				case 1:cout<<"\t\tEnter the usn\t:";
				cin>>usn1;
				cout<<"\n";
				cout<<"\t\tALL THE BEST--------->"<<usn1<<"\t\n";
				y=rand()%max;
				if(y==0 || y==1)
					continue;
				cout<<"\t\t"<<usn1<<"\tYou have got program :  "<<y<<"\t"<<"\n";
				pack();
				break;
				case 2:display();
				break;
				case 3:search();
				break;
				case 4:cout<<"\t\tEnter the usn\t:";
				cin>>usn1;
				cout<<"\n";
				y=rand()%max;
				if(y==0 || y==1)
					continue;
				cout<<"\t\t"<<usn1<<"\tYou have got program :  "<<y<<"\t"<<"\n";
				changeofprogram();
				break;
				default:exit(0);
			}
		}
		break;
		case 2:max=13;cout<<"----------SOFTWARE TESTING LABORATORY EXAMINATION 2021/22--------------\n";
		for(;;)
		{
			cout<<"----------------------------------------------------------------------\n";
			cout<<"\t\t1.ASSIGN PROGRAM\n\t\t2.DISPLAY THE DETAILS\n\t\t3.SEARCH BY USN\n\t\t4.CHANGE OF PROGRAM\n\t\t5.EXIT\t\n";
			cout<<"\n";
			cout<<"----------------------------------------------------------------------\n";
			cout<<"\t\tEnter the Choice\t:";
			cin>>ch;
			cout<<"\n";
			cout<<"----------------------------------------------------------------------\n";
			cout<<"\n";
			switch(ch)
			{
				case 1:cout<<"\t\tEnter the usn\t:";
				cin>>usn1;
				cout<<"\n";
				cout<<"\t\tALL THE BEST--------->"<<usn1<<"\t\n";
				y=rand()%max;
				if(y==0)
					continue;
				cout<<"\t\t"<<usn1<<"\tYou have got program :  "<<y<<"\t"<<"\n";
				pack1();
				break;
				case 2:display1();
				break;
				case 3:search1();
				break;
				case 4:cout<<"\t\tEnter the usn\t:";
				cin>>usn1;
				cout<<"\n";
				y=rand()%max;
				if(y==0 || y==1)
					continue;
				cout<<"\t\t"<<usn1<<"\tYou have got program :  "<<y<<"\t"<<"\n";
				changeofprogram1();
				break;
				default:exit(0);
			}
		}
		break;
		default:exit(0);
	}
	return 0;
}	