#include <bits/stdc++.h>

using namespace std;

const int mod = 20220911;

int str_to_int(string s)
{
    int res = 0;
    for (int i = 0; s[i]; i ++ )
        res = 10 * res + (s[i] - '0');
    return res;
}

int main()
{

    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    string s;
    getline(cin, s);
    stringstream ss(s);

    vector<int> a;
    a.push_back(-2);
    while (ss >> s)
    {
        if (s == "library")
            a.push_back(-1);
        else if(s == "repeat")
            a.push_back(-2);
        else if(s == "for")
        {
            ss >> s;
            a.push_back(str_to_int(s));
        }
    }
    a.push_back(1);
    
    for (int i = 0; i < a.size(); i ++ )
        cout << a[i] << " ";
    cout << endl;

    vector<int> stk;
    int sz = a.size(); 
    for (int i = 0; i < sz; i ++ )
    {
        if (a[i] == -2 || a[i] == -1)
            stk.push_back(a[i]);
        else 
        {
            int res = 0;
            while(stk.size() && stk.back() != -2)
            {
                if (stk.back() == -1)
                    res = (res + 1) % mod;
                else
                    res = (res + stk.back()) % mod;
                stk.pop_back();
            }
            stk.pop_back();
            stk.push_back(1LL * res * a[i] % mod);
        }
    }

    cout << stk.back() << endl;

    return 0;
}