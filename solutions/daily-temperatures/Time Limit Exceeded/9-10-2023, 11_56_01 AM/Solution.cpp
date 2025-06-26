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
            while(j < temperatures.size())
            {
                // cout << temp << " " << temperatures[j] << " ";
                if(temp < temperatures[j])
                {
                    s.push(temperatures[j]);
                    break;
                }
                s.push(temperatures[j]);
                j++;
            }
            // cout << endl;
            v.push_back(j == temperatures.size() ? 0 : s.size());
        }
        return v;
    }
};