#include <iostream>

using namespace std;
struct TableElem
{
    unsigned char key = char(0);
    int value = 0;
    TableElem()
    {
    }
    TableElem(char _key, int _value) :
        key(_key), value(_value)
    {
    }
};


class HashTable
{
    static const unsigned int MaxSize = 10;
    TableElem table[MaxSize];
    unsigned int get_hash(unsigned char key)
    {
        unsigned int hash;
        hash = key % MaxSize;
        return hash;
    }
public:
    HashTable()
    {
    }
    void add_row(TableElem new_row)
    {
        unsigned int hash = get_hash(new_row.key);
        int rehash = 0;
        while (table[(hash + rehash) % MaxSize].key != 0)
        {
            rehash++;
        }
        table[(hash + rehash) % MaxSize] = new_row;
    }
    bool find_by_key(char key)
    {
        bool found = false;
        unsigned int hash = get_hash(key);
        int rehash = 0;
        while (table[(hash + rehash) % MaxSize].key != key && table[(hash + rehash) % MaxSize].key != 0)
        {
            rehash++;
        }
        if (table[(hash + rehash) % MaxSize].key == key)
        {
            cout << "key = " << table[(hash + rehash) % MaxSize].key << "  value = " << table[(hash + rehash) % MaxSize].value << endl;
            found = true;
        }
        return found;
    }
    void print() {
        for (int i = 0; i < MaxSize; i++) {
            if (table[i].key != 0 && table[i].value != 0)
                cout << table[i].key << '\t' << table[i].value << endl;
        }
    }
    void pop(char key) {
        unsigned int hash = get_hash(key);
        int rehash = 0;

        while (table[(hash + rehash) % MaxSize].key != key)
        {
            rehash++;
        }

        table[(hash + rehash) % MaxSize].key = 0;
        table[(hash + rehash) % MaxSize].value = 0;

    }
};

bool table_test()
{
    bool test_passed = true;
    HashTable tabl;
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


void main()
{
    cout << "Table test" << endl;
    cout << "Test : " << (table_test() ? "passed" : "failed") << endl;
    cout << "-------------------------" << endl;
    HashTable tabl;
    TableElem element;

    element.key = 'A';
    element.value = 20;
    tabl.add_row(element);

    element.key = 'B';
    element.value = 50;
    tabl.add_row(element);

    element.key = 'J';
    element.value = 50;
    tabl.add_row(element);

    element.key = 'K';
    element.value = 50;
    tabl.add_row(element);

    cout << "Print:" << endl;
    tabl.print();

    cout << "Finding by key:" << endl;
    tabl.find_by_key('J');

    tabl.pop('B');

    cout << "Print:" << endl;
    tabl.print();
}