// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int s = 0;
        for(int i = 0;n!=0;i++)
        {
            if(n % 2 == 1)
                s++;
            n = n >> 1;
        }
        return s;
    }
};