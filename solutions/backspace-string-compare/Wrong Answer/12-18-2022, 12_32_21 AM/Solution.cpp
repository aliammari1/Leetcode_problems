// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        for(int i = 0;i<s.size();i++)
            if(s[i]=='#')
                {
                    if(s.size() == count(s.begin(),s.end(),'#'))
                        return true;
                    if(i==0)
                        {
                            s.erase(i,1);
                            i--;
                        }
                    else
                        {
                            s.erase(i-1,2);
                            i-=2;
                        }
                }
        cout << s << endl;
        for(int i = 0;i<t.size();i++)
            if(t[i]=='#')
                {
                    if(t.size() == count(t.begin(),t.end(),'#'))
                        return true;
                    if(i==0)
                        {
                            t.erase(i,1);
                            i--;
                        }
                    else
                        {
                            t.erase(i-1,2);
                            i-=2;
                        }
                }
        cout << t << endl;
        if(s == t)
            return true;
        return false;
    }
};