////http://oj.daimayuan.top/course/10/problem/501
//
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//const int N = 100005;
//
//int n;
//int h[N];
//int f[N], g[N];
//
//int main()
//{
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
//    for (int i = 1; i <= n; i ++ )
//        f[i] = min(f[i - 1] + 1, h[i]);
//    for (int i = n; i >= 1; i -- )
//        g[i] = min(g[i + 1] + 1, h[i]);
//
//    int ans = 0;
//    for (int i = 1; i <= n; i ++ )
//        ans = max(ans, min(f[i], g[i]));
//    printf("%d\n", ans);
//
//    return 0;
//}
