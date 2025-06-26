// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        string sMax = to_string(INT_MAX);
        string sMin = to_string(INT_MIN);
        if(x < 0) s.erase(0,1);
        std::reverse(s.begin(),s.end());
        cout << s << endl;
        cout << sMax << endl;
        cout << sMin << endl;
        for(int  i=0;i<s.length();i++)
        if(s.length() == sMax.length() && s[i] > sMax[i])
            return 0;
        x = x < 0 ?  - stoull(s) : stoull(s);
        return x;
    }
};