#include "Header.h"

void main()
{
    Stack<char> s;
    char arr[100] = { 0 };
    char out[100] = { 0 };

    cout << "Please enter an expression : ";
    cin >> arr;
    s.PolishEntry(arr, out);
    cout << "Polish expression: " << out << endl;
    cout << "Result: " << s.Calc(out) << endl;
}