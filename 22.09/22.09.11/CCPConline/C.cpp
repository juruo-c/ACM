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

LL t,a,b,cnt;
int main()
{

    cin >> t;
    while (t --)
    {
        cin >> a >> b;
        if ((a % 2) && (b % 2 == 0))
            cout << "1 1" << endl;
        else if((a % 2 == 0) && b % 2)
            cout << "1 0" << endl;
        else 
        {
            LL t = 2;
            int ans = 0, r = 1;
            while (true)
            {   
                if (b % t)
                {
                    cout << r << " " << ans << endl;
                    break;
                }
                t <<= 1;
                ans ^= 1;
                if (a % t)
                {
                    cout << r << " " << ans << endl;
                    break;
                }
                ans ^= 1;
                t <<= 1;
                r ++;
            }
        }
    }

    return 0;
}
