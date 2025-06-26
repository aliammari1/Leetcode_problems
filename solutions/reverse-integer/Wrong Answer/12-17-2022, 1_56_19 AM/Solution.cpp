// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(x < 0)
        s.erase(0,1);
        std::reverse(s.begin(),s.end());
        if(x > pow(2,31)-1  || x < - pow(2,31))
        return 0;
        return x < 0 ?  - stoll(s) : stoll(s);
    }
};