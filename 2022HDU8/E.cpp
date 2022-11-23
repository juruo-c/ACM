#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

bool vis[N];
int p[N];

void prime()
{
    for (int i = 2; i < N; i ++ )
    {
        if (!vis[i]) p[++ p[0]] = i;
        for (int j = 1; j <= p[0] && i * p[j] < N; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}

int main()
{
    
    return 0;
}