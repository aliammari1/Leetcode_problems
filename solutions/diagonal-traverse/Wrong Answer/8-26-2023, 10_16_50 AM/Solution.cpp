// https://leetcode.com/problems/diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> v;
        int i = 0,j = 0,k = 1;
        while(v.size() != mat.size() * mat[0].size())
        {
            cout << "begin: " << i << " " << j << endl;
            while((j >=0 && i >= 0 && i < mat.size() && j < mat[0].size()))
            {
                cout << "before: " << i << " " << j << endl;
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
                cout << "after: " << i << " " << j << endl;
            }
            
            
            if(i <= 0 && j == mat[0].size())
            {
                i+=2;
                j--;
            }
            if(i == mat.size() && j <= 0)
            {
                i--;
                j+=2;
            }
            if(i < 0)
                i = 0;
            if(j < 0)
                j = 0;
            k++;
            if(k == 10)
                break;
        }
        return v;
    }
};