#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

const int N = 205, mod = 998244353;

int n;
int A[N][N], B[N][N];
int a[N][N];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int x[N];//解集
int freeX[N];//自由变元
int Gauss(int equ,int var){//返回自由变元个数
    /*初始化*/
    for(int i=0;i<=var;i++){
        x[i]=0;
        freeX[i]=0;
    }
 
    /*转换为阶梯阵*/
    int col=0;//当前处理的列
    int num=0;//自由变元的序号
    int row;//当前处理的行
    for(row=0;row<equ&&col<var;row++,col++){//枚举当前处理的行
        int maxRow=row;//当前列绝对值最大的行
        for(int i=row+1;i<equ;i++){//寻找当前列绝对值最大的行
            if(abs(a[i][col])>abs(a[maxRow][col]))
                maxRow=i;
        }
        if(maxRow!=row){//与第row行交换
            for(int j=row;j<var+1;j++)
                swap(a[row][j],a[maxRow][j]);
        }
        if(a[row][col]==0){//col列第row行以下全是0，处理当前行的下一列
            freeX[num++]=col;//记录自由变元
            row--;
            continue;
        }
 
        for(int i=row+1;i<equ;i++){
            if(a[i][col]!=0){
                for(int j=col;j<var+1;j++){//对于下面出现该列中有1的行，需要把1消掉
                    a[i][j]^=a[row][j];
                }
            }
        }
    }
 
    /*求解*/
    //无解：化简的增广阵中存在(0,0,...,a)这样的行，且a!=0
    for(int i=row;i<equ;i++)
        if(a[i][col]!=0)
            return -1;
 
    //无穷解: 在var*(var+1)的增广阵中出现(0,0,...,0)这样的行
    int temp=var-row;//自由变元有var-row个
    if(row<var)//返回自由变元数
        return qpow(2, temp);
 
    //唯一解: 在var*(var+1)的增广阵中形成严格的上三角阵
    for(int i=var-1;i>=0;i--){//计算解集
        x[i]=a[i][var];
        for(int j=i+1;j<var;j++)
            x[i]^=(a[i][j]&&x[j]);
    }
    return 1;
}

int main()
{

    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            scanf("%d", &A[i][j]);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            scanf("%d", &B[i][j]);
    
    int ans = 1;
    for (int k = 0; k < n; k ++ )
    {
        for (int i = 0; i < n; i ++ )
        {
            for (int j = 0; j < n; j ++ )
                a[i][j] = A[i][j];
            if (B[i][k]) a[i][i] ^= 1;
        }
        int t = Gauss(n, n);
        if (t == -1)
        {
            puts("0");
            return 0;
        }
        ans = 1LL * ans * t % mod;
    }

    printf("%d\n", ans);

    return 0;
}