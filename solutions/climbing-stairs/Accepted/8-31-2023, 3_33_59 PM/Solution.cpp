// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climb(map<int,int>& m,int n)
    {
        if(m.find(n) != m.end())
            return m[n];
        int result;
        if(n < 3)
            result = n;
        else
            result = climb(m,n-1) + climb(m,n-2);
        m[n] = result;
        return result;
    }
    int climbStairs(int n) {
        map<int,int> m;
        return climb(m,n);
    }
};