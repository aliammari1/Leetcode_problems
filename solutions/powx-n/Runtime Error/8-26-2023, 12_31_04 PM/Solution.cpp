// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        return x * pow(x,n-1);
    }
};