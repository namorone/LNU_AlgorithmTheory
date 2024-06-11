#include "Header.h"


void main()
{
    PriorityQue<int> q;
    q.push(1, 3);
    q.push(2, 4);
    q.push(3, 5);
    q.push(4, 1);
    q.push(8, 2);

    cout << "Print priority queue:" << endl;
    q.print();

    cout << "Returned back element = " << q.back() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    q.back();
    
   
}