#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class Car
{
	string mark;
	string name;
	double volume;
public:
	virtual string getType() = 0;
	string getMark()
	{
		return mark;
	}
	double  getVolume()
	{
		return volume;
	}
	bool operator< (Car& car)
	{
		if (this->getVolume() < car.getVolume())
		{
			return true;
		}
		if (this->getVolume() == car.getVolume())
		{
			return this->getMark() < car.getMark();
		}
	}
	virtual void input(fstream& f)
	{
		f >> mark >> name >> volume;
	}
	virtual void print(fstream& f)
	{
		f << mark << " "<< name << " "<< volume<<" ";
	}
};

class Diesel : virtual public Car
{
	int volume_of_tank;
public:
	virtual string getType()
	{
		return "Diesel";
	}
	int getVolumeOFTank()
	{
		return volume_of_tank;
	}
	virtual void input(fstream& f)
	{
		Car::input(f);
		f >> volume_of_tank;
	}
	virtual void print(fstream& f)
	{
		Car::print(f);
		f << volume_of_tank;
	}
	friend fstream& operator>>(fstream& f, Diesel& car)
	{
		car.input(f);
	}
	friend fstream& operator<<(fstream& f, Diesel& car)
	{
		car.print(f);
	}
};

class Electrocar : virtual public Car
{
	double max_time_of_run;
	double time_of_charge;
public:
	virtual string getType()
	{
		return "Electrocar";
	}
	double GetTimeOFran()
	{
		return  max_time_of_run;
	}
	double  GetTimeOFCharge()
	{
		return time_of_charge;
	}
	virtual void input(fstream& f)
	{
		Car::input(f);
		f >> max_time_of_run>> time_of_charge;
	}
	virtual void print(fstream& f)
	{
		Car::print(f);
		f << max_time_of_run <<" " << time_of_charge;
	}
	friend fstream& operator>>(fstream& f, Electrocar& car)
	{
		car.input(f);
	}
	friend fstream& operator<<(fstream& f, Electrocar& car)
	{
		car.print(f);
	}
};

class Hibrid : public Diesel, public Electrocar
{
	int run_on_diesel;
	int run_on_electro;
public:
	virtual string getType()
	{
		return " Hibrid";
	}
	int GetRunOnDiesel()
	{
		return  run_on_diesel;
	}
	int  GetRunOnElectro()
	{
		return run_on_electro;
	}
	virtual void input(fstream& f)
	{
		Car::input(f);
		f >> run_on_diesel >> run_on_diesel;
	}
	virtual void print(fstream& f)
	{
		Car::print(f);
		f << run_on_diesel << " " << run_on_diesel;
	}
	friend fstream& operator>>(fstream& f, Hibrid& car)
	{
		car.input(f);
	}
	friend fstream& operator<<(fstream& f, Hibrid& car)
	{
		car.print(f);
	}
};

int main()
{   

	fstream f;
	fstream f2;
	fstream f3;
	f.open("Cars.txt");
	f2.open("Cars2.txt");
	int n = 3;
	Car** cars = new Car * [n];
	int temp;
	int i = 0;
	while (i != n)
	{
		f >> temp;
		switch (temp)
		{
		case 1: cars[i] = new Diesel;
			break;
		case 2: cars[i] = new Electrocar;
			break;
		case 3: cars[i] = new Hibrid;
			break;
		}
		cars[i]->input(f);
		i++;
	}
	f.close();
	for (int j = 0; j < n; j++)
	{
		cars[j]->print(f2);
	}
	for (int j = 0; j < n; j++)
	{
		if (dynamic_cast<Hibrid*>(cars[j]) != 0)
		{
			Hibrid* hybrid = dynamic_cast<Hibrid*>(cars[j]);
			cout << hybrid->GetRunOnDiesel()<< endl;
			cout << hybrid->GetRunOnElectro()<< endl;
		}
	}
	f2.close();
}
