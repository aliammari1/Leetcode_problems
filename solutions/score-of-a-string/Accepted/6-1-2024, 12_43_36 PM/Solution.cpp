// https://leetcode.com/problems/score-of-a-string

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i = 0;i < s.length()-1;i++)
        {
            score += abs(s[i+1]- s[i]);
        }
        return score;
    }
};