


class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        char ch;
        int i=0,l;
        l=s.length();
        for(;i<l;i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
              s1.push(s[i]);
            }
            else if(s[i]==')'||s[i]=='}'||s[i]==']')
            {
                if(s1.empty()||(s[i]==')'&&s1.top()!='(')||(s[i]=='}'&&s1.top()!='{')||(s[i]==']'&&s1.top()!='['))
                {
                    return 0;
                }
                else{
                    s1.pop();
                }

            }
        }
        return(s1.empty())?1:0;

        
    }
};
