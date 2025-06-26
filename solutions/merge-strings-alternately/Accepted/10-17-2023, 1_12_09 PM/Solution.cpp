// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word3 = "";
        int start1 = 0,start2 = 0;
        while(start1 < word1.length() || start2 < word2.length())
        {
            if(start1 < word1.length())
                word3 += word1[start1];
            if(start2 < word2.length())
                word3 += word2[start2];
            start1++;
            start2++;
        }
        return word3;
    }
};