#include <iostream>
#include <vector>
using namespace std;

#define FUNCTION(x, sign)  \
    void x(int &n, int &a) \
    {                      \
        if (a sign n)      \
        {                  \
            n = a;         \
        }                  \
    }

#define INF 100000000 //input constraint // individual element cannot be above 100000000
#define foreach(x, i) for (int i = 0; i < x.size(); i++)

#define io(v) cin >> v
#define toStr(x) #x

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    foreach (v, i)
    {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach (v, i)
    {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) << ' ' << ans;
    return 0;
}