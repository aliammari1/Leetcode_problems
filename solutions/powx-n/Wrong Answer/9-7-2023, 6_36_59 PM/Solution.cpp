// https://leetcode.com/problems/powx-n

class Solution {
public:
    void power(double& x,double& start,int n)
    {
        // cout << start << endl;
        if(n == 0)
            return;
        
        start = start * ( n > 0 ? x : 1 / x);
        power(x,start,abs(n)-1);
    }
    double myPow(double x, int n) {
        if(x == 1 || x == 0) return x;
        if(x == -1 && n % 2) return -1;
        if(x == -1 &&  !(n % 2)) return 1;
        double start = 1;
        power(x,start,n);
        if(n > 0)
            return start;
        return 1 / start;
    }
};