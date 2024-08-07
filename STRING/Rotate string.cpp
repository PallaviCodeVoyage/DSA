class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        {
            return false;
        }
        string temp=s+s;
        if(temp.find(goal)!=string::npos)
        {
           return true;
        }
        return false;
        
    }
};
/***kmp performs the task of finding that whether the particular string is present in the main string or not and find just do in 1 line*/
