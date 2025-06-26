// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        vector<vector<string>> anags;
        vector<string> strings(strs);
        bool found = false;
        for(int i = 0;i < strings.size();i++)
            sort(strings[i].begin(),strings[i].end());
        for(int i = 0;i < strings.size();i++)
        {
            for(int j = 0;j < anagrams.size();j++)
            {
                for(int k = 0;k < anagrams[j].size();k++)
                {
                    //cout << i << " " << j << " " << k << " " << anagrams[j][k] << endl;
                    if(anagrams[j][k] == strings[i])
                    {
                        anagrams[j].push_back(strings[i]);
                        anags[j].push_back(strs[i]);
                        found = true;
                        break;
                    }
                    else
                        found = false;
                }
                if(found) break;
            }
            if(!found)
            {
                anagrams.push_back(vector(1,strings[i]));
                anags.push_back(vector(1,strs[i]));
            }
        }
        return anags;
    }
};