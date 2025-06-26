// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1;i < s.length() / 2;i++)
            for(int j = i;j < s.length();j+=i)
            {
                //cout << i << ' ' << j << ' ' << s.substr(0,i) << ' ' <<  s.substr(j,i) << endl;
                if(s.substr(0,i) != s.substr(j,i))
                    break;
                else if(i + j == s.length())
                        return true;
            }
        return false;
    }
};