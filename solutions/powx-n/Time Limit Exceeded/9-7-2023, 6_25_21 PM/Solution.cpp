// https://leetcode.com/problems/powx-n

class Solution {
public:
    void power(double& x,double& start,int n)
    {
        // cout << start << endl;
        if(n == 0)
            return;
        start = start * x;
        power(x,start,abs(n)-1);
    }
    double myPow(double x, int n) {
        double start = 1;
        power(x,start,n);
        if(n > 0)
            return start;
        return 1 / start;
    }
};