#include <iostream>

using namespace std;

const int N = 60;

string s[N];

int main()
{
    int n;
    cin >> n;
    bool flag = true;
    for (int i = 1; i <= n; i ++ ) cin >> s[i];
    for (int i = 1; i <= n; i ++ )
    {
        if (s[i][0] != 'H' && s[i][0] != 'D' && s[i][0] != 'C' && s[i][0] != 'S')
        {
            flag = false;
            break;
        }
        if (s[i][1] != 'A' && !(s[i][1] >= '2' && s[i][1] <= '9') && s[i][1] != 'T' && s[i][1] != 'J' && s[i][1] != 'Q' && s[i][1] != 'K') 
        {
            flag = false;
            break;
        }
    }
    for (int i = 1; i <= n; i ++ )
        for (int j = i + 1; j <= n; j ++ )
            if (s[i] == s[j])
            {
                flag = false;
                break;
            }

    cout << (flag ? "Yes" : "No");
    
    return 0;
}