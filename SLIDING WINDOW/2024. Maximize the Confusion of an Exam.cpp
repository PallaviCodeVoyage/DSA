class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        //case 1 where i am flipping only true ie telling the maximum of consecutive false;
        int n=answerKey.length();
        int i=0;
        int j=0;
        int tc_in_w=0;
        int ans1=0;
        int ans2=0;
        int fc_in_w=0;
        while(j<n)
        {
            if(answerKey[j]=='T')
            {
                tc_in_w++;
            }
            while(tc_in_w>k)
            {
               if(answerKey[i]=='T')
               {
                tc_in_w--;
               }
               i++;
            }
            ans1=max(ans1,j-i+1);
            j++;

        }

        //case 2
         j=0;
         i=0;
         tc_in_w=0;
        // ans1=0;
       
         fc_in_w=0;
        while(j<n)
        {
            if(answerKey[j]=='F')
            {
                fc_in_w++;
            }
            while(fc_in_w>k)
            {
               if(answerKey[i]=='F')
               {
                fc_in_w--;
               }
               i++;
            }
            ans2=max(ans2,j-i+1);
            j++;

        }
        return max(ans1,ans2);

        
    }
};
