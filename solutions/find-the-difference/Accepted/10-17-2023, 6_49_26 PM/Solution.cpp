// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i = 0;i < s.length();i++)
        for(int j = 0;j < t.length();j++)
            if(s[i] == t[j])
                {
                    t[j] = '0';
                    s[i] = '0';
                }
        for(int i = 0;i < t.length();i++)
            if(t[i] != '0') 
                return t[i];
        //cout << s << ' ' << t << endl;
        return ' ';
    }
};