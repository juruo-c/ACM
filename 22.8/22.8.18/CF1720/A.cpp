#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

int main()
{
	#ifdef ZYCMH
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	#endif 

	int t;
	scanf("%d", &t);
	while(t --)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		LL A = 1LL * a * d, B = 1LL * b * c;
		if (A == B) puts("0");
		else if(A == 0 || B == 0 || A % B == 0 || B % A == 0) puts("1");
		else puts("2");
	}

	return 0;
}