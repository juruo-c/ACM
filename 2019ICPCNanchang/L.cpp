#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 105;

int n;
LL b[N][N];
struct Team
{
    LL score, goal, conceded;
    LL diff;
    int id;
    bool operator < (const Team& b) const
    {
        if (score == b.score)
            return diff > b.diff;
        return score > b.score;
    }
}a[N];

int getscore(LL sa, LL sb)
{
    if (sa > sb) return 3;
    else if (sa == sb) return 1;
    else return 0;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            scanf("%lld", &b[i][j]);
    
    if (n == 1)
    {
        puts("1");
        return 0;
    }

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            if (i != j)
            {
                a[i].goal += b[i][j];
                a[i].conceded += b[j][i];
                a[i].score += getscore(b[i][j], b[j][i]);
            }
        }

    for (int i = 1; i <= n; i ++ )
        a[i].id = i, a[i].diff = a[i].goal - a[i].conceded;

    sort(a + 1, a + 1 + n);

    if (a[1].score == a[2].score && a[1].diff == a[2].diff)
        puts("play-offs");
    else 
        printf("%d\n", a[1].id);


    return 0;
}