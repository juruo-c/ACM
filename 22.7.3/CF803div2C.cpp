#include <iostream>

using namespace std;

const int N = 200005;

int n;
int a[N];

int main()
{
	int t; cin >> t;
	while (t --)
	{
		cin >> n;
		bool flag0 = false;
		int cne = 0, cpo = 0;
		int sum = 0;
		for (int i = 1; i <= n; i ++ )
		{
			cin >> a[i];
			if (a[i] > 0) cpo ++;
			else if (a[i] < 0) cne ++;
			else flag0 = true;
			sum += a[i];
		}

		if (cpo > 2 || cne > 2) 
		{
			cout << "NO" << endl;
			continue;
		}

		if (flag0)
		{
			if (cpo > 1 || cne > 1) cout << "NO" << endl;
			else 
			{
				if (cpo == 1 && cne == 1)
				{
					if (sum) cout << "NO" << endl;
					else cout << "YES" << endl;
				} 
				else
					cout << "YES" << endl;
			}
		}
		else
		{
			bool flag = true;
			for (int i = 1; i <= n; i ++ )
				for (int j = i + 1; j <= n; j ++ )
					for (int k = j + 1; k <= n; k ++ )
					{
						bool fl = false;
						for (int p = 1; p <= n; p ++ )
							if (a[i] + a[j] + a[k] == a[p])
							{
								fl = true;
								break;
							}
						if (fl == false)
						{
							flag = false;
							break;
						}
					}
			if (flag) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}