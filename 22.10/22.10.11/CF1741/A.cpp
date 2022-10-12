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

map<char, int> rk;

char cmp(char a, char b)
{
    if (rk[a] > rk[b]) return '>';
    else return '<';
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    rk['S'] = 1;
    rk['M'] = 2;
    rk['L'] = 3;
    int _; scanf("%d", &_);
    while (_ --)
    {
        string a, b;
        cin >> a >> b;
        int la = a.size(), lb = b.size();
        if (a[la - 1] == b[lb - 1])
        {
            if (a[la - 1] == 'M') cout << '=' << endl;
            else if (a[la - 1] == 'L')
            {
                if (la == lb) cout << "=" << endl;
                else if( la < lb ) cout << "<" << endl;
                else cout << ">" << endl;
            }
            else 
            {
                if (la == lb) cout << "=" << endl;
                else if( la < lb ) cout << ">" << endl;
                else cout << "<" << endl;               
            }
        }
        else 
            cout << cmp(a[la - 1], b[lb - 1]) << endl;
    }
    return 0;
}
