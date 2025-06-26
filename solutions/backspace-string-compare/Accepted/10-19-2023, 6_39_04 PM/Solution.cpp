// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for(int i = 0;i < s.length();i++)
        {
            if(i - 1 >= 0 && s[i] == '#')
            {
                s.erase(i-1,2);
                i-=2;
            }
            else if(i - 1 < 0 && s[i] == '#')
            {
                s.erase(i,1);
                i--;
            }
        }
        for(int i = 0;i < t.length();i++)
        {
            if(i - 1 >= 0 && t[i] == '#')
            {
                t.erase(i-1,2);
                i-=2;
            }
            else if(i - 1 < 0 && t[i] == '#')
            {
                t.erase(i,1);
                i--;
            }
        }
        return s == t;

    }
};