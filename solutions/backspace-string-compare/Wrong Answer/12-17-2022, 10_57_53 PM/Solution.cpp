// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = count(s.begin(),s.end(),'#');
        int n2 = count(t.begin(),t.end(),'#');
        if((n1 == n2 && s.size()==t.size()) || (n1 == s.size() && n2 == t.size()))
            return true;
        return false;
    }
};