#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005;

int n;
char s[N];
int cnt[26];

int main()
{
	int t;scanf("%d", &t);
	while (t --)
	{
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for (int i = 0; i < 26; i ++ ) cnt[i] = 0;
		for (int i = 1; i <= n; i ++ )
			cnt[s[i] - 'a'] ++ ;

		int pos = 1;
		while (pos <= n && cnt[s[pos] - 'a'] - 1)
		{
			cnt[s[pos] - 'a'] --;
			pos ++;
		}

		printf("%s\n", s + pos);
	}
	return 0;
}