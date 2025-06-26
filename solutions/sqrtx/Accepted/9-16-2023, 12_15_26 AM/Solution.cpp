// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int start = 1, end = x / 2 + 1;
        long long mid = 0;
        while(start < end)
        {
            mid = start + (end - start) / 2;
            // cout << start << " " << end << " " << mid << endl;
            if(mid * mid == x)
                return mid;
            if(start == end - 1)
                return start;
            else if(mid * mid < x)
                start = mid;
            else if(mid * mid > x)
                end = mid;
        }
        return -1;
    }
};