#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> tokenizeString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

int main() {
    std::string str = "This is an example string";
    char delimiter = ' ';
    std::vector<std::string> tokens = tokenizeString(str, delimiter);
    
    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }
    
    return 0;
}


/***its application in this ques*//
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        vector<string>indexwise;
        string s;
        char deli=' ';
        while(getline(ss,s,deli))
        {
            indexwise.push_back(s);
        }
        int n=indexwise.size();
        int w=searchWord.length();
        for(int i=0;i<n;i++)
        {
            if(indexwise[i].substr(0,w)==searchWord)
            {
                return i+1;
            }

        }
        return -1;

        
    }
};
