// https://leetcode.com/problems/diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> v;
        int i = 0,j = 0,k = 1;
        bool middle = false;
        while(v.size() != mat.size() * mat[0].size() || k != 0)
        {
            cout << i << " " << j << " " << k << endl;
            while(j >=0 && i >= 0 && i < mat.size())
            {
                cout << "before: " << i << " " << j << " " << k << endl;
                v.push_back(mat[i][j]);
                if(k % 2 == 0)
                {
                    j--;
                    i++;
                }
                else
                {
                    j++;
                    i--;
                }
                cout << "after: " << i << " " << j << " " << k << endl;
            }
            if(i < 0 && j == mat[0].size())
            {
                middle = true;
                i++;
            }
            if(middle)
                k--;
            else
                k++;
            i++;
            if(j < 0)
                j = 0;
            if(i == mat.size())
                i--;
            if(j == mat[0].size())
                j--;
            if(k==0)
                break;
            
        }
        v.push_back(mat[mat.size()-1][mat[0].size()-1]);
        return v;
    }
};