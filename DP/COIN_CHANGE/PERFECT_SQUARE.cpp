class Solution {
public:
unordered_map<int,int>dp;
int help(int n)
{
    
    if(n==0)
    {
        return 0;
    }
    if(dp.find(n)!=dp.end())
    {
        return dp[n];
    }
    int ans=INT_MAX;
    for(int i=1;i*i<=n;i++)
    {
        int square=i*i;
        ans=min(ans,(1+help(n-square)));//this line says i have used one perfect square block to make a tower of height n so adding 1 now u find out ways( help(n-square)) to use other perfeect square blocks to achieve 
      //height h:> analogy
    }
    return dp[n]=ans;
}
    int numSquares(int n) {
    return help(n);
        
    }
};
//imp things where to use map and vector for memo?
/*when the data is not consecutive preferred to use map and also the data or indexing are cofusing to be made or used*/
