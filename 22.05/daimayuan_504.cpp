//http://oj.daimayuan.top/course/10/problem/504

#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 200005;

unordered_map<int, int> last;
int n, a[N];
int f[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);

    int ans = 0, id = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int t = a[i] - 1;
        f[i] = f[last[t]] + 1;
        if (f[i] > ans) ans = f[i], id = a[i];
        else if (f[i] == ans) id = min(id, a[i]);
        last[a[i]] = i;
    }

    printf("%d\n", ans);
    for (int i = id - ans + 1; i <= id; i ++ )
        printf("%d ", i);
    return 0;
}
