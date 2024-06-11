#include<iostream>
#include <ctime>
using namespace std;
/*Визначити шаблонну функцію, яка за заданим масивом елементів – розбиває його на два масиви – 1) ті елементи, які більші за останній і 2) ті, які менші чи рівні за останній елемент масиву.
Функція повертає той масив, який має меншу кількість елементів.
Перевірити виконання функції для масиву цілих чисел та масиву рядків. 
Передбачити перехоплення виняткових ситуацій.*/
template  <typename T>
void break_sort(T * array, T end_element, size_t size, int border)
{
	if (border > size)
	{
		throw out_of_range("\nBorder>size\n")
	}
	size_t bigg_index = 0;
	size_t small_index = 0;
	T* small_array = new T[size];
	T* bigg_array = new T[size]
	for ( size_t i = 0; i < size; i++)
	{
		if (array[i] > end_element)
		{
			bigg_array[bigg_index] = array[i];
			bigg_index++;
		}
		else
		{
			small_array[smaller_index] = array[i];
			small_index++;
		}
	}
	if (bigg_index > small_index)
	{
		cout << "Elements smaller than " << end_element << " : ";
		for (size_t i = 0; i < small_index; i++)
			cout << small_array[i] << " ";
	}
	else
	{
		cout << "Elements bigger than " << end_element << " : ";
		for (size_t i = 0; i < bigg_index; i++)
			cout << bigg_array[i] << " ";
	}

	delete[] bigg_array;
	delete[] small_array;

}



int main()
{
	
	try
	{
		int int_array[10];
		srand(time(NULL));
		cout << "Int array: ";
		for (size_t i = 0; i < 10; i++)
		{
			int_array[i] = rand() % 10;
			cout << int_array[i] << " ";
		}
		cout << endl;
		string string_array[5];
		string_array[0] = "hstring";
		string_array[1] = "astring";
		string_array[2] = "pstring";
		string_array[3] = "wstring";
		string_array[4] = "string";

		cout << "String array: ";
		for (size_t i = 0; i < 5; i++)
		{
			cout << string_array[i] << " ";
		}
		cout << endl;
		break_sort(int_array, int_array[9], 10,9);
		cout << endl;

		break_sort(string_array, string_array[4], 5,4);
		cout << endl;

		return 0;
	}
	catch (out_of_range EXC)
	{
		cout << "\nOut of range\n" << EXC.what();
	}
	catch (exception excp)
	{
		cout  << excp.what();
	}
}   