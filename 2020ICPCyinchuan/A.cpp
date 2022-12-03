#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 105;

int x[N], y[N], z[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> x[i] >> y[i] >> z[i];

    set<PII> sx, sy, sz;
    for (int i = 1; i <= n; i ++ )
    {
        sx.insert({y[i], z[i]});
        sy.insert({x[i], z[i]});
        sz.insert({x[i], y[i]});
    }

    int cx = sx.size(), cy = sy.size(), cz = sz.size();
    if (cx >= cy && cx >= cz) cout << "X" << endl;
    else if(cy > cx && cy >= cz) cout << "Y" << endl;
    else cout << "Z" << endl;

    return 0;
}