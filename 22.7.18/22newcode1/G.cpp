#include <iostream>

using namespace std;

int main()
{
	string n;
	cin >> n;
	if (n.size() == 1) cout << n;
	else
	{
		int i;
		for (i = 0; i < n.size(); i ++ )
			if (n[i] != '9') break;
		if (i == n.size() || i == n.size() - 1) cout << n;
		else 
		{
			for (int j = 0; j < n.size() - 1; j ++ )
				cout << '9';
		}
	}
	return 0;
}