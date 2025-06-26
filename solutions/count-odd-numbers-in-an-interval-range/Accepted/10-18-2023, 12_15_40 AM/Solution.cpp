// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

class Solution {
public:
    int countOdds(int low, int high) {
        int s = 0;
        for(int i = low; i<=high;i++)
        if(i%2)
        s++;
        return s;
    }
};