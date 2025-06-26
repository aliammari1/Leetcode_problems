// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v;
        int j = 0;
        for(int i = 0;i < temperatures.size();i++)
        {
            stack<int> s;
            int temp = temperatures[i];
            j = i + 1;
            while(j < temperatures.size() - 1)
            {
                
                if(temp < temperatures[j])
                {
                s.push(temperatures[j]);
                break;
                }
                if(temp >= temperatures[j])
                    s.push(temperatures[j]);
                j++;
            }
            v.push_back(s.size());
        }
        return v;
    }
};