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

const int N = 2005;

int n;
char s[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        int l = 1, r = n;
        while (l < r && s[l] == s[r]) l ++, r --;
        bool flag = true;
        for (int i = l; i <= r; i += 2)
            if (s[i] != s[i + 1])
            {
                flag = false;
                break;
            }
        if (flag) puts("Draw");
        else puts("Alice");
    }
    return 0;
}
