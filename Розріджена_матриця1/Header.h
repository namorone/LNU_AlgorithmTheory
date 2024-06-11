#pragma once
#include <iostream>
#include <list>
#include <ctime>

using namespace std;

class SparseMatrix
{
private:
    list<int> values;
    list<int> rows;
    list<int> columns;
    int n;
public:
    SparseMatrix(int** array, int size)
    {
        n = size;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (array[i][j] != 0)
                {
                    values.push_back(array[i][j]);
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }
    }

    void push(int values_1, int columns_1, int rows_1)
    {
        auto row = rows.begin();
        auto col = columns.begin();
        auto val = values.begin();

        for (columns.begin(); col != columns.end(); ++col, ++row, ++val)
        {
            if (*col == columns_1 && *row == rows_1)
            {
                *val = values_1;
                return;
            }
        }
        rows.push_back(rows_1);
        columns.push_back(columns_1);
        values.push_back(values_1);
    }

    bool pop(int val)
    {
        bool was_in_matrix = false;
        auto row_1 = rows.begin();
        auto columns_1 = columns.begin();
        for (auto val_1 = values.begin(); val_1 != values.end(); ++val_1, ++columns_1, ++row_1)
        {
            if (*val_1 == val)
            {
                values.erase(val_1);
                rows.erase(row_1);
                columns.erase(columns_1);
                was_in_matrix = true;
                return was_in_matrix;
            }
        }
        return was_in_matrix;
    }

    int find_element(int col, int row)
    {
        auto row_2 = rows.begin();
        auto val_2 = values.begin();
        for (auto columns_2 = columns.begin(); columns_2 != columns.end(); ++columns_2, ++row_2, ++val_2)
        {
            if (*columns_2 == col && *row_2 == row)
            {
                return *val_2;
            }
        }
        return 0;
    }

    void print_sparce_matrix()
    {
        auto row = rows.begin();
        auto col = columns.begin();
        auto val = values.begin();
        int curr;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                row = rows.begin();
                col = columns.begin();
                val = values.begin();

                for (columns.begin(); col != columns.end(); ++col, ++row, ++val)
                {
                    if (*col == j && *row == i)
                    {
                        curr = *val;
                        break;
                    }
                    else
                    {
                        curr = 0;
                    }
                }
                cout << curr << '\t';
            }
            cout << endl;
        }
        cout << endl;
    }
};


void filling(int**& array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = 0;
        }
    }
    for (int i = 0; i < 50; i++)
    {
        int x = rand() % 10;
        int y = rand() % 10;
        array[x][y] = rand() % 100;
    }
}

bool is_sparse(int** array, int n)
{
    int counter = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (array[i][j] == 0)
            {
                ++counter;
            }
        }
    }
    return (counter > (n * n / 2));
}

void print_usual_matrix(int** array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << array[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

