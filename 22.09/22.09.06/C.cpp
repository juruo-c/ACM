#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <sstream>
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
    getchar();
    while (_ --)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);   
        string res;
        while (ss >> res)
            cout << char(res[0] + 'A' - 'a');
        cout << endl;
    }
    return 0;
}
