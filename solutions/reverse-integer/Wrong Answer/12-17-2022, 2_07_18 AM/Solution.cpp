// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(x < 0)
        s.erase(0,1);
        std::reverse(s.begin(),s.end());
        x = x < 0 ?  - stoull(s) : stoull(s);
        if(x >= pow(2,15)-1  || x <= -pow(2,15))
            return 0;
        return x;
    }
};