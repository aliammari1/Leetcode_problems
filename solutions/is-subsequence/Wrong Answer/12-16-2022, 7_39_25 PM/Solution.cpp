// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size = 0;
        int k = 0;
        for(int i = 0; i < s.size() ; i++)
            for(int j = k; j < t.size();j++)
                if(s[i] == t[j])
                {
                    k=j+1;
                    size++;
                }
        return size == s.size();

    }
};