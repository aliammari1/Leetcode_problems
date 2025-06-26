// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        string ch;
        vector<string> vs;
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == ' ')
            {
                ch = "";
            }
            else
            {
                ch += s[i];
                if(i + 1 == s.length() || s[i+1] == ' ')
                    vs.push_back(ch);
            }
        }
        ch = "";
        for(int i = vs.size() - 1;i >= 0;i--)
        {
            ch += vs[i];
            if(i != 0)
            ch += ' ';
        }
        return ch;
    }
};