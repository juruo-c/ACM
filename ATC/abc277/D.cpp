#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m;
int a[N * 2];
long long s[N * 2];

bool check(int j)
{
    return a[j] == a[j - 1] || a[j] == (a[j - 1] + 1) % m;
}

int main()
{
    scanf("%d%d", &n, &m);
    long long sum = 0;
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]), sum += a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++ ) a[i + n] = a[i];

    for (int i = 1; i <= 2 * n; i ++ )
        s[i] = s[i - 1] + a[i];

    long long ans = 0;
    for (int i = 1, j = 1; i <= n; i ++ )
    {
        if (j < i) j = i;
        while (j + 1 <= 2 * n && j + 1 - i + 1 <= n && check(j + 1)) j ++;
        ans = max(ans, s[j] - s[i - 1]);
    }

    printf("%lld\n", sum - ans);

    return 0;
}