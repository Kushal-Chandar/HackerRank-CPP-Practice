#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    cout << a.size() << ' ' << b.size() << '\n'
         << a + b << '\n';
    swap<char>(a[0], b[0]); //? std swap template function
    cout << a << ' ' << b << '\n';
    return 0;
}