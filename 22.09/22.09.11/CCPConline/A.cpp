#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct Hand
{
    int card_cnt[15];
}peo[4], desk, last;

void clear_last()
{
    for (int i = 1; i <= 13; i ++ )
        last.card_cnt[i] = 0;
}

void clear_desk()
{
    for (int i = 1; i <= 13; i ++ )
        desk.card_cnt[i] = 0;
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int x;
    for (int i = 0; i < 4; i ++ )
    {
        for (int j = 0; j < 13; j ++ )
        {
            scanf("%d", &x);
            peo[i].card_cnt[x] ++;
        }
    }

    int m;
    scanf("%d", &m);
    int y, p = 0;
    for (int i = 1; i <= m; i ++ )
    {
        char op;
        scanf("\n%c", &op);
        if (op == 'S')
        {
            clear_last();
            scanf("%d%d", &x, &y);
            for (int j = 0; j < y; j ++ )
            {
                int ay;
                scanf("%d", &ay);
                peo[p].card_cnt[ay] --;
                desk.card_cnt[ay] ++;
                last.card_cnt[ay] ++;
            }
        }
        else if(op == '!')
        {
            clear_last();
            scanf("%d", &y);
            for (int j = 0; j < y; j ++ )
            {
                int ay;
                scanf("%d", &ay);
                peo[p].card_cnt[ay] --;
                desk.card_cnt[ay] ++;
                last.card_cnt[ay] ++;
            }
        }
        else if(op == '?')
        {
            if (last.card_cnt[x] == y)
            {
                for (int j = 1; j <= 13; j ++ )
                    peo[p].card_cnt[j] += desk.card_cnt[j];
            }
            else 
            {
                for (int j = 1; j <= 13; j ++ )
                    peo[(p - 1 + 4) % 4].card_cnt[j] += desk.card_cnt[j];
            }
            clear_desk();
        }
        p = (p + 1) % 4;
    }

    for (int i = 0; i < 4; i ++ )
    {
        for (int j = 1; j <= 13; j ++ )
        {
            int cnt = peo[i].card_cnt[j];
            while (cnt -- )
                printf("%d ", j);
        }
        puts("");
    }

    return 0;
}