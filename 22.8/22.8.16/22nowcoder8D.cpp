#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

struct Card
{
    int rank, suit;
    bool operator < (const Card& c) const
    {
        if (rank == c.rank) return suit < c.suit;
        return rank > c.rank;
    }

    int getrank(char c)
    {
        if (c == 'A') return 13;
        else if(c == 'K') return 12;
        else if(c == 'Q') return 11;
        else if(c == 'J') return 10;
        else if(c == 'T') return 9;
        else return c - '0' - 1;
    }

    int getsuit(char c)
    {
        if (c == 'S') return 4;
        else if(c == 'H') return 3;
        else if(c == 'C') return 2;
        else return 1;
    }

    void read()
    {
        string s;
        cin >> s;
        rank = getrank(s[0]);
        suit = getsuit(s[1]);
    }  

    char get_rank(int x)
    {
        if (x == 13) return 'A';
        else if(x == 12) return 'K';
        else if(x == 11) return 'Q';
        else if(x == 10) return 'J';
        else if(x == 9) return 'T';
        else return x + 1 + '0';
    }

    char get_suit(int x)
    {
        if (x == 4) return 'S';
        else if(x == 3) return 'H';
        else if(x == 2) return 'C';
        else return 'D';
    }
    void output()
    {
        cout << get_rank(rank) << get_suit(suit);
    }
}card[15];

struct Hand
{
    Card card[5];
    Hand(vector<Card>& hand)
    {
        for (int i = 0; i < 5; i ++ ) card[i] = hand[i];
        sort(card, card + 5);
    }

    bool operator < (const Hand& h) const
    {
        for (int i = 0; i < 5; i ++ )
            if (card[i].rank < h.card[i].rank) return true;
            else if(card[i].rank > h.card[i].rank) return false;
        return false;
    }

    bool operator > (const Hand& h) const
    {
        for (int i = 0; i < 5; i ++ )
            if (card[i].rank > h.card[i].rank) return true;
            else if(card[i].rank < h.card[i].rank) return false;
        return false;
    }

    void remake()
    {
        card[0].rank = 4, card[1].rank = 3, card[2].rank = 2, card[3].rank = 1, card[4].rank = 13;
    }

    void output()
    {
        for (int i = 0; i < 5; i ++ )
        {
            card[i].output();
            cout << " ";
        }
        cout << endl;
    }

    bool check()
    {
        return card[0].rank == 13 && card[1].rank == 4 && card[2].rank == 3 && card[3].rank == 2 && card[4].rank == 1;
    }

};
map<Hand, int> hand_type;

void add(int& c2, int& c3, int& c4, int x)
{
    if (x == 2) c2 ++;
    else if (x == 3) c3 ++;
    else if (x == 4) c4 ++;
}

void find_one_element(int& a, int& b, int& c, int& d, int& e, int cct, map<int, int>& cnt)
{
    int x;
    if (cnt[a] == cct) x = a;
    if (cnt[b] == cct) x = b;
    if (cnt[c] == cct) x = c;
    if (cnt[d] == cct) x = d;
    if (cnt[e] == cct) x = e;
    vector<int> v;
    if (a != x) v.push_back(a);
    if (b != x) v.push_back(b);
    if (c != x) v.push_back(c);
    if (d != x) v.push_back(d);
    if (e != x) v.push_back(e);
    if (cct == 2)
        a = b = x, c = v[0], d = v[1], e = v[2];
    else if(cct == 3) 
        a = b = c = x, d = v[0], e = v[1];
    else if (cct == 4)
        a = b = c = d = x, e = v[0];
}

void find_two_element(int& a, int& b, int& c, int& d, int& e, int cct1, int cct2, map<int, int>& cnt)
{
    int x, y;
    if (cnt[a] == cct1) x = a;
    if (cnt[b] == cct1) x = b;
    if (cnt[c] == cct1) x = c;
    if (cnt[d] == cct1) x = d;
    if (cnt[e] == cct1) x = e;
    if (cnt[a] == cct2 && a != x) y = a;
    if (cnt[b] == cct2 && b != x) y = b;
    if (cnt[c] == cct2 && c != x) y = c;
    if (cnt[d] == cct2 && d != x) y = d;
    if (cnt[e] == cct2 && e != x) y = e;
    vector<int> v;
    if (a != x && a != y) v.push_back(a);
    if (b != x && b != y) v.push_back(b);
    if (c != x && c != y) v.push_back(c);
    if (d != x && d != y) v.push_back(d);
    if (e != x && e != y) v.push_back(e);
    if (cct1 == 2 && cct2 == 2)
    {
        if (x < y) swap(x, y);
        a = b = x, c = d = y, e = v[0];
    }
    else 
        a = b = c = x, d = e = y;
}

int get_hand_type(Hand& hand)
{
    int a = hand.card[0].rank, b = hand.card[1].rank, c = hand.card[2].rank, d = hand.card[3].rank, e = hand.card[4].rank;
    int as = hand.card[0].suit, bs = hand.card[1].suit, cs = hand.card[2].suit, ds = hand.card[3].suit, es = hand.card[4].suit;

    if (a > b && b > c && c > d && d > e)
    {
        if (a == 13 && b == 12 && c == 11 && d == 10 && e == 9) return 10;
        if ((b == c + 1 && c == d + 1 && d == e + 1 && a == b + 1) || (a == 13 && b == 4 && c == 3 && d == 2 && e == 1))
        {
            if (as == bs && bs == cs && cs == ds && ds == es) return 9;
            else return 5;
        }
        if (as == bs && bs == cs && cs == ds && ds == es) return 6;
        return 1;
    }
    
    map<int, int> cnt;
    cnt[a] ++, cnt[b] ++, cnt[c] ++, cnt[d] ++, cnt[e] ++;
    int c2 = 0, c3 = 0, c4 = 0;
    add(c2, c3, c4, cnt[a]), add(c2, c3, c4, cnt[b]), add(c2, c3, c4, cnt[c]), add(c2, c3, c4, cnt[d]), add(c2, c3, c4, cnt[e]);
    // cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    // cout << "c2 = " << c2 << " c3 = " << c3 << " c4 = " << c4 << endl;

    int type;
    if (c2 == 2)
    {
        if (!c3)
        {
            find_one_element(a, b, c, d, e, 2, cnt);
            type = 2;
        }   
        else 
            find_two_element(a, b, c, d, e, 3, 2, cnt), type = 7;
    }
    if(c2 == 4)
        find_two_element(a, b, c, d, e, 2, 2, cnt), type = 3;
    if(c3 == 3 && !c2)
        find_one_element(a, b, c, d, e, 3, cnt), type = 4;
    if (c4 == 4)
        find_one_element(a, b, c, d, e, 4, cnt), type = 8;
    
    // cout << "after: " << a << " " << b << " " << c << " " << d << " " << e << endl;
    hand.card[0].rank = a, hand.card[1].rank = b, hand.card[2].rank = c, hand.card[3].rank = d, hand.card[4].rank = e;
    return type;
}

//1: A > B
//0: A = B
//-1: A < B
int compare(vector<Card>& handA, vector<Card>& handB) 
{
    Hand a(handA), b(handB);
    
    int typeA = get_hand_type(a), typeB = get_hand_type(b);
    // cout << "handa: "; a.output();
    // cout << "handb: "; b.output();
    // cout << "typea: " << typeA << endl;
    // cout << "typeb: " << typeB << endl;
    if (a.check()) a.remake();
    if (b.check()) b.remake();
    if (typeA > typeB)
    {
        // cout << "A > B" << endl;
        return 1;
    }
    else if(typeA < typeB) 
    {
        // cout << "A < B" << endl;
        return -1;
    }
    else
    {
        if (a > b) {
            // cout << "A > B" << endl;
            return 1;
        }
        else if(a < b) 
        {
            // cout << "A < B" << endl;
            return -1;
        }
        else 
        {
            // cout << "A = B" << endl;
            return 0;
        }
    }
}

//who
//0: A
//1: B
int sg(vector<Card>& handA, vector<Card>& handB, vector<Card>& unused, bool who)
{
    if (unused.size() == 0)
        return compare(handA, handB);
    
    int mi = 1;
    int len = unused.size(); 
    for (int i = 0; i < len; i ++ )
    {
        vector<Card> next_unused;
        for (int j = 0; j < len; j ++ ) 
            if (j != i) next_unused.push_back(unused[j]);
        
        if (who)
            handB.push_back(unused[i]);
        else handA.push_back(unused[i]);

        mi = min(mi, sg(handA, handB, next_unused, who ^ 1));

        if (who) handB.pop_back();
        else handA.pop_back();
        if (mi == -1) break;
    }
    return -mi;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; cin >> t;
    while (t --)
    {
        for (int i = 1; i <= 10; i ++ )
            card[i].read();
        vector<Card> handA, handB, unused;
        handA.push_back(card[1]), handA.push_back(card[2]);
        handB.push_back(card[3]), handB.push_back(card[4]);
        for (int i = 5; i <= 10; i ++ ) unused.push_back(card[i]);

        int res = sg(handA, handB, unused, 0);
        if (res > 0) cout << "Alice" << endl;
        else if (!res) cout << "Draw" << endl;
        else cout << "Bob" << endl; 
    }
    return 0;
}
