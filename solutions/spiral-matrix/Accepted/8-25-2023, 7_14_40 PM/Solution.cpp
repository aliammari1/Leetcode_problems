// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int i = 0;
        int rows = matrix.size();
        int columns = matrix[0].size();
        while(v.size() != rows * columns)
        {
            for(int j = i;j < columns - i && v.size() != rows * columns;j++)
                v.push_back(matrix[i][j]);
            for(int j = i + 1;j < rows - i - 1 && v.size() != rows * columns;j++)
                v.push_back(matrix[j][columns - 1 - i]);
            for(int j = columns - i - 1;j > i && v.size() != rows * columns;j--)
                v.push_back(matrix[rows - i - 1][j]);
            for(int j = rows - i - 1;j > i && v.size() != rows * columns;j--)
                v.push_back(matrix[j][i]);
            i++;
        }
        return v;
    }
};