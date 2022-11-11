#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i ++ )
        if (s[i] == '.')
        {
            if (!((i && s[i - 1] == 'L') || (i < n - 1 && s[i + 1] == 'L')))
                s[i] = 'C';
        }

    cout << s;
    return 0;
}