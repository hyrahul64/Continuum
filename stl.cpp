#include <student.h>


using namespace std;


int main()
{

	student_manager sm;
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
				sm.Add();
				break;
			case 2:
				sm.Delete();
				break;
			case 3:
				sm.Find();
				break;
			case 4:
				sm.Display();
				break;
			default:
				return 0;
		}
	}while(choice < 5);
	return 0;
}


//TODO
//eclipse project

