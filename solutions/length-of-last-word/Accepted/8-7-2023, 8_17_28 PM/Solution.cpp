// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int k = 0;
        for(int i = s.length() - 1;i >=0 ;i--)
        {
            if(s[i] != ' ')
            {
                k++;
                if(i - 1 >= 0 && s[i - 1] == ' ')
                  break;
            }
        }
            
        return k;
    }
};