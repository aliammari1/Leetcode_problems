// https://leetcode.com/problems/powx-n

class Solution {
public:
    void power(double x,double& start,int n)
    {
        // cout << start << " " << n << endl;
        if(n == 0)
            return;
        if(start == 0)
            return;
        start *= x;
        power(x,start,--n);
    }
    double myPow(double x, int n) {
        if(x == 1 || x == 0) return x;
        if(x == -1 && n % 2) return -1;
        if(x == -1 &&  !(n % 2)) return 1;
        double start = 1;
        if(n >= 0)
            power(x,start,n);
        else
        {
            x = 1 / x;
            n = abs(n) - 1;
            power(x,start,n);
            start = start *x;
        }
        return start;
    }
};