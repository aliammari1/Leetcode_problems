// https://leetcode.com/problems/powx-n

class Solution {
public:
    double power(double x,int n)
    {
        if(n == 0)
            return 1;
        return x * power(x,abs(n)-1);
    }
    double myPow(double x, int n) {
        // cout << n << endl;
        // if
        if(x == 0 || x == 1)
            return x;
        if(n > 0)
            return power(x,n);
        else
            return 1 / power(x,n);
        return 0;
    }
};