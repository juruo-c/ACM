#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 2022;

int n;
int a[N];
int b[N];

int main()
{
    int _;scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &b[i]);
        
        vector<PII> ans;
        bool flag = true;
        for (int i = 1; i <= n; i ++ )
        {
            if (a[i] == b[i]) continue;
            else if(a[i] < b[i]) 
            {
                flag = false;
                break;
            }
            else 
            {
                for (int j = i + 1; j <= n; j ++ )
                    if (a[j] < a[i] && a[j] >= b[i])
                        swap(a[j], a[i]), ans.push_back({i, j});
            }
        }

        if (!flag) puts("-1");
        else {
            printf("%d\n", ans.size());
            for (auto t : ans)
                printf("%d %d\n", t.first, t.second);
        }
    }
    return 0;
}