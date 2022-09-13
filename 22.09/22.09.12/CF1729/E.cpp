#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

LL ask(LL a, LL b)
{
    cout << "? " << a << " " << b << endl << endl;
    cout.flush();
    LL res;
    cin >> res;
    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    LL cur = 3;
    while (true)
    {
        LL t1 = ask(1, cur);
        LL t2 = ask(cur, 1);
        if (t1 == -1 && t2 == -1)
        {
            cout << "! " << cur - 1 << endl;
            cout.flush();
            break;
        }
        if (t1 != t2)
        {
            cout << "! " << t1 + t2 << endl;
            cout.flush();
            break;
        }
        cur ++;
    }
    return 0;
}
