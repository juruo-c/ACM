#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, e, f, x;
	cin >> b >> a >> c >> e >> d >> f >> x;
	int t = x;
	int ansT = 0, ansA = 0;
	while (t)
	{
		if (t >= b) 
			ansT += a * b;
		else
		{
			ansT += a * t;
			break;
		}
		t -= b;
		if (t >= c) t -= c;
		else break;
	}
	t = x;
	while (t)
	{
		if (t >= e) ansA += d * e;
		else
		{
			ansA += d * t;
			break;
		}
		t -= e;
		if (t >= f) t -= f;
		else break;
	}

	if (ansT > ansA) cout << "Takahashi" << endl;
	else if(ansT == ansA) cout << "Draw" << endl;
	else cout << "Aoki" << endl;
	return 0;
}