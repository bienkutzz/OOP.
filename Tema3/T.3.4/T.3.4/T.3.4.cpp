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

	Student()
	{
		name = "Unknown";
		age = 0;
		group = 0;
		grade = 0;
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

Student maxGrade(Student students[], int n)
{
	Student maxGrade;
	for (int i = 0; i < n; i++)
	{
		if (students[i].getGrade() > maxGrade.getGrade()) //compare the grades, save the student with the greatest grade
			maxGrade = students[i];
	}
	return maxGrade;
}
int main()
{
	Student students[20], maxGradeStudent;
	students[0] = Student("Irina", 17, 2, 8.50);
	students[1] = Student("Oana", 17, 1, 6.25);
	students[2] = Student("Cristian", 18, 3, 7.44);
	students[3] = Student("Liviu", 19, 2, 3.40);
	students[4] = Student("Maria", 18, 1, 9.30);
	students[5] = Student("Carmen", 16, 2, 9.90);
	maxGradeStudent = maxGrade(students, 6);
	cout << "The name of the student is " << maxGradeStudent.getName() << ", of age " << maxGradeStudent.getAge() << ", from group ";
	cout << maxGradeStudent.getGroup() << ", with grade " << maxGradeStudent.getGrade();
}
