#include <bits/stdc++.h>

using namespace std;

string r[5];
map<string, int> ma;

int main()
{
    ma["-F"] = 8;
    ma["-Cl"] = 7;
    ma["-Br"] = 6;
    ma["-I"] = 5;
    ma["-CH3"] = 4;
    ma["-CH2CH3"] = 3;
    ma["-CH2CH2CH3"] = 2;
    ma["-H"] = 1;
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        for (int i = 1; i <= 4; i ++ )
            cin >> r[i];
        if (r[1] == r[3] || r[2] == r[4]) 
        {
            cout << "None\n";
            continue;
        }

        if (r[1] == r[2] || r[3] == r[4])
        {
            cout << "Cis\n";
            continue;
        }
        if (r[1] == r[4] || r[2] == r[3])
        {
            cout << "Trans\n";
            continue;
        }

        int a = ma[r[1]] > ma[r[3]] ? 1 : 3;
        int b = ma[r[2]] > ma[r[4]] ? 2 : 4;

        if ((a == 1 && b == 2) || (a == 3 && b == 4))
        {
            cout << "Zasamman\n";
            continue;
        }
        
        cout << "Entgegen\n";

    }

    return 0;
}