#include <iostream>
#include <map>

using namespace std;

const int N = 2005;

int n, m;
int cham[10];
int uncham[10];
map<string, bool> vis;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < 5; j ++ )
        {
            string s;
            cin >> s;
            vis[s] = true;
        }
    
    cin >> m;
    for (int i = 1; i <= m; i ++ )
    {
        string s; int pos;
        cin >> s >> pos;
        if (!vis[s]) uncham[pos] ++;
        else cham[pos] ++;
    }


    int mi = 2000, id;
    for (int i = 1; i <= 5; i ++ )
        if (uncham[i] + cham[i] < mi) 
        {
            mi = uncham[i] + cham[i];
            id = i;
        }

    for (int i = 1; i <= cham[id]; i ++ )
    {
        for (int j = 1; j <= 5; j ++ )
            if (j != id)
            {
                if (uncham[j]) uncham[j] --;
                else cham[j] --;
            }
    }
    int ans = cham[id];
    for (int i = 1; i <= uncham[id]; i ++ )
    {
        int idx = -1;
        for (int j = 1; j <= 5; j ++ )
            if (j != id)
            {
                if (cham[j]) 
                {
                    idx = j;
                    break;
                }
            }
        
        if (idx == -1) break;
        ans ++;
        cham[idx] --;
        for (int j = 1; j <= 5; j ++ )
            if (j != id && j != idx)
            {
                if (uncham[j]) uncham[j] --;
                else cham[j] --;
            }
    }

    cout << ans << endl;

    return 0;
}