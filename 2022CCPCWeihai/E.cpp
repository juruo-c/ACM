#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[15];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    
    if (a[n] - a[n - 1] >= 0)
        puts("Python will never be faster than C++");
    else 
    {
        int t1 = a[n - 1];
        int t2 = a[n];
        while (t2 >= k)
        {
            n ++;
            int t = t2;
            t2 = 2 * t2 - t1;
            t1 = t;
        }
        printf("Python 3.%d will be faster than C++\n", n);
    }

    return 0;
}