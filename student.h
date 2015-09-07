#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <list>

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

class student_manager
{

	std::list<student> m_info;

public:
	void Add();
	void Delete();
	void Find();
	void Display();
};

void student_manager::Add()
{
	printf("Enter Name of Student:");	
	char name[100];
	scanf("%s",name);
	student s(student::giveid(),name);
	m_info.push_back(s);
}

void student_manager::Delete()
{
	printf("Enter id of student:");
	int id;
	scanf("%d",&id);
	for(std::list<student>::iterator it = m_info.begin(); it != m_info.end(); it++)
	{
		if(id == (*it).id)
		{
			m_info.erase(it);
			return;
		}	
	}
	printf("\nstudent not found\n");
}

void student_manager::Find()
{
	printf("Enter id of student:");
	int id;
	scanf("%d",&id);
	for(std::list<student>::iterator it = m_info.begin(); it != m_info.end(); it++)
	{
		if(id == (*it).id)
		{
			printf("\nStudent Name:%s\n",(*it).name);
			return;
		}	
	}
	printf("\nstudent not found\n");
	
}

void student_manager::Display()
{
	for(std::list<student>::iterator it = m_info.begin(); it != m_info.end(); it++)
	{
		printf("\nID:%d\tName:%s",(*it).id,(*it).name);
	}
}

