#include<iostream>
#include<ctime>
#include<fstream>

using namespace std;

struct Milk
{
    string name;
    double fattiness;

    friend istream& operator>>(istream& is, Milk& milk)
    {
        is >> milk.name >> milk.fattiness;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Milk& milk)
    {
        os << milk.name << " " << milk.fattiness;
        return os;
    }
};

template<typename T>
class Object
{
private:
    T object;
    tm date_of_production;
    tm expiration_date;
public:
    friend istream& operator>>(istream& is, Object& object)
    {
        is >> object.object >> object.date_of_production.tm_mday >> object.date_of_production.tm_mon >> object.date_of_production.tm_year;
        is >> object.expiration_date.tm_mday >> object.expiration_date.tm_mon >> object.expiration_date.tm_year;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Object& object)
    {
        char fulldate[50];
        os << object.object << " ";
        if (strftime(fulldate, sizeof(fulldate), "%d/%m/%y", &object.date_of_production));
        os << fulldate << " ";
        if (strftime(fulldate, sizeof(fulldate), "%d/%m/%y", &object.expiration_date));
        os << fulldate << endl;
        return os;
    }

    tm GetExpirationDate()
    {
        return expiration_date;
    }

    T GetObject()
    {
        return object;
    }
};

int main()
{
    int n;
    fstream File_1;
    fstream File_2;
    fstream File_3;
    File_1.open("file_1.txt");
    File_2.open("file_2.txt");
    File_3.open("file_3.txt");
    File_1 >> n;
    Object<string>* arr = new Object<string>[n];
    for (size_t i = 0; i < n; i++)
    {
        File_1 >> arr[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        File_3 << arr[i].GetObject() << ": " << arr[i].GetExpirationDate().tm_mday << "/" << arr[i].GetExpirationDate().tm_mon << "/" << arr[i].GetExpirationDate().tm_year << endl;
    }

    File_3 << "\t---Milk---" << endl;

    int m;
    File_2 >> m;
    Object<Milk>* arr2 = new Object<Milk>[m];
    for (size_t i = 0; i < m; i++)
    {
        File_2 >> arr2[i];
    }

    for (size_t i = 0; i < m; i++)
    {
        File_3 << arr2[i].GetObject().name << ": " << arr2[i].GetExpirationDate().tm_mday << "/" << arr2[i].GetExpirationDate().tm_mon << "/" << arr2[i].GetExpirationDate().tm_year << endl;
    }

    delete[] arr;
    delete[] arr2;
    File_1.close();
    File_2.close();
    File_3.close();

    return 0;
}