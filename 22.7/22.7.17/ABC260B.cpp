#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1005;

int n, x, y, z;

struct S
{
	int m, e, id;
}s[N];

bool cmpm(S a, S b)
{
	if (a.m == b.m)
		return a.id < b.id;
	return a.m > b.m;
}

bool cmpe(S a, S b)
{
	if (a.e == b.e)
		return a.id < b.id;
	return a.e > b.e;
}

bool cmps(S a, S b)
{
	if (a.e + a.m == b.e + b.m)
		return a.id < b.id;
	return a.e + a.m > b.e + b.m;
}

int main()
{
	cin >> n >> x >> y >> z;
	for (int i = 1; i <= n; i ++ )
		cin >> s[i].m, s[i].id = i;
	for (int i = 1; i <= n; i ++ )
		cin >> s[i].e;

	sort(s + 1, s + 1 + n, cmpm);

	vector<int> admit;
	for (int i = 1; i <= x; i ++ )
		admit.push_back(s[i].id);

	sort(s + x + 1, s + 1 + n, cmpe);

	for (int i = 1; i <= y; i ++ )
		admit.push_back(s[i + x].id);

	sort(s + x + y + 1, s + 1 + n, cmps);
	for (int i = 1; i <= z; i ++ )
		admit.push_back(s[i + x + y].id);

	sort(admit.begin(), admit.end());
	for (auto x : admit)
		cout << x << endl;

	return 0;
}