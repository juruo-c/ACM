#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int char_to_int(char c)
{
    return c - '0';
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans;
        int i = n - 1;
        while (i >= 0)
        {
            if (s[i] == '0')
            {
                ans += char(char_to_int(s[i - 2]) * 10 + char_to_int(s[i - 1]) - 1 + 'a');
                i -= 3;
            }
            else ans += char(char_to_int(s[i]) - 1 + 'a'), i --;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}
