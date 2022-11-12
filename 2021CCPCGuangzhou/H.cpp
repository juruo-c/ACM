#include <iostream>

using namespace std;

typedef long long LL;

LL get(LL a, LL b, LL c)
{
    if (c < b) return b;
    LL t = c - b;
    LL k = t / a;
    while (k * a <= t) k ++;
    return k * a + b;
}

int main()
{
    int _; cin >> _;
    while (_ --)
    {
        LL a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) printf("YES\n1 1 1\n");
        else if(a == b && b == c) puts("NO");
        else 
        {
            if (a > c)
            {
                LL x = a, y, z;
                z = get(a, c, b);
                y = get(z, b, a);
                cout << "YES\n";
                cout << x << " " << y << " " << z << endl;
            }
            else if (b > a)
            {
                LL x, y = b, z;
                x = get(b, a, c);
                z = get(x, c, b);
                cout << "YES\n";
                cout << x << " " << y << " " << z << endl;
            }   
            else if (c > b)
            {
                LL x, y, z = c;
                y = get(c, b, a);
                x = get(y, a, c);
                cout << "YES\n";
                cout << x << " " << y << " " << z << endl;
            }
            else 
                puts("NO");
        }
    }
    return 0;
}