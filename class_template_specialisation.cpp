#include <iostream>
using namespace std;
enum class Fruit
{
    apple,
    orange,
    pear
};
enum class Color
{
    red,
    green,
    orange
};

template <typename T>
struct Traits;

// Define specializations for the Traits class template here.

template <>
struct Traits<Fruit>
{
    static string name(int);
};
template <>
struct Traits<Color>
{
    static string name(int);
};

string Traits<Color>::name(int a)
{
    if (a == 0)
    {
        return "red";
    }
    else if (a == 1)
    {
        return "green";
    }
    else if (a == 2)
    {
        return "orange";
    }
    else
    {
        return "unknown";
    }
}
string Traits<Fruit>::name(int a)
{
    if (a == 0)
    {
        return "apple";
    }
    else if (a == 1)
    {
        return "orange";
    }
    else if (a == 2)
    {
        return "pear";
    }
    else
    {
        return "unknown";
    }
}

int main()
{
    int t = 0;
    std::cin >> t;

    for (int i = 0; i != t; ++i)
    {
        int index1;
        std::cin >> index1;
        int index2;
        std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
