#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

map<PII, bool> follow;

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i ++ )
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) follow[{x, y}] = true;
        else if(op == 2) follow[{x, y}] = false;
        else printf("%s\n", (follow[{x, y}] && follow[{y, x}] ? "Yes" : "No"));
    }
    return 0;
}