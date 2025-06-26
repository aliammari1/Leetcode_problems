// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int value = 0;
        int size = digits.size();
        for(int i = 0;i < size;i++)
        {
        value += digits[i] * pow(10,size - 1 - i);
        }
        value++;
        vector<int> numbers;
        int power = 0;
        for(int i = 0;i < size;i++)
        {
            power = pow(10,size - 1 - i);
            numbers.push_back(value / power);
            value = value % power;
        }
        if(numbers[0] == 10)
        {
            numbers.push_back(0);
            numbers[0] = 1;
        }
        return numbers;
        }
};