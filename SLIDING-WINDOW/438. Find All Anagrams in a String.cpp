class Solution {
public:

bool alzro(vector<int>v)
{
    for(auto i:v)
    {
        if(i!=0)
        {
            return false;
        }
        
    }
    return true;
}
    vector<int> findAnagrams(string s, string p) {
        int l1=s.length();
        int l2=p.length();
        vector<int>ans;
        int i=0,j=0;
        vector<int>occ(26,0);
        while(i<l2)
        {
            occ[p[i]-'a']++;//this line is imp as it is used to find the index of respective element in order to  maintain freq
            i++;
        }
        i=0;j=0;
        while(j<l1)
        {
            occ[s[j]-'a']--;
            if(j-i+1==l2)
            {
                if(alzro(occ))//call to the function is mae in order to find  whether the freq of all elements is 0 once the length of pattern in recieved
                {
                    ans.push_back(i);
                }
                occ[s[i]-'a']++;
                i++;
            }
            j++;
        }
       // ans.shrink_to_fit();

        return ans;//returning the vector containing the indices where the anagrams of the given pattern found in the string
    }
};
