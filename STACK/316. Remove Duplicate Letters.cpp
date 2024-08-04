class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool>inside(26,false);
        vector<int>count(26,0);
        stack<int>st;
        for(char c:s)
        {
            count[c-'a']++;
        }

        for(char c:s)
        {
            count[c-'a']--;
            if(inside[c-'a']==true)
            {
                continue;
            }
            else
            {
                
                while(!st.empty()&&st.top()>c&&count[st.top()-'a']>=1)
                {
                    inside[st.top()-'a']=false;
                    st.pop();


                }
                st.push(c);
                inside[c-'a']=true;

            }
        }
        string ans="";
        while(!st.empty())
        {
            char c=st.top();
            ans=c+ans;
            st.pop();

        }
        return ans;
    }
};
