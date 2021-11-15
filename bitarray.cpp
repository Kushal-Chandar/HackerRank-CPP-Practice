#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long //range - 0 to 18,446,744,073,709,551,615

#define constraint 2147483648 // value of 2^31 // a constant value so we don't want to compute

/*
a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31) 

3 1 1 1
a[0] = 1 % 2^31; // 1
a[1] = ((a[0] * (1)) + 1) % 2^31 // 1 + 1 //2
a[2] = ((2 * 1) + 1) % 2^31 // 3

1,2,3

//* Better logic
n = 3; s = 1, p = 1, q = 1

if q >= 1 and  p = 1
    we are always adding the same positive number(ap) "before calculating modulo"
    i.e, all number will be unique
-> working of modulo: 0, 1, 2, 3, ......... , 2^31 - 1, 0, 1, 2....., 2^31 - 1
    let x be a very large number which is in ap with common difference 1
    if
    (x) % 2^31 is 0
    (x + 2^31) % 2^31 is also 0 // ((x % 2^31) + (2^31 % 2^31))% 2^31 // (0 + 0) % 2^31 = 0
    but x != x + 2^31;

    but if common difference is 0 (q is 0)
    (x) % 2^31 is 0
    (x + d) % 2^31 is also 0 
    then x = x + d (all terms will be same i.e not unique)
# checking the 2 terms is enough to check if all numbers are unique

if s is 0  and q = 0 all numbers will be same
if s is not 0 and p = 1 and q = 0 all numbers will be the same 

if s is 0  and q > 0 all numbers will be unique (they will be in ap, as we will be adding p in each iteration)
if s is not 0 and p = 0 and q >= 1 then also all numbers will be unique (as they will be in ap)
if s is not 0 and p is not 0 and q = 0 then also all numbers will be unique (as they will be in gp)
if s is not 0 and p is not 0 and q is not  0 then also all numbers will be unique (as they will be in agp)

? missing something|| when do the numbers become non unique ?
 
*/

//* Error put p and q in the wrong place - fixed 1 (added a mod function that returns positive mod result)

//* Numbers are in multiplication and grow quickly
//arr[i] will be overflowed ?
//? Floyd's algorithm - math problem

//* using unsingned long long to store numbers

//* array can get very big
//? corrected algorithm from a = a[i - 1] * 1 + (1 % 2^31) to a = ((a[i - 1] * 1) + 1) % 2 ^ 31;

int main()
{

    //* I/O optimisation
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Input
    ull n, s, p, q;
    cin >> n >> s >> p >> q;

    // variables for loop
    ull i = 0, unique;

    // 2 values will be updated in loop

    ull a;                   // current value of a[i]
    ull ap = s % constraint; // ap is a[i - 1]
    //a[0] will be previous value for a[1]

    for (i = 1; i <= n - 1; i++) //from i = 1 to i = n -1
    {
        a = ap * p + q;
        a %= constraint; //computing a[i] as per given psedo code

        if (a == ap) //if a[1] == a[0] (1 digit is unique)
        {
            unique = i;
            break;
        }
        ap = a;
    }
    if (i == n) //loop is completed, all digits are unique
    {
        unique = i;
    }
    cout << unique << '\n';

    /*
    missing a case where number become same after certain number of iterations
    if (q == 0 && ((s == 0) || (s != 0 && p == 1)))
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << n << '\n';
    } */

    return 0;
}
