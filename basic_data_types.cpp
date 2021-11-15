#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::fixed;
using std::setprecision;

int main(int argc, char const *argv[])
{
    int a;
    long long b;
    char c;
    float d;
    double e;
    cin >> a >> b >> c >> d >> e;
    cout << a << '\n'
         << b << '\n'
         << c << '\n';
    cout << fixed << setprecision(3) << d << '\n';
    cout << fixed << setprecision(9) << d << '\n';

    return 0;
}
