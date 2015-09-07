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

