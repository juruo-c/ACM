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

const int N = 100005, mod = 1000000007;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        int s;
        scanf("%d", &s);
        vector<int> ans;
        for (int i = 9; i >= 1; i -- )
            if (s >= i) ans.push_back(i), s -= i;
        for (int i = ans.size() - 1; i >= 0; i -- )
            printf("%d", ans[i]);
        puts("");
    }
    return 0;
}
