/*hint 1:if i have a 3 rupees coin it is sure that i can make 3,4,5,6,7 and so on amount with it not 2,1
=>main problem was i were stuck that how come i bring the approach to make it possible to open up ways to select a coin multiple times
=>imp 1,2 is same as 2,1 here so need to avoid unnecessary counting
=>
for example considering coin 2:
dp[i] states what is the way to make a contribution to make coin of 5 using coin 2
=>dp[i]=dp[i](abhi tk coin 5 bnane k jitne ways hain add)+d[i-2]//dp[3] bcoz if 3 ways are to make 3 rupees then adding 2 in all 3 ways i can make 5 rupess amount
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
        dp[0]=1;//koi coin select hi mt kro
        for(int coin:coins)
        {
            for(int i=coin;i<=amount;i++)
            {
                dp[i]=dp[i]+dp[i-coin];
            }
        }
        return dp[amount];
    }
};
