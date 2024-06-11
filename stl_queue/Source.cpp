#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> nums;
	cout << "Is the queue empty? ";

	// check if the queue is empty  
	if (nums.empty())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	cout << "Pushing elements..." << endl;

	// push element into the queue
	nums.push(1);
	nums.push(2);
	nums.push(3);
	nums.push(6);
	nums.push(9);

	cout << "Is the queue empty? ";

	// check if the queue is empty  
	if (nums.empty())
	{
		cout << "Yes";
	}
	else
	{
		cout << "No" << endl;
	}
	cout << "-------------------------------" << endl;

	// get the element at the front
	cout << "First element: " << nums.front() << endl;

	cout << "-------------------------------" << endl;

	// get the element at the back
	cout << "Last element: " << nums.back() << endl;

	cout << "-------------------------------" << endl;

	// get the size of the queue
	cout << "Size of the queue: " << nums.size() << endl;
	return 0;
}