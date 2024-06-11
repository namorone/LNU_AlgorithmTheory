#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

void parseFile(string const& path, vector<string>& u)
{
    ifstream file1(path);

    string s;

    while (!file1.eof())
    {
        file1 >> s;
        u.emplace_back(s);
    }

    file1.close();
}

char const* Markov(vector<string> const& u, vector<string> const& v, string& word)
{
    int i = 0;
    unsigned long ind = 0;
    string temp;

    while (i < u.size()) {
        if (strstr(word.data(), u[i].data())) {
            ind = word.find(u[i]);

            for (unsigned j = 0; j < word.size(); ++j) {
                if ((j < ind) || (j > ind + u[i].size() - 1)) {
                    temp += word[j];
                }
                else {
                    temp += v[i];
                    j += u[i].size() - 1;
                }
            }
            word = temp;
            temp = "";
            i = 0;
        }
        else
            ++i;
    }

    return word.data();
}

void main()
{
    vector<string> u;
    vector<string> v;

    string const left = "left_subs.txt";
    string const right = "right_subs.txt";

    parseFile(left, u);
    parseFile(right, v);

    string s = "aaboop";
    cout << "Expression = " << s << endl;

    char const* res = Markov(u, v, s);

    cout << "Result = " << res << endl;
}