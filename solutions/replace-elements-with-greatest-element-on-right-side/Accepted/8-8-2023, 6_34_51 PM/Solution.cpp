// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for(int i = 0;i < arr.size();i++)
        {
            i == arr.size() - 1 ? arr[i] = -1 : arr[i] = *max_element(arr.begin()+i+1,arr.end());
        }
        return arr;
    }
};