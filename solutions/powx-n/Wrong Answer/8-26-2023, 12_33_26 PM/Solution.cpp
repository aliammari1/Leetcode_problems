// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(x >= 0)
            return x * pow(x,n-1);
        return 1 / (x * pow(x,n-1));
    }
};