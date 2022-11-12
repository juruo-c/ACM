#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 100;
const int INF = 1000000;

int n;
int matrix[N][N];

void dij(int s)
{
    int *dist = new int[N];
    bool *vis = new bool[N];
    int path[N][N];
    int len[N];

    // 初始化vis, dist
    memset(vis, false, sizeof vis);
    for (int i = 0; i < n; i ++ )
        dist[i] = matrix[s][i];
    
    // 初始化path
    memset(path, -1, sizeof path);
    for (int i = 0; i < n; i ++ )
        path[i][0] = s, path[i][1] = i, len[i] = 2;

    // 一开始s在集合中
    dist[s] = 0;
    vis[s] = true;

    // 开始循环
    for (int i = 0; i < n - 1; i ++ )
    {
        // 找与s距离最小的点
        int mi = INF, v;
        for (int j = 0; j < n; j ++ )
            if (!vis[j] && mi > dist[j])
            {
                v = j;
                mi = dist[j];
            }
         
        // 如果已经不存在该点了 退出循环
        if (mi == INF) break;
        // 把距离最近的点加入集合中
        vis[v] = true;

        // 使用v更新其他未在集合中的点的与s的距离 
        for (int j = 0; j < n; j ++ )
            if (!vis[j] && dist[j] > dist[v] + matrix[v][j])
            {
                dist[j] = dist[v] + matrix[v][j];
                // 更新路径
                len[j] = len[v] + 1;
                for (int k = 0; k < len[v]; k ++ )
                    path[j][k] = path[v][k];
                path[j][len[v]] = j;
            }
    } 

    // 输出结果
    for (int i = 0; i < n; i ++ )
        if (i != s)
        {
            printf("%d-%d-%d----[", s, i, dist[i]);
            for (int j = 0; j < len[i]; j ++ )
                printf("%d ", path[i][j]);
            printf("]\n");
        }

    delete[] dist;
    delete[] vis;
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                matrix[i][j] = INF;

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
            {
                int x;
                scanf("%d", &x);
                if (x) matrix[i][j] = x;
            }
        

        int s;
        scanf("%d", &s);

        dij(s);
    
    }


    return 0;
}