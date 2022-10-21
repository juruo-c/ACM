#include <iostream>
#define ZYCMH

using namespace std;

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    int _;
    scanf("%d", &_);
    while (_ --)
    {
        int n;
        scanf("%d", &n);
        printf("1");
        for (int i = n; i >= 2; i -- )
            printf(" %d", i);
        puts("");
    }

    return 0;
}