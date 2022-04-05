#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const int N = 200005;

int n;
int a[N];
int sum[N];

PIII solve(int l, int r)
{
	int cneg = 0;
	for (int i = l; i <= r; i ++ )
		if (a[i] < 0) cneg ++;

	if (cneg % 2 == 0) return {sum[r] - sum[l - 1], {l - 1, n - r}};
	int pl = l, pr = r;
	while(a[pl] > 0) pl ++;
	pl ++;
	while(a[pr] > 0) pr --;
	pr --;
	int ansl = sum[r] - sum[pl - 1], ansr = sum[pr] - sum[l - 1];
	if (ansl > ansr) return {sum[r] - sum[pl - 1], {pl - 1, n - r}};
	else return {sum[pr] - sum[l - 1], {l - 1, n - pr}};
}

int main()
{
	int t; scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%d", &a[i]);
			if (abs(a[i]) == 2)
				sum[i] = sum[i - 1] + 1;
			else sum[i] = sum[i - 1];
		}

		vector<int> zero;
		zero.push_back(0);
		for (int i = 1; i <= n; i ++ )
			if (a[i] == 0) zero.push_back(i);
		zero.push_back(n + 1);

		PIII ans = {0, {n, 0}};
		for (int i = 1; i < (int)zero.size(); i ++ )
		{
			int l = zero[i - 1] + 1, r = zero[i] - 1;
			if (l > r) continue;
			PIII res = solve(l, r);
			if (res.first > ans.first)
				ans = res;
		}

		printf("%d %d\n", ans.second.first, ans.second.second);
	}
	return 0;
}