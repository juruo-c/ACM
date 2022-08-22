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

int ask(int a, int b)
{
    printf("? %d %d\n", a, b);
    fflush(stdout); 
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        int n;
        scanf("%d", &n);
        vector<int> num;
        num.push_back(0);
        for (int i = 1; i <= (1 << n); i ++ ) num.push_back(i);

        while (num.size() > 2)
        {
            vector<int> tmp;
            tmp.push_back(0);
            if (num.size() == 3)
            {
                int ans = ask(num[1], num[2]);
                if (ans == 1) tmp.push_back(num[1]);
                else tmp.push_back(num[2]);
            }
            else 
            {
                for (int i = 1; i <= num.size() - 1; i += 4 )
                {
                    int a = num[i], b = num[i + 1], c = num[i + 2], d = num[i + 3];
                    int ans = ask(a, c);
                    if (ans == 1) 
                    {
                        ans = ask(a, d);
                        if (ans == 1) tmp.push_back(a);
                        else tmp.push_back(d);
                    }
                    else if (ans == 2)
                    {
                        ans = ask(c, b);
                        if (ans == 1) tmp.push_back(c);
                        else tmp.push_back(b);
                    }
                    else 
                    {
                        ans = ask(b, d);
                        if (ans == 1) tmp.push_back(b);
                        else tmp.push_back(d);
                    }
                }
            }
            num = tmp;
        }

        printf("! %d\n", num[1]);
        fflush(stdout);
    }
    return 0;
}
