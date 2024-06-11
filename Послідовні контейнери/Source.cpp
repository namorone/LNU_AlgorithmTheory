#include<iostream>
#include<fstream>
#include<deque>
#include<string>
#include <algorithm>

using namespace std;
/*
Використати контейнер deque та його ітератор для роботи з масивами даних. Також реалізувати перехоплення винятків. 

В текстовому файлі знаходяться дані про оплачені рахунки за газ та воду.
Для рахунків за газ – це прізвище абонента, кількість прописаних осіб, оплачена сума;
для рахунків за воду – це прізвище абонента, останній показ лічильника, оплачений об’єм води, оплачена сума.

зчитати дані з файлу у контейнер, відобразити на екрані (і записати у відповідні файли) окремо рахунки за газ, окремо за воду.
При цьому рахунки за газ повинні бути посортовані у порядку спадання кількості прописаних осіб, а рахунки за воду – у алфавітному порядку.

 вивести у окремий файл 5 найбільших оплат за воду
 */ 



class Gas 
{   
public:
	string surname;
	unsigned int amount_paid;
	unsigned int registered_persons;
public:
	void Input(ifstream& f)
	{
		f >> surname >> registered_persons >> amount_paid;
	}

	void Print(ofstream& f)
	{
		f << surname << ' ' << registered_persons << " " << amount_paid << endl
			<< endl;
	}

	bool operator>(Gas gas)
	{
		if (this->registered_persons > gas.registered_persons)
		{
			return true;
		}
		return false;
	}

	bool operator<(Gas gas)
	{
		if (this->registered_persons < gas.registered_persons)
		{
              return true;
		}
		return false;
	}
};
class Water
{   
public:
	string surname;
	unsigned int amount_paid;
	unsigned int meter_readings;
	unsigned int paid_volum;
public:
	void Input(ifstream& f)
	{
		f >> surname >> meter_readings >> paid_volum >> amount_paid;
	}

	void Print(ofstream& f)
	{
		f << surname << " " << meter_readings << " " << paid_volum << " " << amount_paid << endl
			<< endl;
	}

	bool operator>(Water w)
	{
		if (this->surname > w.surname)
		{
			return true;
		}return true;
		return false;
	}

	bool operator<(Water w)
	{
		if (this->surname < w.surname)
		{
			return true;
		}	
		return false;
	}
};
int main()
{
    ifstream MyReadFile("Bills.txt");
    ofstream GasFile("Gas_bills.txt");
    ofstream WaterFile("Water_bills.txt");
    ofstream Greatest("The_greatest.txt");
    
    deque<Gas> gas_deque;
    deque<Water> water_deque;

    char type;

    while (!MyReadFile.eof())
    {
        MyReadFile >> type;

        if (type == 'g')
        {
            Gas gas_element;
            gas_element.Input(MyReadFile);
            gas_deque.push_back(gas_element);
        }
        else
        {
            Water water_element;
            water_element.Input(MyReadFile);
            water_deque.push_back(water_element);
        }
    }

    for (deque<Gas>::iterator it = gas_deque.begin(); it != gas_deque.end(); ++it)
    {
        for (deque<Gas>::iterator it2 = gas_deque.begin(); it2 != gas_deque.end(); ++it2)
        {
            Gas g1, g2;
            g1 = *it;
            g2 = *it2;
            if (g1 > g2)
                swap(*it, *it2);
        }
    }

    for (deque<Gas>::iterator it = gas_deque.begin(); it != gas_deque.end(); ++it)
    {
        Gas g;
        g = *it;
        g.Print(GasFile);
    }

    for (deque<Water>::iterator it = water_deque.begin(); it != water_deque.end(); ++it)
    {
        for (deque<Water>::iterator it2 = water_deque.begin(); it2 != water_deque.end(); ++it2)
        {
            Water w1, w2;
            w1 = *it;
            w2 = *it2;
            if (w1 < w2)
                swap(*it, *it2);
        }
    }

    for (deque<Water>::iterator it = water_deque.begin(); it != water_deque.end(); ++it)
    {
        Water w;
        w = *it;
        w.Print(WaterFile);
    }

    for (deque<Water>::iterator it = water_deque.begin(); it != water_deque.end(); ++it)
    {
        for (deque<Water>::iterator it2 = water_deque.begin(); it2 != water_deque.end(); ++it2)
        {
            Water w1, w2;
            w1 = *it;
            w2 = *it2;
            if (w1.amount_paid > w2.amount_paid)
                swap(*it, *it2);
        }
    }

    for (deque<Water>::iterator it = water_deque.begin(); it < water_deque.begin() + 5; ++it)
    {
        Water w;
        w = *it;
        w.Print(Greatest);
    }

    MyReadFile.close();
    GasFile.close();
    WaterFile.close();
    Greatest.close();

    
   
    return 0;
}
