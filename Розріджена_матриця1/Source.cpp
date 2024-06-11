#include"Header.h"
void main()
{
    int n = 10;
    srand(time(NULL));
    int** array = new int* [n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[n];
    }
    filling(array, n);
    cout << "Usual matrix:" << endl;
    print_usual_matrix(array, n);

    if (is_sparse(array, n))
    {
        SparseMatrix sp(array, n);
        cout << "Element we wanna push = 15, 25, 50" << endl;
        sp.push(15, 3, 2);
        sp.push(25, 4, 1);
        sp.push(50, 6, 5);
        sp.print_sparce_matrix();
        cout << "Try to find element(position: 4 column, 1 row) = " << sp.find_element(4, 1) << endl;
        cout << "Detele element #15" << endl;
        sp.pop(15);
        sp.print_sparce_matrix();
        cout << "Try to find element which was deleted = " << sp.find_element(3, 2) << endl;
    }
}