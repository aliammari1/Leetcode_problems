// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer;
        int s = 0;
        for(int i = 0;i<temperatures.size();i++)
        {
        for(int j = i; j < temperatures.size();j++)
            {
                if(temperatures[i]<temperatures[j])
                {
                        answer.push_back(s);
                        break;
                }
                else
                    s++;
                if(j == temperatures.size() - 1)
                    answer.push_back(0);

            }
        s=0;
        }
        return answer;
    }
};