#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Student
{
private:
	string name;
	int grade;
public:
	//setter
	void setName(string name)
	{
		this->name = name;
	}
	void setGrade(int grade)
	{
		this->grade = grade;
	}

	//getters
	string getName()
	{
		return name;
	}
	int getGrade()
	{
		return grade;
	}

	//constructor
	Student(string name = "Unspecified", int grade = 0)
	{
		this->name = name;
		this->grade = grade;
	}

};

class StudentList
{
private:
	list<Student> studentList;
public:
	void addStudent(Student student)
	{
		studentList.push_back(student);
	}

	void displayList()
	{
		list<Student>::iterator it;
		int counter = 0;
		for (it = studentList.begin(); it != studentList.end(); it++, counter++)
		{
			cout << "Student no. " << counter << ": " << it->getName() << " " << it->getGrade() << "\n";
		}
	}

	Student grade5()
	{
		list<Student>::iterator it;
		Student student = Student();
		for (it = studentList.begin(); it != studentList.end(); it++)
		{
			if (it->getGrade() == 5)
			{
				student.setName(it->getName());
				student.setGrade(it->getGrade());
				break;
			}
		}
		if (student.getGrade() == 0)
			student.setName("There is no student with grade 5.");
		return student;
	}
};

int main()
{
	StudentList list;
	list.addStudent(Student("Darius", 9));
	list.addStudent(Student("Alina", 8));
	list.addStudent(Student("Lorena", 7));
	//list.addStudent(Student("Ana", 5));
	list.addStudent(Student("Daniel", 10));
	list.addStudent(Student("Miruna", 6));

	list.displayList();
	cout << "\n";


	Student grade5;
	grade5 = Student();
	grade5 = list.grade5();
	cout << "The first student with grade 5 is: \n";
	cout << grade5.getName();
}
