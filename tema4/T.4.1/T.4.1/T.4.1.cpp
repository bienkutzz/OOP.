#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	void setName(string name)
	{
		this->name = name;
	}
	void setAge(int age)
	{
		this->age = age;
	}

	string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}

	Person()
	{
		name = "UNSPECIFIED";
		age = 0;
	}
	Person(string name="UNSPECIFIED", int age=0)
	{
		this->name = name;
		this->age = age;
	}
};

class GroupOfFriends
{
private:
	string name;
	vector <Person> friends;
public:
	//setter
	void setName(string name)
	{
		this->name = name;
	}
	//getter
	string getName()
	{
		return name;
	}
	//constructor to construct a new group
	GroupOfFriends(string name = "Unknown")
	{
		this->name = name;
	}
	//methods
	void addFriend(Person person)
	{
		friends.push_back(person);
	}
	void updateFriend(string actualName, int actualAge, string updatedName, int updatedAge)
	{
		int i, size = friends.size();
		for(i=0; i<size; i++)
			if (actualName == friends[i].getName() && actualAge == friends[i].getAge())
			{
				friends[i].setName(updatedName);
				friends[i].setAge(updatedAge);
			}
	}
	void removeFriend(string actualName, int actualAge)
	{
		int i, size=friends.size();
		for(i=0; i<size; i++)
			if (actualName == friends[i].getName() && actualAge == friends[i].getAge())
			{
				friends.erase(friends.begin()+i);
				size--;
				return;
			}
	}
	void displayGroup()
	{
		int i, size=friends.size();
		for (i = 0; i < size; i++)
			cout << "Friend no. " << i << ": " << friends[i].getName()<<" and is "<<friends[i].getAge()<<" years old.\n";
	}

};

int main()
{
	GroupOfFriends group;
	group.addFriend(Person("Bianca", 16));
	group.addFriend(Person("Irina", 17));
	group.addFriend(Person("Iulian", 16));
	group.addFriend(Person("Denisa", 18));
	group.displayGroup();
	cout << "\n";

	group.updateFriend("Irina", 18, "Irina", 17);
	group.displayGroup();
	cout << "\n";

	group.removeFriend("Iulian", 16);
	group.displayGroup();
	cout << "\n";
}
