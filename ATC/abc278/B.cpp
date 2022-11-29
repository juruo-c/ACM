#include <iostream>

using namespace std;

bool check(int h, int m)
{
    int t1 = h % 10, t2 = m / 10;
    h = h / 10 * 10 + t2, m = t1 * 10 + m % 10;
    if (0 <= h && h <= 23 && 0 <= m && m <= 59) return true;
    return false;
}

int main()
{
    int h, m;
    cin >> h >> m;
    while (true)
    {
        if (check(h, m)) 
        {
            cout << h << " " << m << endl;
            break;
        }
        m ++;
        if (m == 60) m = 0, h ++;
        if (h == 24) h = 0;
    }
    return 0;
}