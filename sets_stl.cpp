#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char querytype;
        int element;
        cin >> querytype >> element;
        switch (querytype)
        {
        case '1':
            s.insert(element);
            break;
        case '2':
            s.erase(element);
            break;
        case '3':
            set<int>::iterator it = s.find(element);
            cout << (it != s.end() ? "Yes" : "No") << '\n';
            break;
        }
    }

    return 0;
}