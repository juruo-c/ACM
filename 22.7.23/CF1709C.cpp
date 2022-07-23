#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005;

int n;
char s[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t -- )
	{
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int c1 = 0, c2 = 0, c3 = 0;
		for (int i = 1; i <= n; i ++ )
		{
			if (s[i] == '(') c1 ++;
			else if (s[i] == ')') c2 ++;
			else if(s[i] == '?') c3 ++;
		}

		if (c1 == n / 2 || c2 == n / 2)
		{
			puts("YES");
			continue;
		}

		c1 = n / 2 - c1, c2 = n / 2 - c2;

		int p1, p2;
		for (int i = 1; i <= n; i ++ )
			if (s[i] == '?')
			{
				if (c1) s[i] = '(', c1 --, p1 = i;
				else
				{
					s[i] = ')';
					p2 = i;
					break;
				}
			}

		for (int i = p2 + 1; i <= n; i ++ )
			if (s[i] == '?') s[i] = ')';

		// printf("%s\n", s + 1);

		s[p2] = '(', s[p1] = ')';

		// printf("%s\n", s + 1);

		int c = 0;
		bool flag = true;
		for (int i = 1; i <= n; i ++ )
			if (s[i] == '(')
				c ++;
			else
			{
				if (!c)
				{
					flag = false;
					break;
				}
				else c --;
			}

		if (flag)
			puts("NO");
		else puts("YES");
	}
	return 0;
}