class Solution {
public:
int N,M,K;
int MOD=1e9+7;
int dp[51][51][101];
int solve(int indx,int searchcost,int maxabhitk)
{
    if(indx==N)
    {
        if(K==searchcost)
        {
            return 1;
        }
        return 0;
    }
    if(dp[indx][searchcost][maxabhitk]!=-1)
    {
        return dp[indx][searchcost][maxabhitk];
    }
  int result=0;
    for(int i=1;i<=M;i++)
    {
        if(maxabhitk<i)
        {
          result=(result+solve(indx+1,searchcost+1,i))%MOD;

        }
        else
        {
             result=(result+solve(indx+1,searchcost,maxabhitk))%MOD;
        }
    }
    return dp[indx][searchcost][maxabhitk]=result%MOD;
}
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};
