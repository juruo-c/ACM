#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m;
int a[N], b[N];
int p[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) p[i] = i, b[i] = i;

    vector<pair<int, int> > res;

    for (int i = 1; i <= m; i ++ )
        swap(p[b[a[i]]], p[b[a[i] + 1]]), swap(b[a[i]], b[a[i] + 1]), res.push_back({b[a[i]], b[a[i] + 1]});

    // for (int i = 1; i <= n; i ++ )
    //     cout << b[i] << " ";
    // cout << endl;

    // for (int i = 1; i <= n; i ++ )
    //     cout << p[i] << " ";
    // cout << endl;

    for (int i = 0; i < m; i ++ )
    {
        swap(p[res[i].first], p[res[i].second]);
        cout << p[1] << endl;
        swap(p[res[i].first], p[res[i].second]);
    }

    return 0;
}