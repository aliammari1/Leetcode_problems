// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length(),j = b.length(),carry = 0;
        string c = "";
        while(b.length() < a.length())
        {
             b.insert(0,"0");
        }
        while(a.length() < b.length())
        {
             a.insert(0,"0");
        }
        while(i - 1 >= 0 && j - 1>= 0)
        {
            if(a[i - 1] == '1' && b[j - 1] == '1')
            {
                c += a[i - 1] - 1 + carry;
                carry = 1;
            }
            else if(a[i - 1] == '0' && b[j - 1] == '0')
            {
                if(carry == 0)
                c += a[i - 1];
                else
                {
                    c += a[i - 1] + 1;
                    carry = 0;
                }
            }
            
            else if(a[i - 1] == '1' && b[j - 1] == '0')
            {
                if(carry == 0)
                    c += a[i - 1];
                else
                {
                    c += a[i - 1] - 1;
                    carry = 1;
                }
            }
            else if(a[i - 1] == '0' && b[j - 1] == '1')
            {
                if(carry == 0)
                    c += a[i - 1] + 1;
                else
                {
                    c += a[i - 1];
                    carry = 1;
                }
            }
            i--;
            j--;
        }
        if(a.length() == b.length() && carry == 1) c += "1";
        reverse(c.begin(),c.end());
        return c;
    }
};