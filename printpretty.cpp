#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--)
    {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;

        /* Enter your code here */
        //* printing hex in capital letters - fixed
        //* double integer part exceeded range of int so using long long - fixed
        cout << resetiosflags(ios::uppercase)
             << setw(0) << setbase(16) << hex << showbase << (long long)A << '\n'
             << setw(0xf) << std::right << setfill('_')
             << showpos << fixed << setprecision(2) << B << '\n'
             << setiosflags(ios::uppercase)
             << noshowpos
             << setfill(' ') << scientific << setprecision(9) << C << '\n';
    }
    return 0;
}