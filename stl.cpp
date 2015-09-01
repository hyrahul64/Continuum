#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>
#include <stdlib.h>


using namespace std;

class student
{
public:
	int id;
	char* name;
	static int nextid;

public:
	student(int stdid, char* stdname)
	{
		id = stdid;
		name = new char[100];
		strncpy(name,stdname,100);
	}

	student(const student& s)
	{
		id = s.id;
		name = new char[100];
		strncpy(name,s.name,100);
	}

	student& operator = (const student& s)
	{
		id = s.id;
		name = new char[100];
		strncpy(name,s.name,100);
	}
	~student()
	{
		delete []name;
	}
	static int giveid(){return ++student::nextid;}
	
};
int student::nextid = 0;

list<student> info;

void Add()
{
	printf("Enter Name of Student:");	
	char name[100];
	scanf("%s",name);
	student s(student::giveid(),name);
	info.push_back(s);
}

void Delete()
{
	printf("Enter id of student:");
	int id;
	scanf("%d",&id);
	for(list<student>::iterator it = info.begin(); it != info.end(); it++)
	{
		if(id == (*it).id)
		{
			info.erase(it);
			return;
		}	
	}
	printf("\nstudent not found\n");
}

void Find()
{
	printf("Enter id of student:");
	int id;
	scanf("%d",&id);
	for(list<student>::iterator it = info.begin(); it != info.end(); it++)
	{
		if(id == (*it).id)
		{
			printf("\nStudent Name:%s\n",(*it).name);
			return;
		}	
	}
	printf("\nstudent not found\n");
	
}

void Display()
{
	for(list<student>::iterator it = info.begin(); it != info.end(); it++)
	{
		printf("\nID:%d\tName:%s",(*it).id,(*it).name);
	}
}
int main()
{
	/*
	char name[100] = "Rahul Shah";
	student st(1,name);
	student st2(st);
	student st3(2,"Binal Shah");
	st3 = st2;*/

	int choice;
	
	do
	{
		//system("clear");
		printf("\nThis program manages student information in memory.\n");
		cout << "1.	Add Student" << endl;
		cout << "2.	Delete Student" << endl;
		cout << "3.	Find Student" << endl;
		cout << "4.	Display Students" << endl;
		cout << "Enter your option:";
		cin >> choice;
		//system("clear");
		
		switch(choice)
		{
			case 1:
				Add();
				break;
			case 2:
				Delete();
				break;
			case 3:
				Find();
				break;
			case 4:
				Display();
				break;
			default:
				return 0;
		}
	}while(choice < 5);
	return 0;
}


//TODO
//eclipse project
//make file
//unit testing
//class refactoring, different file

