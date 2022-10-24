#include <iostream>
#include <algorithm>
#include <cstring>
#define ZYCMH

using namespace std;

typedef long long LL;

const int N = 500005;

int num[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif 

    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i ++ )
    {
        int a;
        scanf("%d", &a);
        num[a] ++;
    }

    bool flag = true;
    LL cur = num[1];
    for (int i = 2; i <= x; i ++ )
    {
        if (cur % i)
        {
            flag = false;
            break;
        }
        else cur /= i, cur += num[i];
    }


    if (flag) puts("Yes");
    else puts("No");


    return 0;
}