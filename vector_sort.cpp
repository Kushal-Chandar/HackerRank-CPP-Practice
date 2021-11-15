#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vecInt;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        vecInt.push_back(a);
    }
    sort(vecInt.begin(), vecInt.end());
    for (int i = 0; i < size; i++)
    {
        cout << vecInt[i] << ' ';
    }

    return 0;
}
