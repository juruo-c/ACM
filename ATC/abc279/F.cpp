#include <bits/stdc++.h>

using namespace std;

const int N = 600005;

int n, m;
int id[N], num[N], pos[N];
vector<int> box[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        box[i].push_back(i), num[i] = i, pos[i] = i, id[i] = i;

    for (int i = 1; i <= m; i ++ )
    {
        int op, x, y;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d", &x, &y);
            if (box[pos[x]].size() < box[pos[y]].size())
                swap(id[pos[x]], id[pos[y]]), swap(pos[x], pos[y]);
            for (auto ball : box[pos[y]])
                box[pos[x]].push_back(ball), num[ball] = pos[x];
            box[pos[y]].clear();
        }
        else if(op == 2)
        {
            scanf("%d", &x);
            box[pos[x]].push_back(++ n);
            num[n] = pos[x];
        }
        else if(op == 3)
        {
            scanf("%d", &x);
            printf("%d\n", id[num[x]]);
        }
    }

    return 0;
}