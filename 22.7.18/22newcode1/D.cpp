#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

double r, x, y, d;

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%lf%lf%lf%lf", &r, &x, &y, &d);
		double dis = sqrt(x * x + y * y);
		double a = dis - d, b = dis + d;
		double A = acos(a / r);
		double B = acos(b / r);
		printf("%.10f\n", r * (A - B));
	}
	return 0;
}