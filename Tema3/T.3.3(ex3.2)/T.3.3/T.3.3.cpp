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
	void setName(string input) //setters
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

	string getName() //getters
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
		name="Unknown";
		age=0;
		group=0;
		grade=0;
	}
	Student(string inputName)
	{
		name = inputName;
		age = 0;
		group = 0;
		grade = 0;
	}
	Student(string inputName, int inputAge)
	{
		name = inputName;
		age = inputAge;
		group = 0;
		grade = 0;
	}
	Student(string inputName, int inputAge, int inputGroup)
	{
		name = inputName;
		age = inputAge;
		group = inputGroup;
		grade = 0;
	}
	Student(string inputName, int inputAge, int inputGroup, float inputGrade)
	{
		name = inputName;
		age = inputAge;
		group = inputGroup;
		grade = inputGrade;
	}
};

int main()
{
	Student* student1, student2;
	student1 = new Student("Catalin", 17, 3, 8.45);
	student2 = Student("Bianca");

	cout << "Student one is named " << student1->getName() << ", has " << student1->getAge();
	cout << " years, is in group " << student1->getGroup() << " and grade is " << student1->getGrade() << "\n";

	cout << "Student two is named " << student2.getName() << ", has " << student2.getAge();
	cout << " years, is in group " << student2.getGroup() << " and grade is " << student2.getGrade() << "\n\n";

	student2.setAge(18);
	student2.setGroup(2);
	student2.setGrade(9.70);

	cout << "Student two is named " << student2.getName() << ", has " << student2.getAge();
	cout << " years, is in group " << student2.getGroup() << " and grade is " << student2.getGrade() << "\n";
}
