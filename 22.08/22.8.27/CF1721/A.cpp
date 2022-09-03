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

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        vector<int> cnt(26, 0);
        char a, b, c, d;
        cin >> a >> b >> c >> d;
        cnt[a - 'a'] ++, cnt[b - 'a'] ++, cnt[c - 'a'] ++, cnt[d - 'a'] ++;
        
        set<int> s;
        for (int i = 0; i < 26; i++ )
            s.insert(cnt[i]);

        if (s.count(4)) cout << 0 << endl;
        else if (s.count(1) && s.count(3)) cout << 1 << endl;
        else if(s.count(1) && !s.count(3) && !s.count(2)) cout << 3 << endl;
        else if(s.count(2) && !s.count(1) && !s.count(3)) cout << 1 << endl;
        else if(s.count(2) && s.count(1)) cout << 2 << endl;

    }
    return 0;
}
