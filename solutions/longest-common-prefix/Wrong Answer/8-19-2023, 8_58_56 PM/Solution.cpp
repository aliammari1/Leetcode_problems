// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        int index = 0,count = 1;
        for(int i = 0;i < strs.size()-1;i++)
        {
            char c = strs[i][index];
            if(strs[i+1][index] == c)
                count++;
            else
                break;
            if(count == strs.size())
            {
                s+=strs[i][index];
                i = -1;
                index++;
                count = 1;
            }
        }
        return s;
    }
};