// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(x < 0)
        s.erase(0,1);
        std::reverse(s.begin(),s.end());
        return x < 0 ?  - stoull(s) : stoull(s);
    }
};