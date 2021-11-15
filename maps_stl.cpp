#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;
    map<string, int> name_marks;
    for (int i = 0; i < q; i++)
    {
        char querytype;
        string name;
        int marks;
        cin >> querytype >> name;
        switch (querytype)
        {
        case '1':
        {
            cin >> marks;
            map<string, int>::iterator it = name_marks.find(name);
            if (it == name_marks.end())
            {
                name_marks.insert(make_pair(name, marks));
            }
            else
            {
                (it->second) += marks;
            }
            break;
        }
        case '2':
        {
            name_marks.erase(name);
            break;
        }
        case '3':
        {
            cout << name_marks[name] << '\n';
            break;
        }
        }
    }

    return 0;
}
