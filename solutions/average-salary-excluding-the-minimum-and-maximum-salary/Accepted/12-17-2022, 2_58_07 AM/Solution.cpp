// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

class Solution {
public:
    double average(vector<int>& salary) {
    sort(salary.begin(),salary.end());
    int sum = 0;
    int size = salary.size();
    for(int i = 1;i < size - 1;i++)
        sum+=salary[i];
    return static_cast<double>(sum) / (size - 2);
    }
};