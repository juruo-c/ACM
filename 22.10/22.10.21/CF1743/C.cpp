#include <iostream>
#define ZYCMH

using namespace std;

const int N = 200005;

int n;
char s[N];
int a[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        
        int ans = 0;
        int i = 1;
        while (i <= n)
        {
            if (s[i] == '1')
            {
                int sum = a[i - 1], mi = a[i - 1];
                int j = i;
                while (j <= n && s[j] == '1')
                {
                    sum += a[j];
                    mi = min(mi, a[j]);
                    j ++;
                }
                ans += sum - mi;
                i = j - 1;
            }
            i ++;
        }
        printf("%d\n", ans);
    }

    return 0;
}