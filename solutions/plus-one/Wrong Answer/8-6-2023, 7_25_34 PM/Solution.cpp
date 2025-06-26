// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if(digits[size - 1] < 9)
            digits[size - 1]++;
        else
        {
            for(int i = size - 1;i >= 0; i--)
            {
                digits[i]++;
                if(i == 0 && digits[0] == 10)
                {
                    digits.push_back(0);
                    digits[0]++;
                }
                digits[i]=digits[i] % 10;
            }

        }
        return digits;
    }
};
