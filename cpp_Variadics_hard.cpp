#include <iostream>
using namespace std;

/* 
* Recursive Solution
template <bool a>
int reversed_binary_value()
{
    return a;
}

// Enter your code for reversed_binary_value<bool...>()
template <bool a, bool b, bool... d> //param pack
int reversed_binary_value()
{
    return (reversed_binary_value<b, d...>() << 1) + a;
}
//for 0,0,1
// 1. 01 << 1 + 0; // 2 << 1 + 0 = //4;
// 2. 1 << 1 + 0; 2 + 0;
// 3. 1;
*/

template <bool... digits>
int reversed_binary_value()
{
    int num = 0;
    int mulbase = 1;
    bool boolarray[] = {digits...};
    for (int i = 0; i < sizeof...(digits); i++)
    {
        num += boolarray[i] ? mulbase : 0;
        mulbase *= 2;
    }
    return num;
}

template <int n, bool... digits>
struct CheckValues
{
    static void check(int x, int y)
    {
        //? cannot understand how is it feed bools
        //(need to learn template meta programming to understand)
        CheckValues<n - 1, false, digits...>::check(x, y); //until n is 0 class itself
        CheckValues<n - 1, true, digits...>::check(x, y);
        //if n becomes 0 it will call the other check
    }
};

template <bool... digits>
struct CheckValues<0, digits...> //template specialisation?
{
    static void check(int x, int y)
    {
        //we need to feed digit... will bools for below function to work
        int z = reversed_binary_value<digits...>();
        std::cout << (z + 64 * y == x);
    }
};

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i != t; ++i)
    {
        int x, y;
        cin >> x >> y;
        CheckValues<6>::check(x, y); // n is 6;
        cout << "\n";
    }
}
