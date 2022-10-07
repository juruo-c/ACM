#include <iostream>
#include <algorithm>
#include <cstring>
#define ZYCMH
#define LL long long
using namespace std;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n; scanf("%d", &n);
    if(n == 1)printf("1\n1\n");
    else if(n == 2) printf("2\n2 2\n");
    else if(n==3)printf("2\n2 2\n");
    else 
    {   
        printf("%d\n",2*n-4);
        for(int i=2;i<=n-1;i++)
            printf("%d ",i);
        for(int i=n-1;i>=2;i--)
        {
            printf("%d",i);
            if(i==2)printf("\n");
            else printf(" ");
        }
    }
    return 0;
}