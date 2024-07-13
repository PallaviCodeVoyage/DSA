
class Solution
{
    public:
    vector<int> LPS;

    void fill(int patl, string p)
    {
        LPS.resize(patl);
        int max_l = 0;
        LPS[0] = 0;  // LPS[0] is always 0,here lps means longest prefix suffix as per my notice it contain atleast one element which must be uncommon for eg AAA the length 
      //of longest prefix which is equal to suffix is 2 (AA) which contains atleast one A which is not a common member for both the groups
        int i = 1;
        while (i < patl)
        {
            if (p[i] == p[max_l])
            {
                max_l++;
                LPS[i] = max_l;
                i++;
            }
            else
            {
                if (max_l != 0)
                {
                    max_l = LPS[max_l - 1];//It tells us the length of the next longest prefix which is also a suffix that might still match.
                }
                else
                {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(string pat, string txt)
    {
        vector<int> ans;
        int patl = pat.length();
        int txtl = txt.length();
        fill(patl, pat);

        int i = 0, j = 0;
        while (i < txtl)
        {
            if (txt[i] == pat[j])
            {
                i++;
                j++;
            }

            if (j == patl)
            {
                ans.push_back(i - j + 1);  // Adding 1 for 1-based indexing
                j = LPS[j - 1];
            }
            else if (i < txtl && txt[i] != pat[j])
            {
                if (j != 0)
                {
                    j = LPS[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return ans;
    }

     
};/*LPS Array: Helps remember parts of the pattern that repeat.
Mismatch Handling: max_l = LPS[max_l - 1] tells us where to look next in the pattern if a mismatch happens.*/

