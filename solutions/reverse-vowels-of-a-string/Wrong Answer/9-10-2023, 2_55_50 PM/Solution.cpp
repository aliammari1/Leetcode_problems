// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    string reverseVowels(string s) {
        string s1;
        int start = 0, end = s.length() - 1;
        while(start <= end)
        {
            if(s[start] == 'a' || s[start] == 'e' || s[start] == 'i' || s[start] == 'o' || s[start] == 'u')
            {
            if(s[end] == 'a' || s[end] == 'e' || s[end] == 'i' || s[end] == 'o' || s[end] == 'u')
            {
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else
            {
                end--;
            }
            }
            else if(s[end] == 'a' || s[end] == 'e' || s[end] == 'i' || s[end] == 'o' || s[end] == 'u')
            start++;
            else
            {
                start++;
                end--;
            }


        }
        return s;
    }
};