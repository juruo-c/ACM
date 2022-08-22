#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

struct Card
{
    int rank, suit;
    bool operator < (const Card& c) const
    {
        if (rank == c.rank) return suit < c.suit;
        return rank < c.rank;
    }

    int getrank(char c)
    {

    }

    int getsuit(char c)
    {
        
    }

    void read()
    {
        string s;
        cin >> s;
        rank = getrank(s[0]);
        suit = getsuit(s[1]);
    }    
}card[15];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        
    }
    return 0;
}
