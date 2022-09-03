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

int calc(int a, int b, int c)
{
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    res.push_back(c);
    return res[1];
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    
    // int n, x;
    // cin >> n >> x;
    // if (n == x)
    // {
    //     puts("YES");
    //     for (int i = 1; i <= 2 * n - 1; i ++ )
    //         printf("%d\n", i);
    // }
    // else puts("NO");

    int n = 4;
    vector<int> a(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i ++ )
    {
        a[i] = i + 1;
    }

    do
    {
        vector<vector<int> > b(n);
        b[n - 1] = a;
        for (int i = n - 2; i >= 0; i -- )
            for (int j = 0; j < 2 * (i + 1) - 1; j ++ )
                b[i][j] = calc(b[i + 1][j], b[i + 1][j + 1], b[i + 1][j + 2]);  
        
        for (int i = 0; i < n; i ++ )
        {
            for (int j = 0; j < n - i - 1; j ++ )
                cout << " ";
            for (int j = 0; j < 2 * (i + 1) - 1; j ++ )
                cout << b[i][j];
            cout << endl;
        }
            
    } while (next_permutation(a.begin(), a.end()));
    


    return 0;
}
