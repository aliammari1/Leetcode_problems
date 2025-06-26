// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int number(map<int,int>& m,int n)
    {
        if(m.find(n) != m.end())
            return m[n];
        int result;
        if(n < 2)
            result = n;
        else 
            result = number(m,n-1) + number(m,n-2);
        m[n] = result;
        return result;
        
    }
    int fib(int n) {
        map<int,int> m;
        return number(m,n);
    }
};