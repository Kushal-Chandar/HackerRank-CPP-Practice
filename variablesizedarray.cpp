#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

int main(int argc, char const *argv[])
{
    int n, q;
    cin >> n >> q;
    int *arr[n]; //n integer pointers // int (*arr)[n] - pointer to an array of n ints
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int *temp = new int[x];
        for (int j = 0; j < x; j++)
        {
            cin >> temp[j];
        }
        arr[i] = temp;
    }
    int ans[q];
    for (int x = 0; x < q; x++)
    {
        int i, j;
        cin >> i >> j;
        ans[x] = arr[i][j];
    }
    for (int x = 0; x < q; x++)
    {
        cout << ans[x] << '\n';
    }

    return 0;
}
