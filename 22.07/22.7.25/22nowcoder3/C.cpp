#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 20000005, mod = 1000000007;

int n;
string s[N];

bool cmp(string& a, string& b)
{
    return a + b < b + a;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t = 1;
    while (t --)
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ )
            cin >> s[i];

        sort(s + 1, s + 1 + n, cmp);

        for (int i = 1; i <= n; i ++ )
            cout << s[i];
        cout << endl;

    }
    return 0;
}
