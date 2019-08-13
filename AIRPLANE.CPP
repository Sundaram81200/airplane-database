#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<process.h>
#include<dos.h>

class file
{

	char cno[11];
	int age;
	char name[30];
	char dest[20];
	char airway[20];
public:
	void input();
	void show();
	char *getn()
	{
		return name;
	}
};file fileobj;

void file::input()
{
	cout<<"Enter your mobile number: ";
	cin>>cno;
	cout<<"Enter your age: ";
	cin>>age;
	cout<<"Enter your name: ";
	gets(name);
	cout<<"Enter your destination: ";
	gets(dest);
	cout<<"Enter the Airways: ";
	gets(airway);
}
void file::show()
{
	cout<<"Contact Number==> "<<cno<<endl;
	cout<<"Age ==> "<<age<<endl;
	cout<<"Name==> "<<name<<endl;
	cout<<"Destination==> "<<dest<<endl;
	cout<<"Airways==> "<<airway<<endl;
}
void Create();
void Add();
void Display();	//display all
void DisplayP(); //display a particular record
void Modify();
void Delete();

fstream fil;
void box()
{
gotoxy(14,2);
cout<<"ษอออออออออออออออออออออออออออออออออออออออออป";
gotoxy(14,3);
cout<<"บ";
gotoxy(56,3);
cout<<"บ";
gotoxy(14,4);
cout<<"บ";
gotoxy(56,4);
cout<<"บ";

gotoxy(14,5);
cout<<"บ";
gotoxy(56,5);
cout<<"บ";
gotoxy(14,6);
cout<<"บ";
gotoxy(56,6);
cout<<"บ";
gotoxy(14,7);
cout<<"บ";
gotoxy(56,7);
cout<<"บ";
gotoxy(14,8);
cout<<"บ";
gotoxy(56,8);
cout<<"บ";
gotoxy(14,9);
cout<<"บ";
gotoxy(56,9);
cout<<"บ";
gotoxy(14,10);
cout<<"บ";
gotoxy(56,10);
cout<<"บ";
gotoxy(14,11);
cout<<"บ";
gotoxy(56,11);
cout<<"บ";
gotoxy(14,12);
cout<<"บ";
gotoxy(56,12);
cout<<"บ";
gotoxy(14,13);
cout<<"บ";
gotoxy(56,13);
cout<<"บ";
gotoxy(14,14);
cout<<"บ";
gotoxy(56,14);
cout<<"บ";
gotoxy(14,15);
cout<<"ศอออออออออออออออออออออออออออออออออออออออออผ";

}
void startup()
{
 box();
gotoxy(17,4);
cout<<"  AIRPLANE DATABASE SYSTEM";
gotoxy(19,6);
cout<<"MADE BY: ";
gotoxy(19,8);
cout<<"Sundaram";

}

void menu()
{
	int opt;
	while(1)
	{
		clrscr();
		cout<<"MAIN MENU"<<endl;
		cout<<"============================"<<endl;
		cout<<"1.Create Data File"<<endl;
		cout<<"2.Display Record From Data File"<<endl;
		cout<<"3.Display Particular Record From Data File"<<endl;
		cout<<"4.Modify Paricular Record From Data File"<<endl;
		cout<<"5.Delete Particular Record From Data File"<<endl;
		cout<<"6.Exit From the Program"<<endl;
		cout<<"Enter your Option : "<<endl;
		cin>>opt;
		switch(opt)
		{
			case 1:

				clrscr();
				Create();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;


			case 2:

				clrscr();
				Display();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;

			case 3:

				clrscr();
				DisplayP();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;

			case 4:

				clrscr();
				Modify();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;

			case 5:

				clrscr();
				Delete();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;

			case 6:

				exit(0);

			default:

				cout<<"Wrong Choice....Press Key For View the Main Menu";
				getch();


		}
	}
}
void main()
{
  clrscr();
  startup();
  delay(4000);
  menu();
  getch();
}



void Create()		//Function to Create Data File
{
	char ch='y';
	fil.open("binary.dat",ios::app| ios::binary);
	while(ch=='y' || ch =='Y')
	{
		fileobj.input();
		fil.write((char*)&fileobj, sizeof(fileobj));
		cout<<endl;
		cout<<"Want to Continue.....";
		cin>>ch;
		cout<<"======================="<<endl;
	}
	fil.close();
}



void Display()		//Function to Display All Record from Data File
{
	fil.open("binary.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{

		while(fil.read((char*)&fileobj, sizeof(fileobj)))
		{
			fileobj.show();
			cout<<"Press Any Key....For Next Record"<<endl;
			cout<<"========================"<<endl;
			getch();
		}
	}
	fil.close();
}

void DisplayP()		//Function to Display particular Record from Data File
{
	char n[100];
	cout<<"Enter Name that should be searched:";
	gets(n);
	cout<<endl;
	cout<<"====================================="<<endl;
	fil.open("binary.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())==0)
			{
				fileobj.show();
				cout<<"Press Any Key...."<<endl;
				getch();
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	fil.close();
}
void Modify()		//Function to Modify Particular Record from Data File
{
	char n[30];
	cout<<"Enter Name that should be searched:";
	gets(n);
	cout<<endl;
	cout<<"============================"<<endl;
	fil.open("binary.dat",ios::in| ios::out|ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())==0)
			{
				fil.seekg(0,ios::cur);
				cout<<"Enter New Record.."<<endl;
				fileobj.input();
				fil.seekp(fil.tellg() - sizeof(fileobj));
				fil.write((char*)&fileobj, sizeof(fileobj));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	fil.close();
}

void Delete()		//Function to Delete Particular Record from Data File
{
	char n[100];
	cout<<"Enter Name that should be Deleted :";
	gets(n);
	int flag=0;
	ofstream o;
	o.open("new.dat",ios::app|ios::binary);
	fil.open("binary.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{

		while(fil.read((char*)&fileobj, sizeof(fileobj)))
		{
			if(strcmp(n,fileobj.getn())!=0)
			{
				o.write((char*)&fileobj, sizeof(fileobj));
			}
			else
			{
				 flag=1;
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	o.close();
	fil.close();
	if(flag==1)
    {
	cout<<"This Record has been Deleted"<<endl;
	getch();
     }
	else
	{
	 cout<<"No such Record Exists"<<endl;
	}
	remove("binary.dat");
	rename("new.dat", "binary.dat");
}
