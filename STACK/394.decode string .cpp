class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<char> charStack;
        int currentNum = 0;
        
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                currentNum = currentNum * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(currentNum);
                currentNum = 0;
                charStack.push(c);
            } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                charStack.push(c);
            } else if (c == ']') {
                string temp = "";
                while (!charStack.empty() && charStack.top() != '[') {
                    temp = charStack.top() + temp;
                    charStack.pop();
                }
                charStack.pop();  // Pop the '['

                int repeatTimes = numStack.top();
                numStack.pop();
                string repeatedStr = "";
                for (int i = 0; i < repeatTimes; ++i) {
                    repeatedStr += temp;
                }

                for (char ch : repeatedStr) {
                    charStack.push(ch);
                }
            }
        }

        string result = "";
        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }

        return result;
    }
};
/*** yha pe i can use another approach why not to create a whole string which is inside the parenthesis and use a stack of string type and insert it*/

/***both have O(N^2)***/
