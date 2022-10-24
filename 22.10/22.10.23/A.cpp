#include <iostream>
#include <algorithm>
#include <cstring>
#define ZYCMH

using namespace std;

int n;
char s[105];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif 

    int _;
    scanf("%d", &_);
    while(_ --)
    {
        int c0 = 0, c1 = 0;
        scanf("%d", &n);
        scanf("%s", s);
        for (int i = 0; s[i]; i ++ )
            if (s[i] == 'Q') c0 ++;
            else if (c0) c0 --;
        
        printf("%s\n", c0 ? "No" : "Yes");
    }

    return 0;
}