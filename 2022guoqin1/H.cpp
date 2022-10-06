#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ZYCMH
int t,m,n,k,col[1000005],fir,las,ans,colm[1000005],u;
int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&m,&n,&k);
        u=0;
        col[0]=0;
        ans=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&col[i]);
            if(col[i]!=col[i-1])
            {
                u++;
                colm[u]=1;
            }
            else
            {
                colm[u]++;
            }
        }
        if(col[1]==col[m]&&m!=1)
        {
            colm[1]+=colm[u];
            colm[u]=0;
            u--;
        }
        int flag=0;
        for(int i=1;i<=u;i++)
        {
            if(colm[i]>=k)
            {
                flag=1;
            }
            ans+=(colm[i]+k-1)/k;
        }
        if(flag)printf("%d\n",ans);
        else printf("-1\n");
    }
}