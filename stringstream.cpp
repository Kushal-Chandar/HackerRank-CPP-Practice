#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
    stringstream s(str);
    vector<int> ret;
    char ch;
    int a;
    while ((s >> a))
    {
        s >> ch;
        ret.push_back(a);
    }
    return ret;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}