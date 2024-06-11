
#include <iostream>
using namespace std;

struct TableElem
{
    char key = char(0);
    int value = 0;
    TableElem() { }
    TableElem(char _key, int _value) : key(_key), value(_value) { }
};
class SimpleTable
{
    int MaxSize = 20;
    TableElem table[20];
    unsigned int empty_index = 0;
public:
    SimpleTable() { }

    void add_row(TableElem new_row) {
        table[empty_index] = new_row;
        empty_index++;
    }
    bool find_by_key(char key)
    {
        bool passed = false;
        for (int i = 0; i < empty_index; i++) {
            if (table[i].key == key) {
                cout << "key = " << table[i].key << "value = " << table[i].value << endl;
                passed = true;
            }
        }
        return passed;
    }

    void print()
    {
        for (int i = 0; i < empty_index; i++) {
            if (table[i].key != 0 && table[i].value != 0)
                cout << table[i].key << '\t' << table[i].value << endl;
        }
    }

    void pop(char key)
    {
        for (int i = 0; i < MaxSize; ++i)
        {
            if (table[i].key == key)
            {
                table[i].key = 0;
                table[i].value = 0;
            }
        }
    }
};

bool table_test()
{
    bool test_passed = true;
    SimpleTable tabl;
    TableElem element;
    element.key = 'A';
    element.value = 20;
    tabl.add_row(element);
    element.key = 'B';
    element.value = 30;
    tabl.add_row(element);
    element.key = 'C';
    element.value = 40;
    tabl.add_row(element);
    test_passed &= !tabl.find_by_key('D');
    test_passed &= tabl.find_by_key('B');
    return test_passed;
}

int main()
{
    cout << "Table test:" << endl;
    cout << "Test: " << (table_test() ? "passed" : "failed") << endl;
    cout << "-------------------------" << endl;
    SimpleTable tabl;
    TableElem element;
    element.key = 'A';
    element.value = 20;
    tabl.add_row(element);
    element.key = 'B';
    element.value = 30;
    tabl.add_row(element);
    element.key = 'C';
    element.value = 40;
    tabl.add_row(element);
    tabl.print();
    tabl.pop('A');
    tabl.print();
    tabl.find_by_key('C');
    return 0;
}