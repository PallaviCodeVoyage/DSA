
class Solution {
public:
    int longestValidParentheses(string s) {
        int max_length = 0;
        stack<int> st;
        int start = -1; // Starting index of the current potential valid substring

        for (int i = 0; i < s.length(); ++i)
         {
            if (s[i] == '(') 
            {
                st.push(i); // Push the index of opening parenthesis onto stack
            } else 
            
            
            
            { // s[i] == ')'
                if (!st.empty())
                 {
                    st.pop(); // Matching opening parenthesis found
                    if (!st.empty()) 
                    {
                        max_length = max(max_length, i - st.top()); // Calculate current length of valid substring
                    } else 
                    {
                        max_length = max(max_length, i - start); // Calculate current length of valid substring
                    }
                } else
                 {
                    start = i; // Reset the starting index
                }
            }
        }

        return max_length;
    }
};
