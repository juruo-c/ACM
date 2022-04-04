#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1000005, M = 17;
const int mod = 998244353;

int n;
int a[N];
int c[M];

int main()
{
	int t;cin >> t;
	while (t -- )
	{
		for (int i = 0; i < M; i ++ ) c[i] = 0;
		int l;cin >> l;
		cin >> n;
		for (int i = 0; i <= n; i ++ ) 
		{
			cin >> a[i];
			for (int j = 0; j < M; j ++ )
				if (a[i] & (1 << j)) c[j] ++;
		}
		int x = 0;
		for (int i = 0; i < M; i ++ )
			if (n - c[i] < c[i]) x += (1 << i);
		cout << x << endl;
	}
	return 0;
}