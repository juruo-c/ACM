#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int N = 200005;

char s[N];

int main()
{
	int t; scanf("%d", &t);
	while (t --)
	{
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		int ans = 0;
		set<char> se;
		for (int i = 1; i <= n; i ++ )
			if (se.count(s[i]))
			{
				se.clear();
				ans ++;
			}
			else se.insert(s[i]);
		printf("%d\n", n - 2 * ans);
	}
	return 0;
}