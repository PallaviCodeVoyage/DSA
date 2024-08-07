/**in this brute force approach i learnt how to use the substr in order to check for suffix* O(N2.M)*/
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        //brute force without kmp;
        int pair=0;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            int s=words[i].length();//a size of ith sitring
            for(int j=i+1;j<n;j++)
            {
                int s2=words[j].length();
                if(s2<s)
                {
                    continue;
                }
                else
                {
                    if(words[j].substr(0,s)==words[i])
                    {
                        if(words[j].substr((s2-s),s)==words[i])//imp here i have sub l of s1 and s2 and them from that index i need to search for suffix  upto the length f given pt(suffix which needs to be searched
                        {
                            pair++;
                        }
                    }
                }
            }

        }
        return pair;
    }
};
