#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 410;
LL a[N], b[N], c[N];
LL w[N][N], la[N], lb[N], p[N];
bool va[N], vb[N];
int mat[N];
int n, last[N];
LL upd[N];
bool dfs(int x, int fa)
{
    va[x] = 1;
    for(int y = 1; y <= n; y ++)
        if(!vb[y])
        {
            if(la[x] + lb[y] - w[x][y] == 0)
            {
                vb[y] = 1, last[y] = fa;
                if(!mat[y] || dfs(mat[y], y))
                {
                    mat[y] = x;
                    return true;
                }
            }
            else if(upd[y] > la[x] + lb[y] - w[x][y])
            {
                upd[y] = la[x] + lb[y] - w[x][y];
                last[y] = fa;
            }
        }
    return false;
}
LL km()
{
    for(int i = 1; i <= n; i ++)
    {
        la[i] = -(1 << 30), lb[i] = 0;
        for(int j = 1; j <= n; j ++)
            la[i] = max(la[i], w[i][j]);
    }
    for(int i = 1; i <= n; i ++)
    {
        memset(va, 0, sizeof va), memset(vb, 0, sizeof vb);
        memset(last, 0, sizeof last), memset(upd, 0x7f, sizeof upd);
        int st = 0; mat[0] = i;
        while(mat[st])
        {
            LL delta = 1LL << 60;
            if(dfs(mat[st], st)) break;
            for(int j = 1; j <= n; j ++)
                if(!vb[j] && upd[j] < delta)
                {
                    delta = upd[j];
                    st = j;
                }
            for(int j = 1; j <= n; j ++)
            {
                if(va[j]) la[j] -= delta;
                if(vb[j]) lb[j] += delta;
                else upd[j] -=delta;
            }
            vb[st] = 1;
        }    
        while(st)
        {
            mat[st] = mat[last[st]];
            st = last[st];
        }
    }
    LL ans = 0;
    for(int i = 1; i <= n; i ++) ans += w[mat[i]][i];
    return ans;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i ++) scanf("%lld", &p[i]);
    for(int i = 1; i <= n; i ++) scanf("%lld", &b[i]);
    for(int i = 1; i <= n; i ++) scanf("%lld", &c[i]);
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            for(int k = 1; k <= n; k ++)
            {
                if(a[i] < b[j] + c[k]) w[i][j] += p[j];
            }
        }
    }
    printf("%lld\n", km());
    return 0;
}