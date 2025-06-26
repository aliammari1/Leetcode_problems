// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if(digits[size - 1] != 9)
        {
            digits[size-1]++;
            return digits;
        }
        int i = size-1;
        int n = digits[0];
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
            if(n == 9)
            digits.push_back(0);
            digits[0]++;
        }
        if(i == size - 1 && size > 1)
        {
            digits[i]++;
        }
        return digits;
    }
};