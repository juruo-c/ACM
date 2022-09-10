#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2005;

int n;
char s[N];
int f[N];

int a[] = {1, 6, 28, 88, 198, 328, 648};
int b[] = {8, 18, 28, 58, 128, 198, 388};

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    int ans = n * 10;
    for (int i = 0; i <= 6; i ++ )
        for (int j = n; j >= a[i]; j -- )
            f[j] = max(f[j], f[j - a[i]] + b[i]);
    cout << ans + f[n] << endl;

    return 0;
}
