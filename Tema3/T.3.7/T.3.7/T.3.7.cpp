#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int age;
	int group;
	float grade;

public:
	static int noStudents; //counts the number of instances of Student

	void setName(string input)
	{
		name = input;
	}
	void setAge(int input)
	{
		age = input;
	}
	void setGroup(int input)
	{
		group = input;
	}
	void setGrade(float input)
	{
		grade = input;
	}

	string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}
	int getGroup()
	{
		return group;
	}
	float getGrade()
	{
		return grade;
	}

	Student() //constructors
	{
		noStudents++;
		name = "Unknown";
		age = 0;
		group = 0;
		grade = 0;
	}
	Student(string inputName)
	{
		noStudents++;
		name = inputName;
		age = 0;
		group = 0;
		grade = 0;
	}
	Student(string inputName, int inputAge)
	{
		noStudents++;
		name = inputName;
		age = inputAge;
		group = 0;
		grade = 0;
	}
	Student(string inputName, int inputAge, int inputGroup)
	{
		noStudents++;
		name = inputName;
		age = inputAge;
		group = inputGroup;
		grade = 0;
	}
	Student(string inputName, int inputAge, int inputGroup, float inputGrade)
	{
		noStudents++;
		name = inputName;
		age = inputAge;
		group = inputGroup;
		grade = inputGrade;
	}
	~Student() //destructor
	{
		noStudents--;
	}
};
int Student::noStudents = 0;

int main()
{

	Student *student1, *student2, *student3, *student4, *student5, *student6;
	student1 = new Student("Alina", 17, 3, 6.50);
	student2 = new Student("Dan", 18, 2, 7.25);
	student3 = new Student("Mihai", 18, 1, 9.33);
	student4 = new Student("Daniela", 16, 2, 8.45);
	student5 = new Student("Cristi", 19, 1, 8.30);
	student6 = new Student("Mircea", 18, 3, 6.75);
	cout << "The number of students is " << Student::noStudents<<"\n";
	delete student4;
	cout << "The number of students is " << Student::noStudents << "\n";

}
