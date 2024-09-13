class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<0)
        {
            return -1;

        }
        vector<int>dp(amount+1,amount+1);//ye kehta hain ki ith index =>i paisa bnane k lia kitna min number of coins req hain
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(auto coin:coins)
            {
                if(i-coin>=0)//jo paisa abhi bnana hain means i usmain se coin rupee hta dia
                {
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};
