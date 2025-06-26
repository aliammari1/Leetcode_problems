// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string str = "";
        int l = gcd(str1.length(),str2.length());
        int max = str1.length() > str2.length() ? str1.length() : str2.length();
        for(int i = 0;i < max;i+=l)
        {
            cout << str2.substr(0,l) << " " << str1.substr(i,l) << endl;
            if(i < str2.length() && str1.substr(0,l) != str2.substr(i,l))
                return "";
            if(i < str1.length() && str2.substr(0,l) != str1.substr(i,l))
                return "";
        }
        if(str2.substr(0,l) == str1.substr(0,l))
            return str1.substr(0,l);
        return "";
    }
};