#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long LL;

LL qmul(LL a, LL b, LL p)
{
	LL ans = 0;
	while (b)
	{
		if (b & 1) ans = (ans + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return ans;
}

LL qpow(LL a, LL b, LL p)
{
	LL ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

bool Miller_Rabin(LL p)
{
	if (p < 2) return false;
	LL s = 0, t = p - 1;
	while (!(t & 1)) s ++, t >>= 1;
	for (int i = 0; i < 20; i ++ )
	{
		LL a = rand() % (p - 1) + 1;
		LL x = qpow(a, t, p);
		for (int j = 0; j < s; j ++ )
		{
			LL y = qmul(x, x, p);
			if (y == 1 && x != 1 && x != p - 1) return false;
			x = y;
		}
		if (x != 1) return false;
	}
	return true;
}

int main() {
    int n, p;
    srand(time(NULL));
    while (~scanf("%d", &n)) {
    	int ans = 0;
    	for (int i = 0; i < n; i ++ )
    	{
    		scanf("%d", &p);
    		if (Miller_Rabin(p)) ans ++;
    	}
    	printf("%d\n", ans);
    }
    return 0;
}