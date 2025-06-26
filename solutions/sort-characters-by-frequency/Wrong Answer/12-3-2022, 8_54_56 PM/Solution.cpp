// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(), s.end());
        return s;
    }
};