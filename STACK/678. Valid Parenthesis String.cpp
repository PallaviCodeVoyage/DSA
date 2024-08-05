class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftParen; // Stack to keep track of '(' positions
        stack<int> asterisk;  // Stack to keep track of '*' positions
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                leftParen.push(i);
            } else if (s[i] == '*') {
                asterisk.push(i);
            } else { // s[i] == ')'
                if (!leftParen.empty()) {
                    leftParen.pop();
                } else if (!asterisk.empty()) {
                    asterisk.pop();
                } else {
                    return false; // No matching '(' or '*' for ')'
                }
            }
        }
        
        // Now we need to match any remaining '(' with '*' if possible
        while (!leftParen.empty() && !asterisk.empty()) {
            if (leftParen.top() < asterisk.top()) { // The '*' must come after '('
                leftParen.pop();
                asterisk.pop();
            } else {
                return false;
            }
        }
        
        return leftParen.empty();
    }
};
