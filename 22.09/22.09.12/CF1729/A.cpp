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

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int t2 = abs(b - c) + c - 1;
        int t1 = a - 1;
        if (t1 < t2) cout << 1 << endl;
        else if(t1 > t2) cout << 2 << endl;
        else cout << 3 << endl;
    }
    return 0;
}
