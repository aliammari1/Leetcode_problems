// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int neg = 0;
        if(x < 0)
        {
            s.erase(0,1);
            neg = 1;
        }
        std::reverse(s.begin(),s.end());
        cout << s << endl;
        x = x < 0 ?  - stoull(s) : stoull(s);
        if(x >= INT_MAX  || x <= INT_MIN)
            return 0;
        return x;
    }
};