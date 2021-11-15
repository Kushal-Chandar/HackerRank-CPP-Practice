#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, q;
    cin >> n;
    vector<int> sorted_int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sorted_int[i];
    }
    cin >> t;
    while (t--)
    {
        cin >> q;
        vector<int>::iterator it = lower_bound(sorted_int.begin(), sorted_int.end(), q);
        if (*it == q)
        {
            cout << "Yes " << it - sorted_int.begin() + 1 << '\n';
        }
        else
        {
            cout << "No " << it - sorted_int.begin() + 1 << '\n';
        }
    }

    return 0;
}