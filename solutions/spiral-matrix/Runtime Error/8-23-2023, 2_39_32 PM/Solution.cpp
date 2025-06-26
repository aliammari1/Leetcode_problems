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
            cout << "-----------------------1-----------------" << endl;
            for(int j = i;j < matrix[i].size() - 1 - i;j++)
            {
                cout << matrix[i][j] << endl;
                v.push_back(matrix[i][j]);
            }
            cout << "-----------------------2-----------------" << endl;
            for(int j = i;j < matrix.size() - 1 - i;j++)
            {
                cout << matrix[j][matrix[i].size() - 1 - i] << endl;
                v.push_back(matrix[j][matrix[i].size() - 1 - i]);
            }
            cout << "-----------------------3-----------------" << endl;
            for(int j = matrix[i].size() - 1 - i;j > i;j--)
            {
                cout << matrix[matrix.size() - 1 - i][j] << endl;
                v.push_back(matrix[matrix.size() - 1 - i][j]);
            }
            cout << "-----------------------4-----------------" << endl;
            for(int j = matrix.size() - 1 - i;j > i;j--)
            {
                cout << matrix[j][i] << endl;
                v.push_back(matrix[j][i]);
            }
            i++;
        }
        return v;
    }
};