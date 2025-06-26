// https://leetcode.com/problems/baseball-game

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v;
        for(int i = 0;i < operations.size();i++)
        {
            if(operations[i][0] == '+')
            {
                v.push_back(v[v.size() - 1] + v[v.size() - 2]);
            }
            else if(operations[i][0] == 'C')
            {
                v.pop_back();
            }
            else if(operations[i][0] == 'D')
            {
                v.push_back(v[v.size() - 1] * 2);
            }
            else
            {
                v.push_back(stoi(operations[i]));
            }
        }
        return accumulate(v.begin(),v.end(),0);
    }
};