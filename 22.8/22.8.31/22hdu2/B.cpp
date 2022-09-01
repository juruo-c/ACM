#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>

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
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i ++ )
            if (s[i] == '(' || s[i] == ')' || (s[i] >= '0' && s[i] <= '9') || s[i] == ',' || s[i] == '-')
                cout << s[i];
        cout << endl;
    }
    return 0;
}
