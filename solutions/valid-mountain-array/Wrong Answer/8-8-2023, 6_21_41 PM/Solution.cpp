// https://leetcode.com/problems/valid-mountain-array

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       bool test1 = false,test2 = false,test3 = true;
        for(int i = 0;i < arr.size() - 1;i++)
        {
            if(arr[i + 1] == arr[i])
                return false;
            else if(arr[i + 1] > arr[i] && test2)
                return false;
            else if(arr[i + 1] > arr[i])
                test1 = true;
            else if(arr[i + 1] < arr[i] && test1)
                test2 = true;
        }
        return test1 && test2;
    }
};