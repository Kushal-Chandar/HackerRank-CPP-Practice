#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    cin >> a;
    vec.erase(vec.begin() + a - 1);
    cin >> a >> n;
    vec.erase(vec.begin() + a - 1, vec.begin() + n - 1);
    cout << vec.size() << '\n';
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }

    return 0;
}
