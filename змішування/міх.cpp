#include <iostream>
using namespace std;

//�-��� ��� ������ 
void swapEl(int* arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}

//�-��� ��� -����������
void myShakerSort(int* arr, int size)
{
	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		rightMark--;

		cout << "\nCircul: " << leftMark - 1; //  ������� ��������
	}
}
//����
int main()
{

	int size = 0;
	cout << "size_of_array: ";
	cin >> size;
	int* A = new int[size];

	for (int k = 0; k < size; k++)
	{
		A[k] = size - k; // ����� ������� �� ����������
		cout << A[k] << " | ";
	}

	myShakerSort(A, size); // ����������

	cout << "\nArray ofter mix:\n";
	for (int k = 0; k < size; k++)
	{
		cout << A[k] << " | ";
	}
	cout << endl;
	return 0;
}