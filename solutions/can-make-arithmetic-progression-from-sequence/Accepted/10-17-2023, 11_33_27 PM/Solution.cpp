// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr[0] - arr[1];
        for(int i = 0;i < arr.size() - 1;i++)
            if(arr[i] - arr[i+1] != n)
                return false;
        return true;
    }
};