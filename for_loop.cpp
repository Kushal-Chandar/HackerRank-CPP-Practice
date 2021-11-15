#include <iostream>
using std::cin;
using std::cout;
using std::string;

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    string options[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = a; i <= b; i++)
    {
        if (i > 9)
        {
            cout << ((i % 2 == 0) ? "even" : "odd") << '\n';
        }
        else
        {
            cout << options[i - 1] << '\n';
        }
    }

    return 0;
}
