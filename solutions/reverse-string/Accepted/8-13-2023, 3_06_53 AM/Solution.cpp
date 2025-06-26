// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void rever(vector<char>& s,int i = 0)
    {
        if(i == s.size() / 2) return;
        char t = s[i];
        s[i] = s[s.size()-1-i];
        s[s.size()-1-i] = t;
        i++;
        rever(s,i);
        cout << i << endl;
    }
    void reverseString(vector<char>& s) {
        rever(s);
    }
};