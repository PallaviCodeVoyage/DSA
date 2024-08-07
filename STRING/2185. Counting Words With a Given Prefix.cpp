class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int i;
        for(string s:words)
        {
           for(i=0;i<pref.size();i++)
           {
            if(s[i]==pref[i])
            {
                continue;
            }
            else
            {
                break;
            }
           }
           if(i==pref.size())
           {
            count++;
           }
           
        }
        return count;
        
    }
};
/***O(M.N)**/
/*kmp does notwork beacuse it is for fiding the occurance doe not matter whether it is as suffix or prefix  in the text and also here it finds the substring even if it is suffix thus fails*/
