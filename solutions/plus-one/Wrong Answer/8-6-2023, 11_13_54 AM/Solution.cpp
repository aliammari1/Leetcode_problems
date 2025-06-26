// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int i = size-1;
        while(i >= 0 && digits[i] == 9)
        {
            digits[i]++;
            digits[i]%=10;
            i--;
        }
        bool test = false;
        for(int j = 0;j < size;j++)
            if(digits[j]!=0)
                test = true;
        if(!test)
        {
            digits.push_back(0);
            digits[0]++;
        }
        if(i == size - 1)
        {
            digits[i]++;
        }
        return digits;
    }
};