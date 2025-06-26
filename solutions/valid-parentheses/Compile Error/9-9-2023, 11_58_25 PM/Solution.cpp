// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1)
        stack<char> st;
        for(int i = 0;i < s.length();i++)
        {
        if(s[i] == ')' && !st.empty() && st.top() == '(')
            st.pop();
        else if(s[i] == '}' && !st.empty() && st.top() == '{')
            st.pop();
        else if(s[i] == ']' && !st.empty() && st.top() == '[')
            st.pop();
        else
            st.push(s[i]);
        }
        if(!st.empty())
            return false;
        return true;
    }
};