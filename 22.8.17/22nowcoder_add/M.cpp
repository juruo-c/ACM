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

const int N = 100005, mod = 1000000007;

double goal[][5] = {{1, 1, 0.8, 0.5, 0}, {2, 2, 1.6, 1.0, 0}, {3, 3, 2.4, 1.5, 0}, {5, 5, 2.5, 2, 0}};
int c[5][5];
double ext[] = {1, 0.5, 0.4, 0.3, 0};

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    double A = 0, B = 0, A0 = 0, B0 = 0;
    for (int i = 1; i <= 4; i ++ )
    {
        for (int j = 0; j < 5; j ++ )
        {
            scanf("%d", &c[i][j]);
            A0 += c[i][j] * goal[i - 1][j], A += c[i][j] * goal[i - 1][0];
            if (i == 4) B0 += c[i][j] * ext[j], B += c[i][j] * ext[0];
        }
    }

    printf("%.10f\n", (A0 / A + B0 / B * 0.01) * 100);
    return 0;
}
