#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define endl '\n' //this will replace endl with '\n' improves performance

bool start_up() // declaring out side main
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return false;
}
bool d = start_up();

template <typename T>
class AddElements
{
private:
  T x;

public:
  AddElements(T x) : x(x) {}
  T add(T);
};
template <typename T>
T AddElements<T>::add(T l)
{
  return x + l;
}

template <>
class AddElements<string>
{
private:
  string x;

public:
  AddElements(string x) : x(x) {}
  string concatenate(string);
};
//? No need to use template for defination of Template specialisation class functions outside the class
string AddElements<string>::concatenate(string l)
{
  return x + l;
}

int main()
{
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++)
  {
    string type;
    cin >> type;
    if (type == "float")
    {
      double element1, element2;
      cin >> element1 >> element2;
      AddElements<double> myfloat(element1);
      cout << myfloat.add(element2) << endl;
    }
    else if (type == "int")
    {
      int element1, element2;
      cin >> element1 >> element2;
      AddElements<int> myint(element1);
      cout << myint.add(element2) << endl;
    }
    else if (type == "string")
    {
      string element1, element2;
      cin >> element1 >> element2;
      AddElements<string> mystring(element1);
      cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
