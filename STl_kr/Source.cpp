#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
/*а) Дана функція f повинна змінити контейнер l1  таким чином: всі символи, які представляють цифри замінити на символ a.
Дописати який саме <Алгоритм> треба використати і визначити необхідний функціональний об`єкт Fun, який використовується у вказаному алгоритмі для  виконання завдання.

void f(vector<char> l1, char  a)

{

       //Task A
            <Алгоритм>(l1.begin(),l1.end(),l1.begin(), Fun(a));

       //Task Б

}

Б) Використовуючи алгоритми STL , Дописати функцію так:  з контейнера l1 видалити всі елементи, які повторюються, залишивши лише по одному екземпляру.
Вивести у потік змінений контейнер.*/

bool Fun()
{

};
void f(vector<char> l1, char  a)

{

    //Task A
 
    bool IsNumber(vector s)
    {
        //size_t x = 0;
        if(s.begin(), s.end(), [](char i)
            { return (i <= '9') && (i >= '0'); });

        for (size_t i = 0; i < s.length(); i++)
        {
            if (!isdigit(s[i]))
                return false;
        }
        return true;

        /*if (x == s.length())
            return true;
        else
            return false;*/
    }
    swap(l1.begin(), l1.end(), l1.begin(), Fun(a));

    //Task Б

}