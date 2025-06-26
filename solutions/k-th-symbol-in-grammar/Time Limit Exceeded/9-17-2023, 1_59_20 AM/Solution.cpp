// https://leetcode.com/problems/k-th-symbol-in-grammar

class Solution {
public:
    void stringify(string& s,int& n,int& k,char& c)
    {
        if(n == 0) 
        {
            c = s[k-1];
            // cout << s << endl;
            return;
        }
        for(int i = 0;i < s.size();i+=2)
        {
            if(s[i] == '0')
                s.replace(i,1,"01");
            else if(s[i] == '1')
                s.replace(i,1,"10");
        }
        --n;
        // cout << "s: " << s << endl;
        stringify(s,n,k,c);
        return;
    }
    int kthGrammar(int n, int k) {
        char c = ' ';
        string s = "0";
        stringify(s,n,k,c);
        // cout << "c: " << c << endl;
        if(c == '1')
            return 1;
        return 0;
    }
};