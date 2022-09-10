#include<fstream>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int choice,y;
	char usn[20];
	for(;;)
	{
	cout<<"enter the subject\n";
	cout<<"1.FS\n2.ST\n3.exit\n";
	cin>>choice;
	srand(time(0));
	switch(choice)
	{
		case 1:
		cout<<"\nenter the usn\n";
		cin>>usn;
		cout<<usn<<"\nYou've got the Progrm\n";
		int max;
		max=9;//set the upper bound to generate the random number
   cout <<rand()%max;
   cout<<"\nAll the best\n";
   break;
		case 2:
		while(1)
		{
			
			cout<<"enter the usn\n";
			cin>>usn;
			cout<<usn<<"\tYou've got the Progrm\n";
			int max;
			max=13; //set the upper bound to generate the random number
			srand(time(0));
			y=rand()%max;
			if(y==0||y==1)
			{
				continue;
			}
			else
			{
				cout<<"youve got the program\n"<<y;
				break;
			}
		}
		break;
		case 3:exit(0);
	}
}
	return 0;
}