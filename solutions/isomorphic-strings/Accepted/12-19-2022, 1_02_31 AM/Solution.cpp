// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m;
        map<char,char> m1;
        for(int i=0;i < s.size();i++)
        {
            auto it = m.find(s[i]);
            if(it != m.end())
                if(it->second != t[i])
                    return false;
            m.insert(m.begin(),pair<char,char>(s[i],t[i]));
            auto it1 = m1.find(t[i]);
            if(it1 != m1.end())
                if(it1->second != s[i])
                    return false;
            m1.insert(m1.begin(),pair<char,char>(t[i],s[i]));
        }
        return true;
    }
};