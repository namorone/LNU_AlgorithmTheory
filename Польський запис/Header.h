#pragma once
#include <iostream>
using namespace std;

template <class Polish>
class Stack
{
private:
    struct Node
    {
        Node() :elem(0), next(0) {};
        Node* next;
        Polish elem;
    };
    Node* Index;
public:
    Stack() : Index(0) {};

    void push(Polish el)
    {
        Node* Temp;
        Temp = new Node;
        Temp->elem = el;
        if (Index == 0)
        {
            Index = Temp;
        }
        else
        {
            Temp->next = Index;
            Index = Temp;
        }
    }

    bool is_empty()
    {
        return (Index == NULL);
    }

    Polish pop()
    {
        Polish temp = Index->elem;
        Node* del = Index;
        Index = Index->next;
        delete del;
        return temp;
    }

    Polish top()
    {
        return Index->elem;
    }

    int prior(char ch)
    {
        switch (ch)
        {
        case ')': return 1;
        case '(': return 1;
        case '+': return 2;
        case '-': return 2;
        case '*': return 3;
        case '/': return 3;
        }
    }

    bool is_op(char c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    bool is_digit(char c)
    {
        return c >= '0' && c <= '9';
    }

    void PolishEntry(char* a, char* out)
    {
        Stack<char> st;
        int i = 0, j = 0;

        for (i = 0; a[i] != '\0'; i++)
        {
            if (is_digit(a[i]))
            {
                out[j] = a[i];
                ++j;
            }
            else
            {
                if (j != 0 && out[j - 1] >= '0' && out[j - 1] <= '9')
                {
                    out[j] = ' ';
                    ++j;
                }
                if (is_op(a[i]))
                {
                    if (st.is_empty() || prior(st.top()) < prior(a[i]))
                    {
                        st.push(a[i]);
                    }
                    else
                    {
                        while (!st.is_empty() && (prior(st.top()) >= prior(a[i])))
                        {
                            out[j++] = st.top();
                            st.pop();
                        }
                        st.push(a[i]);
                    }
                }
                else
                {
                    if (a[i] == '(')
                    {
                        st.push(a[i]);
                    }
                    else
                    {
                        if (a[i] == ')')
                        {
                            if (st.is_empty() || st.top() == '(')
                            {
                                cout << "Input error!" << endl;
                            }
                            else
                            {
                                while (st.top() != '(')
                                {
                                    out[j] = st.top();
                                    st.pop();
                                    j++;
                                }
                            }
                            st.pop();
                        }
                    }
                }
            }
        }
        while (!st.is_empty())
        {
            if (st.top() == '(')
            {
                cout << "Input error!" << endl;
            }
            else
            {
                out[j] = st.top();
                st.pop();
                j++;
            }
        }
    }
    int stoi1(string s)
    {
        int pos = s.size();
        int x = 1;
        int ans = 0;
        while (pos > 0)
        {
            pos--;
            ans += x * (s[pos] - '0');
            x *= 10;
        }
        return ans;
    }
    double Calc(string out)
    {
        int j = 0;
        double value1 = 0;
        double value2 = 0;
        Stack <double> st;


        char* pEnd = NULL;
        while (j < out.size())
        {
            if (out[j] == ' ')
            {
                ++j;
                continue;
            }
            if (out[j] >= '0' && out[j] <= '9')
            {
                string sq = "";
                while (j < out.size() && (out[j] >= '0' && out[j] <= '9'))
                    sq += out[j++];
                int iNum = stoi1(sq);

                st.push(iNum);
            }
            else
            {
                if (is_op(out[j]))
                {
                    value1 = st.top();
                    st.pop();
                    value2 = st.top();
                    st.pop();
                    switch (out[j])
                    {
                    case '+': st.push(value2 + value1);
                        break;
                    case '-': st.push(value2 - value1);
                        break;
                    case '*': st.push(value2 * value1);
                        break;
                    case '/': st.push(value2 / value1);
                        break;
                    }
                }
                ++j;
            }
        }
        return (st.top());
    }
};