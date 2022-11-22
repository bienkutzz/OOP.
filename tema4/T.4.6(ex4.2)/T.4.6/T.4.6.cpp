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

	void sortList()
	{

		studentList.sort([](Student student1, Student student2)-> bool {if (student1.getGrade() <= student2.getGrade()) return true; return false; });
	}

	Student maxGradeStudent()
	{
		list<Student>::iterator it;
		Student maxGradeStudent = Student();
		for (it = studentList.begin(); it != studentList.end(); it++)
		{
			if (maxGradeStudent.getGrade() < it->getGrade())
			{
				maxGradeStudent.setName(it->getName());
				maxGradeStudent.setGrade(it->getGrade());
			}


		}
		return maxGradeStudent;
	}
};

int main()
{
	StudentList list;
	list.addStudent(Student("Otilia", 5));
	list.addStudent(Student("Marius", 9));
	list.addStudent(Student("Andreea", 6));
	list.addStudent(Student("Irina", 7));
	list.addStudent(Student("Gabriel", 2));
	list.addStudent(Student("Bianca", 10));

	list.displayList();
	cout << "\n";

	//list.sortList();
	//list.displayList();
	//cout << "\n";

	Student maxGrade;
	maxGrade = Student();
	maxGrade = list.maxGradeStudent();
	cout << "Student " << maxGrade.getName() << " has maximum grade, which is " << maxGrade.getGrade();
}
