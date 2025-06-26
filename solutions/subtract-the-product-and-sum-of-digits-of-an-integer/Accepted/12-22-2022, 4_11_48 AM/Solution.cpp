// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer

class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = to_string(n);
        vector<int> v;
        for(int i = 0;i < s.length();i++)
        v.push_back(s[i]-48);
        int p = 1;
        for(auto it = v.begin();it != v.end();it++)
            p *= *it;
        int sum = 0;
        for(auto it = v.begin();it != v.end();it++)
            sum += *it;
        return p - sum;

    }
};