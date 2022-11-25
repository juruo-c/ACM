#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m;
int a[N], b[N];
bool vis[N];
int p[N];
vector<int> pos[N];
int bl[N], br[N];
int al[N], ar[N];

void getprime()
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

void getfactor(int P, int a)
{
    for (int i = 1; i <= p[0] && p[i] * p[i] <= a; i ++ )
        if (a % p[i] == 0)
        {
            pos[p[i]].push_back(P);
            while (a % p[i] == 0) a /= p[i];
        }
    if (a != 1) pos[a].push_back(P);
}

bool moveLeft(int i)
{
    if (al[i] == 1) return false;
    int x = al[i] - 1;
    if (ar[i] < br[x]) return false;
    al[i] = min(x, al[x]);
    ar[i] = max(ar[i], ar[x]);
    return true;
}

bool moveRight(int i)
{
    // cout << "i = " << i << " al[i] = " << al[i] << " ar[i] = " << ar[i] << endl;
    if (ar[i] == n) return false;
    int x = ar[i];
    if (al[i] > bl[x]) return false;
    al[i] = min(al[i], al[x + 1]);
    ar[i] = max(x + 1, ar[x + 1]);
    return true;
}

int main()
{
    getprime();
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        for (int i = 0; i < N; i ++ ) pos[i].clear();
        for (int i = 1; i <= p[0]; i ++ ) pos[p[i]].push_back(0);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]), ar[i] = al[i] = i;
        for (int i = 1; i < n; i ++ )
            scanf("%d", &b[i]);
        
        for (int i = 1; i <= n; i ++ )
            getfactor(i, a[i]);
        for (int i = 1; i <= p[0]; i ++ ) pos[p[i]].push_back(n + 1);

        for (int i = 1; i < n; i ++ )
        {
            int x = b[i];
            int t = upper_bound(pos[x].begin(), pos[x].end(), i) - pos[x].begin() - 1;
            bl[i] = pos[x][t];
            t = lower_bound(pos[x].begin(), pos[x].end(), i + 1) - pos[x].begin();
            br[i] = pos[x][t];
        }

        // for (int i = 1; i < n; i ++ )
        //     cout << bl[i] << " " << br[i] << endl;

        for (int i = 1; i <= n; i ++ )
        {
            while (true)
            {
                bool flag = moveLeft(i) || moveRight(i);
                if (!flag) break;
            }
        }

        // for (int i = 1; i <= n; i ++ )
        //     cout << al[i] << " " << ar[i] << endl;

        for (int i = 1; i <= m; i ++ )
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (al[x] <= y && y <= ar[x]) 
                puts("Yes");
            else puts("No");
        }

    }
    return 0;
}