#include <iostream>
#include <string>
#include <list>
#include <time.h>
using namespace std;
// Story time: A COMMUTER wants to go to ADDRESS X. He looks up on Google Maps the closest BUS STATION to his place, and the closest one to his destination.
//He then checks the list of BUSSES that pass through both BUSS STATIONS and chooses the first one. Being the morning after a chilly summer night,
// the commuter realises the bus has a few MOSQUITOES inside. During the commute, the COMMUTER tries to kill as many MOSQUITOES as he can. He has a limit of 1/minute. 
// The time of the commute is measured by measuring the duration between the start of the trip and the end of the trip. A BUS is a CAR with an ENGINE and a DRIVER.
// What is the number of mosquitoes he kills during a trip?

class Mosquito
{
private:
	int mosquitonumber;
public:
	static int noMosquito;
	void setMosquitonumber(int mosquitoIDnumber)
	{
		this->mosquitonumber = mosquitoIDnumber;
	}

	int getMosquitonumber()
	{
		return  mosquitonumber;
	}

	Mosquito(int mosquitoIDnumber=0)
	{
		this->mosquitonumber = mosquitoIDnumber;
		mosquitoIDnumber++;
	}

	~Mosquito()
	{
		noMosquito--;
	}

};
class Address
{
private:
	string street;
	int number;
public:
	void setStreet(string street)
	{
		this->street = street;
	}
	void setNumber(int number)
	{
		this->number = number;
	}

	string getStreet()
	{
		return street;
	}
	int getnumber()
	{
		return number;
	}

	Address(string street = "UNKNOWN", int number = 0)
	{
		this->street = street;
		this->number = number;
	}
};
class Commuter
{
private:
	string name;
	Address address;
public:
	int static noCommuters;

	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}
	Address getAddress()
	{
		return address;
	}

	Commuter(Address address,string name = "UNKNOWN")
	{
		this->name = name;
		this->address = address;
		noCommuters++;
	}
	~Commuter()
	{
		noCommuters--;
	}
};
class Driver
{
private:
	string name;
	string driverLicence;
public:
	void setName(string name)
	{
		this->name = name;
	}
	void setDriverLicence(string driverLicence)
	{
		this->driverLicence = driverLicence;
	}

	string getName()
	{
		return name;
	}
	string getDriverLicence()
	{
		return driverLicence;
	}

	Driver(string name = "UNKNOWN", string driverLicence = "not ok")
	{
		this->name = name;
		this->driverLicence = driverLicence;
	}
};
class Engine
{
private:
	string type;
	int number;
public:
	void setType(string type)
	{
		this->type = type;
	}
	void setNumber(int number)
	{
		this->number = number;
	}

	string getType()
	{
		return type;
	}
	int getNumber()
	{
		return number;
	}

	Engine(string type = "UNKNOWN", int number = 0)
	{
		this->type = type;
		this->number = number;
	}
};
class Car
{
private:
	string model;
	string number;
	Engine engine;
public:
	void setModel(string model)
	{
		this->model = model;
	}
	void setNumber(string number)
	{
		this->number = number;
	}
	void setEngine(Engine engine)
	{
		this->engine = engine;
	}

	string getModel()
	{
		return model;
	}
	string getNumber()
	{
		return number;
	}
	Engine getEngine()
	{
		return engine;
	}

	Car(Engine engine, string model = "UNKNOWN", string number = "UNKNOWN")
	{
		this->model = model;
		this->number = number;
		this->engine = engine;
	}
	Car()
	{
		model = "UNKNOWN";
		number = "UNKNOWN";
	}
};
class Buss
{
private:
	Car car;
	Driver driver;
	list<Address> address;
	Mosquito mosquitoes;
public:
	void setCar(Car car)
	{
		this->car = car;
	}
	void setDriver(Driver driver)
	{
		this->driver = driver;
	}
	void addAddress(Address address)
	{
		this->address.push_back(address);
	}
	void setMosquitoes(Mosquito mosquitoes)
	{
		this->mosquitoes = mosquitoes;
	}

	Car getCar()
	{
		return car;
	}
	Driver getDriver()
	{
		return driver;
	}
	Mosquito getMosquitoes()
	{
		return mosquitoes;
	}

	Buss(Car car, Driver driver, Mosquito mosquitoes)
	{
		this->car = car;
		this->driver = driver;
		this->mosquitoes = mosquitoes;
	}

	bool searchAddress(Address address) //there is only one station on a street
	{
		list<Address>::iterator it;
		for (it = this->address.begin(); it != this->address.end(); it++)
		{
			if (it->getStreet() == address.getStreet())
				return true;
		}
		return false;
	}
};
class BussStation
{
private:
	Address address;
	list<Buss> buss;
public:
	void setAddress(Address address)
	{
		this->address = address;
	}
	void addBuss(Buss buss)
	{
		this->buss.push_back(buss);
	}
	
	Address getAddress()
	{
		return address;
	}

	BussStation(Address address)
	{
		this->address = address;
	}

	bool searchBuss(Car car, Driver driver)
	{
		list<Buss>::iterator it;
		for (it = this->buss.begin(); it != this->buss.end(); it++)
		{
			if (it->getCar().getNumber() == car.getNumber() && it->getDriver().getName() == driver.getName())
				return true;
		}
		return false;

	}
	bool searchAdress(BussStation destination)
	{
		list<Buss>::iterator it;
		for (it = buss.begin(); it != buss.end(); it++)
			if (destination.searchBuss(it->getCar(), it->getDriver()) == true)
			{
				return true;
			}
		return false;
		
	}
};

int Mosquito::noMosquito = 0;
int Commuter::noCommuters = 0;
int main()
{
	Mosquito mosquito = Mosquito(10);
	Address mainCharacterLocation = Address("Tudor Vladimirescu", 74);
	Commuter mainCharacter = Commuter(mainCharacterLocation, "TOM");
	BussStation mainCharacterBS(mainCharacterLocation);

	cout << "Our main character today is " << mainCharacter.getName() << ". He is currently on street " << mainCharacter.getAddress().getStreet() << " at number "<<mainCharacter.getAddress().getnumber()<<".\n";
	system("PAUSE");
	Address destination = Address("Mihai Eminescu", 54);
	BussStation mainCharacterDBS(destination);
	cout << "He wants to get to his girlfriend who lives on street " << destination.getStreet() << " at number " << destination.getnumber()<<" and he wants to take the buss.\n";
	system("PAUSE");
	Engine engine = Engine("X5", 233);
	Car car = Car(engine, "Volvo", "DJ13KLM");
	Driver driver = Driver("Mihai", "ok");
	Buss buss1 = Buss(car, driver, mosquito);
	Buss buss2 = Buss(car, driver, mosquito);
	Buss buss3 = Buss(car, driver, mosquito);
	
	mainCharacterBS.addBuss(buss2);
	mainCharacterBS.addBuss(buss3);
	
	mainCharacterDBS.addBuss(buss2);

	buss2.addAddress(mainCharacterLocation);
	buss2.addAddress(destination);
	

	cout << "He looks up the list of busses that pass through his station and checks them one by one to see if any go through his girlfriend's station.\n";
	system("PAUSE");
	bool found= mainCharacterBS.searchAdress(mainCharacterDBS);
	
	if (found == false)
	{
		cout << "There is no buss for Tom to take to reach his destination.\n";
		system("PAUSE");
	}
	else
	{
		clock_t start = clock();
		cout << " Tom has found a buss! He hops on the buss and starts his trip.\n";
		system("PAUSE");
		cout << " He suddenly feels a 'bzzz' in his ears and that's when he notices how many mosquitoes were in the buss.\n";
		system("PAUSE");
		cout << "He thinks:'What if i kill as many as i can until i reach my destination? That might help the future passangers!'\n";
		system("PAUSE");
		cout << " So he starts killing every mosquito he can find.\n";
		system("PAUSE");
		cout << "Time passes...\n";
		system("PAUSE");
		clock_t end = clock();
		int time = int(end - start) / CLOCKS_PER_SEC;
		if (time > mosquito.getMosquitonumber())
			time = mosquito.getMosquitonumber();
		cout << "Tom has reached his destination. He realised he could only kill one mosquito per minute. During the time spend in the buss he has killed " << time << " mosquitoes!\n";
	}

}