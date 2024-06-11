#pragma once
#include <iostream>
using namespace std;

template <typename T>
class PriorityQue
{
private:
    struct Node
    {
        T value;
        int priority;
        Node* next;
        Node* prev;
        Node(const T& value_, int priority_, Node* next_ = nullptr, Node* prev_ = nullptr)
            : value(value_),
            priority(priority_),
            next(next_),
            prev(prev_) {}
    };
    Node* tail;
    Node* head;
    int size;

public:
    PriorityQue() :
        tail(nullptr),
        head(nullptr),
        size(0) {
    }
    void push(const T& value_, int priority_)
    {
        if (!isempty())
        {
            size++;
            Node* insert = new Node(value_, priority_);
            Node* ptrToInsert = nullptr;
            for (Node* i = tail; i != nullptr; i = i->prev)
            {
                if (i->priority < insert->priority)
                {
                    ptrToInsert = i;
                }
                else
                {
                    break;
                }
            }
            if (ptrToInsert == nullptr)
            {
                tail->next = insert;
                insert->prev = tail;
                tail = insert;
            }
            else
            {
                insert->next = ptrToInsert;
                if (ptrToInsert->prev)
                {
                    insert->prev = ptrToInsert->prev;
                    ptrToInsert->prev->next = insert;
                }
                else
                {
                    head = insert;
                }
                ptrToInsert->prev = insert;
            }
        }
        else
        {
            size++;
            head = tail = new Node(value_, priority_);
        }
    }


    T back()
    {
        if (!isempty())
        {
            return tail->value;
        }
        else
        {
            cout << "Cannot return value. Queue is empty" << endl;
            return 0;
        }
    }

    T pop()
    {
        if (!isempty())
        {
            size--;
            T returnValue = tail->value;
            Node* ptrToDel = tail;
            tail = tail->prev;
            delete ptrToDel;
            return returnValue;
        }
        else
        {
            cout << "Cannot delete value. Queue is empty" << endl;
            return 0;
        }
    }

    bool isempty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void print()
    {
        Node* ptr;
        ptr = tail;

        cout << "Queue is :" << endl;
        cout << "Item  Priority" << endl;

        while (ptr != NULL)
        {
            cout << ptr->value << "         " << ptr->priority << endl;
            ptr = ptr->prev;
        }
    }
};
