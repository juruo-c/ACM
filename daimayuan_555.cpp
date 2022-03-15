//http://oj.daimayuan.top/course/10/problem/555

#include <iostream>
#include <map>

using namespace std;

const int N = 50, INF = 0x3f3f3f3f;

int n;
int a[N];
map<int, int> cnt;

bool check(int x)
{
    map<int, int> s;
    for (int i = 1; i <= n; i ++ )
    {
        s[(a[i] % x + x) % x] ++;
        if (s[(a[i] % x + x) % x] >= n / 2) return true;
    }
    return false;
}

int main()
{
    int T;cin >> T;
    while(T --)
    {
        cin >> n;
        cnt.clear();

        for (int i = 1; i <= n; i ++ )
        {
            cin >> a[i];
            cnt[a[i]] ++;
        }

        bool flag = false;
        for (auto x : cnt)
            if (x.second >= n / 2)
            {
                cout << - 1 << endl;
                flag = true;
                break;
            }
        if (flag)
            continue;

        int ans = 0;
        for (int i = 1; i <= n; i ++ )
            for (int j = i + 1; j <= n; j ++ )
            {
                int d = abs(a[i] - a[j]);
                for (int k = 1; k * k <= d; k ++ )
                {
                    if (d % k == 0)
                    {
                        if (check(k)) ans = max(ans, k);
                        if (check(d / k)) ans = max(ans, d / k);
                    }
                }
            }
        printf("%d\n", ans);

    }
    return 0;
}
