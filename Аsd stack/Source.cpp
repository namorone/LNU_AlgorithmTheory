#include <iostream>


using namespace std;


class CharStack
{
private:
	//максимальний розмір контейнера для спрощення
	static const unsigned int MAX_SIZE = 100;
	//контейнер де буде зберігатися стек без проштовхування
	char container[MAX_SIZE];
	//індекс першої вільної комірки
	unsigned int index_of_empty_element = 0;
public:
	void push(char new_element)
	{
		//todo:check if not full!!!
		if (index_of_empty_element == 101) cout << "Full";
		container[index_of_empty_element] = new_element;
		index_of_empty_element++;
	}

	char pop()
	{
		//todo:check if not empty!!!
		if (index_of_empty_element == -1) cout <<"  empty";
		char ret_val = container[index_of_empty_element - 1];
		index_of_empty_element--;
		return ret_val;
	}
	bool is_empty()
	{
		bool to_return = index_of_empty_element == 0;
		return to_return;
	}


};


//перевірити стек is_empty, повернути true якщо все ок
bool stack_test1()
{
	bool test_passed = true;
	CharStack stack1;
	test_passed = test_passed && stack1.is_empty() == true;
	stack1.push('b');
	test_passed = test_passed && stack1.is_empty() == false;
	stack1.pop();
	test_passed = test_passed && stack1.is_empty() == true;
	return test_passed;
}


//перевірити стек push pop, повернути true якщо все ок
bool stack_test2()
{
	bool test_passed = true;
	CharStack stack1;
	stack1.push('b');
	stack1.push('c');

	test_passed = test_passed && stack1.pop() == 'c';
	test_passed = test_passed && stack1.pop() == 'b';
	return test_passed;
}


int main()
{
	cout << "Stack program" << endl;
	cout << "Test 1:" << (stack_test1() ? "passed" : "failed") << endl;
	cout << "Test 2:" << (stack_test2() ? "passed" : "failed") << endl;


	return 0;
}