#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 1<<29
int dp[(1<<11)+5][11];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int dis[11][11];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                scanf("%d",&dis[i][j]);
        //Floyd求最短路
        for(int k=0;k<=n;k++)
            for(int i=0;i<=n;i++)
                for(int j=0;j<=n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        memset(dp,0,sizeof(dp));//初始化
        for(int state=0;state<(1<<n);state++)//枚举所有状态
            for(int i=1;i<=n;i++)//枚举所有城市
                if(state&(1<<(i-1)))//去过i城市
                {
                    if(state==(1<<(i-1)))//只去过i城市显然此状态最短路即为披萨店到i城市最短路
                        dp[state][i]=dis[0][i];
                    else//还去过其他城市
                    {
                        dp[state][i]=INF;//初始化
                        //从此状态经过的其他城市中选取合适的中间点j城市使得总距离最小
                        for(int j=1;j<=n;j++)
                            if(i!=j&&state&(1<<(j-1)))
                                dp[state][i]=min(dp[state][i],dp[state^(1<<(i-1))][j]+dis[j][i]);//更新最短总距离
                    }
                }
        //从经过所有城市的状态中选取最短总距离
        int ans=dp[(1<<n)-1][1]+dis[1][0];
        for(int i=2;i<=n;i++)
            ans=min(ans,dp[(1<<n)-1][i]+dis[i][0]);
        printf("%d\n",ans);
    }
    return 0;
}