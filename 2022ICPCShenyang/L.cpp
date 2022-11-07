#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int n, m;
int hpa[10], hpb[10];
int a[10], b[10];
int atTimes[10], btTimes[10];

struct Node
{
    int id;
    int times;
    bool operator < (const Node& b) const 
    {
        if (times == b.times)
            return id < b.id;
        return times < b.times;
    }
}tmp[10];

double ap, bp;

int check()
{
    /*
        -1: continue;
        0: tie
        1: Alice win
        2: Bob win
    */
    if (n && m) return -1;
    if (!n && !m) return 0;
    if (!n && m) return 2;
    if (!m && n) return 1;
}

void dfs(double p, int who)
{
    int t = check();
    if (t != -1)
    {
        if (t == 1) ap += p;
        else if (t == 2) bp += p;
        return;
    }
    if (who == 0)
    {   
        int cnt = 0;
        for (int i = 0; i < N; i ++ )
            if (hpa[i] > 0) tmp[++ cnt] = {i, atTimes[i]};
        sort(tmp + 1, tmp + 1 + cnt);
        int id = tmp[1].id;

        for (int i = 0; i < M; i ++ )
        {
            if (hpb[i] <= 0) continue;
            
            hpa[id] -= b[i], hpb[i] -= a[id];
            atTimes[id] ++;
            int tm = m;
            if (hpa[id] <= 0) n --;
            if (hpb[i] <= 0) m --;
            
            dfs(p / tm, 1);
            
            if (hpa[id] <= 0) n ++;
            if (hpb[i] <= 0) m ++;
            hpa[id] += b[i], hpb[i] += a[id];
            atTimes[id] --;
        }
    }
    else 
    {
        int cnt = 0;
        for (int i = 0; i < M; i ++ )
            if (hpb[i] > 0) tmp[++ cnt] = {i, btTimes[i]};
        sort(tmp + 1, tmp + 1 + cnt);
        int id = tmp[1].id;
        
        for (int i = 0; i < N; i ++ )
        {
            if (hpa[i] <= 0) continue;
            
            hpb[id] -= a[i], hpa[i] -= b[id];
            btTimes[id] ++;
            int tn = n;
            if (hpa[i] <= 0) n --;
            if (hpb[id] <= 0) m --;
            
            dfs(p / tn, 0);
            
            if (hpa[i] <= 0) n ++;
            if (hpb[id] <= 0) m ++;
            hpa[i] += b[id], hpb[id] += a[i];
            btTimes[id] --;
        }
    }
}

void solve(double p)
{
    if (n == m)
        dfs(p * 0.5, 0), dfs(p * 0.5, 1);
    else if (n > m)
        dfs(p, 0);
    else dfs(p, 1);
}

int main()
{
    // freopen("1.in", "r", stdin);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i ++ )
        scanf("%d", &a[i]), hpa[i] = a[i];
    for (int i = 0; i < M; i ++ )
        scanf("%d", &b[i]), hpb[i] = b[i];

    n = N, m = M;
    solve(1);
    printf("%.10f\n%.10f\n%.10f\n", ap, bp, 1 - ap - bp);

    return 0;
}