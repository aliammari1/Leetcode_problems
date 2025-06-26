// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        vector<string> vs;
        string ch = "";
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == ' ')
            {
                ch = "";
            }
            else
            {
                ch += s[i];
                if(i+1 == s.length() || s[i+1] == ' ')
                    vs.push_back(ch);
            }
        }
        ch = "";
        for(int i = 0;i < vs.size();i++)
        {
            reverse(vs[i].begin(),vs[i].end());
            ch += vs[i];
            if(i != vs.size()-1)
            ch += ' ';
        }
        return ch;
    }
};