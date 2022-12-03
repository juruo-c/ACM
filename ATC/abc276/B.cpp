#include <iostream>

using namespace std;

const int N = 15;

typedef long long LL;

int n;

int main()
{
    cin >> n;
    LL a = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (i > 1) cout << " ";
        int s;cin >> s;
        a = s - a;
        cout << a ;
        a = s;
    
    }

    return 0;
}
