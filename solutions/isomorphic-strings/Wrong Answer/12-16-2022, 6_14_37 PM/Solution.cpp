// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m;
        for(int i = 0;i < s.size();i++)
        {
            if(m.find(s[i]) != m.end())
            if(m.find(s[i])->second != t[i])
            return false;
            m.insert(m.begin(),pair<char,char>(s[i],t[i]));
        }
        for(auto it = m.begin();it != m.end();it++)
            cout << it->first << " " << it->second << endl;
        return true;
    }
};