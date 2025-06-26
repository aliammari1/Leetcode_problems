// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n != 1)
        {
            if(n % 3 != 0 || n == 0)
                return false;
            n /= 3;
            cout << n << endl;
        }
        return true;
    }
};