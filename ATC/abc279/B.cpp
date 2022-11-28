#include <iostream>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    if (t.size() > s.size()) cout << "No";  
    else 
    {
        bool flag = false;
        int sz = s.size();
        for (int i = 0; i < sz && i + t.size() - 1 < sz; i ++ )
            if (s.substr(i, t.size()) == t)
            {
                cout << "Yes";
                flag = true;
                break;
            }
        if (!flag) cout << "No";
    }
    return 0;
}