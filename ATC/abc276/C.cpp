#include <iostream>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < (int)t.size(); i ++ )
        if (s[i] != t[i])
        {
            cout << i + 1;
            break;
        }
    return 0;
}