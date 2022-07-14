#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N=2e6 + 10;
int n, head, tail, a[N], b[N], q[N], f[N];
//队头放连续区间长的，如果连续区间一样长，就放置最小温度更小的
int main()
{
 scanf("%d", &n);
 for(int i = 1; i <= n; i ++) 
  scanf("%d%d", &a[i], &b[i]);
 head = 0, tail = -1;
 f[1] = 1, q[++ tail] = 1;
 int ans = 1;
 for(int i = 2; i <= n; i ++)
 {
  while(head <= tail && b[i] < a[q[head]])//不降 后面的大 后面最大不小于前面最小的
   head ++;
  if(b[i] < a[q[head]]) //当前温度太低只能重新开始
  {
   q[head] = i;
   f[i] = 1;
   continue;
  }
  f[i] = f[q[head]] + 1;
  ans = max(ans, f[i]);
  while(head <= tail && 
   (f[i] > f[q[tail]] || (f[i] == f[q[tail]] && a[i] > a[q[tail]])))
   tail --;

  q[++ tail] = i;
 }
 printf("%d\n", ans);
 return 0;
}