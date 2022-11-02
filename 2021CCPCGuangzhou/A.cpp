#include <iostream>

using namespace std;

const int N = 1000005;

int d[N];

int main() 
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i ++ )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        d[u] ++, d[v] ++;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
        if (d[i] > 3)
        {
            puts("0");
            return 0;
        }
        else if(d[i] == 3) cnt ++;
    
    printf("%d\n", n - cnt);

    return 0;
}