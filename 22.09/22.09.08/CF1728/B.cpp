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

int calc(vector<int>& a)
{
    int x = 0;
    for (int i = 0; i < a.size(); i ++ )
        if (x < a[i])
            x += a[i];
        else x = 0;
    return x;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            for (int i = n - 2; i >= 1; i -- )
                printf("%d ", i);
            printf("%d %d\n", n - 1, n);
        }
        else 
        {
            printf("%d %d %d ", 1, 2, 3);
            for (int i = n - 2; i >= 4; i -- )
                printf("%d ", i);
            printf("%d %d\n", n - 1, n);
        }
    }
    return 0;
}
