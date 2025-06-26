// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string str = "";
        int l = gcd(str1.length(),str2.length());
        if(str2.substr(0,l) == str1.substr(0,l))
            return str1.substr(0,l);
        return "";
    }
};