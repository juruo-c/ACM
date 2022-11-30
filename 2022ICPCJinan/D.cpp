#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 15, M = 1005;

vector<int> Status[N][N];
int n;
int Ac, Time;
int x[N], y[N], num[N];
char op[N];
string s[N];
int id[N];
bool isAc[N];
int Subtime[N], Actime[N];

PII get(string s)
{
    int x = 0, y = 0;
    int i = 0, sz = s.size();
    for (; i < sz && s[i] != '/'; i ++ )
        x = x * 10 + s[i] - '0';
    i ++;
    for (; i < sz; i ++ )
        y = y * 10 + s[i] - '0';
    return {x, y};
}

int main()
{
    int _; cin >> _ >> n;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < 1 << i; j ++ )
        {
            int x = 0;
            for (int k = 0; k < i; k ++ )
                if (j >> k & 1) x ++;
            Status[i][x].push_back(j);
        }
    while (_ --)
    {
        memset(isAc, false, sizeof isAc);
        memset(Subtime, 0, sizeof Subtime);
        memset(Actime, 0, sizeof Actime);
        cin >> Ac >> Time;
        int numAc = 0, numPd = 0;
        for (int i = 1; i <= n; i ++ )
        {
            cin >> op[i];
            if (op[i] == '+')
            {
                numAc ++;cin >> s[i];
                PII t = get(s[i]);
                Time -= (t.first - 1) * 20;
                Time -= t.second;
            }
            else if (op[i] == '-')
                cin >> s[i];
            else if (op[i] == '?')
            {
                id[i] = numPd;
                num[numPd] = i;
                cin >> x[numPd] >> y[numPd];
                numPd ++;
            }
        }

        // cout << "Time = " << Time << endl;

        if (Time < 0)
        {
            cout << "No" << endl;
            continue;
        }

        if (!numPd) // 没有 '?'
        {
            if (numAc == Ac && Time == 0) // 榜上过题数=输入过题数 and 罚时一致 
            {
                cout << "Yes" << endl;
                for (int i = 1; i <= n; i ++ )
                {
                    cout << op[i];
                    if (op[i] != '.') cout << " " << s[i];
                    cout << endl;
                }
            }
            else cout << "No" << endl; // 不一致
        }
        else // 有 '?' 
        {
            if (numAc > Ac) cout << "No" << endl; // 榜上过题数 > 输入过题数
            else if(numAc == Ac) 
            {
                if (Time != 0)
                {
                    cout << "No" << endl;
                    continue;
                }
                cout << "Yes" << endl;
                for (int i = 1; i <= n; i ++ )
                {
                    if (op[i] == '.') cout << op[i] << endl;
                    else if(op[i] == '?') cout << "- " << y[id[i]] << endl;
                    else cout << op[i] << " " << s[i] << endl;
                }
            }
            else // 封榜后还有过题
            {
                int numPdAc = Ac - numAc;
                if (numPdAc > numPd) cout << "No" << endl;
                else 
                {   
                    Time -= numPdAc * 240;
                    if (Time < 0)
                    {
                        cout << "No" << endl;
                        continue;
                    }
                    bool flag = false;
                    for (auto status : Status[numPd][numPdAc])
                    {
                        vector<int> pass;
                        int curTime = Time, sumWa = 0;
                        for (int i = 0; i < numPd; i ++ )
                            if (status >> i & 1) curTime -= (y[i] - x[i]) * 20, pass.push_back(i), sumWa += x[i] - 1;
                        
                        if (curTime < 0) continue;
                        if (curTime > sumWa * 20 + numPdAc * 59) continue;

                        // cout << "curTime = " << curTime << endl;

                        for (auto pa : pass)
                            isAc[num[pa]] = true;
                        
                        for (auto pa : pass)
                        {
                            int idx = num[pa];
                            if (curTime > (x[pa] - 1) * 20) Subtime[idx] = x[pa] - 1, curTime -= (x[pa] - 1) * 20;
                            else 
                            {
                                Subtime[idx] = curTime / 20, curTime -= Subtime[idx] * 20;
                                break;
                            }
                        }
                        
                        for (auto pa : pass)
                        {
                            int idx = num[pa];
                            if (curTime <= 59)
                            {
                                Actime[idx] = curTime, curTime = 0;
                                break;
                            }
                            else Actime[idx] = 59, curTime -= 59;
                        }

                        flag = true;
                        cout << "Yes" << endl;
                        for (int i = 1; i <= n; i ++ )
                        {
                            if (op[i] == '.') cout << op[i] << endl;
                            else if(op[i] == '?')
                            {
                                if (isAc[i]) cout << "+ " << Subtime[i] + (y[id[i]] - x[id[i]]) + 1 << "/" << Actime[i] + 240 << endl;
                                else cout << "- " << y[id[i]] << endl;
                            }
                            else 
                                cout << op[i] << " " << s[i] << endl;
                        }
                        break;
                    }

                    if (!flag) cout << "No" << endl;
                }
            }
        }

    }
    return 0;
}

/* 
1 13
6 668
+ 1/6
? 3 4
+ 4/183
- 2
+ 3/217
.
.
.
+ 2/29
+ 1/91
.
+ 1/22
.
*/