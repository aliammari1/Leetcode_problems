// https://leetcode.com/problems/number-of-employees-who-met-the-target

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int numbers = 0;
        for(auto& number : hours)
            if(number >= target)
                numbers++;
        return numbers;
    }
};