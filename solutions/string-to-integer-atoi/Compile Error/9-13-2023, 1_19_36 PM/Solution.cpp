// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        bool pos = true;
        int i = 0;
        int len = 0,begin = 0,sum = 0;
        while(s[i] == ' ' || (s[i] < 48 && s[i] != 43 && s[i] != 45 ) || s[i] > 57)
        {
            // if(s[i] > 57)
            //     return 0;
            i++;
        }
        if(s[i] == '-')
        {
            pos = false;
            i++;
        }
        else if(s[i] == '+')
        {
            i++;
        }
        begin = i;
        while(i < s.length() && s[i] != ' ' )
        {
            
            i++;
            len++;
        }
        i = begin;
        while(len > 0)
        {
            // cout << (s[i] - 48) << " " << len << endl;
            sum += (s[i] - 48) * pow(10,len - 1);
            if(sum >= INTMAX)
                return INTMAX;
            if(sum <= INTMIN)
                return INTMIN;
            len--;
            i++;
        }
        if(!pos) sum = -sum;
        return sum;
    }
};