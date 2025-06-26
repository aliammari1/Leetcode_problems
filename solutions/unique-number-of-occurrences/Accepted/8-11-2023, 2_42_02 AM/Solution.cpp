// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> occurences;
        int k = 0,j=0;
        sort(arr.begin(),arr.end());
        for(int i = 0;i < arr.size();i++)
        {
            k = count(arr.begin(),arr.end(),arr[i]);
            cout << k << endl;
            occurences.push_back(k);
            j = arr[i];
            while(arr[i] == j && i < arr.size())
            arr.erase(arr.begin()+i);
            i--;
        }
        for(int i = 0;i < occurences.size();i++)
        if(count(occurences.begin(),occurences.end(),occurences[i]) > 1)
        return false;
        return true;
    }
};