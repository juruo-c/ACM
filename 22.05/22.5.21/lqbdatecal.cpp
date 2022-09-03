#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Date
{
	int y, d, m;
	Date(){}
	Date(int y, int d, int m):y(y), d(d), m(m){}
	bool operator > (const Date& D)
	{
		if (y == D.y)
		{
			if (m == D.m)
				return d > D.d;
			return m > D.m;
		}
		return y > D.y;
	}
};
int l1[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int l2[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

int main()
{
	Date d1(2011, 11, 11);
	int y, d, m;
	cin >> y >> m >> d;
	Date d2(y, m, d);

	bool flag = true;
	if (d1 > d2) swap(d1, d2), flag = false;

	int cnt = 0;
	for (int i = d1.y; i < d2.y - 1; i ++ )
		if (isleap(i))
			cnt += 366;
		else cnt += 365;

	

	return 0;
}