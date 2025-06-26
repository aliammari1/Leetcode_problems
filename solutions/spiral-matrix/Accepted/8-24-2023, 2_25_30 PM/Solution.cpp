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
            cout << "---------------1----------------" << endl;
            for(int j = i;j < columns - i && v.size() != rows * columns;j++)
            {
                cout << matrix[i][j] << endl;
                v.push_back(matrix[i][j]);
            }
            cout << "---------------2----------------" << endl;
            for(int j = i + 1;j < rows - i - 1 && v.size() != rows * columns;j++)
            {
                cout << matrix[j][columns - 1 - i] << endl;
                v.push_back(matrix[j][columns - 1 - i]);
            }
            cout << "---------------3----------------" << endl;
            cout << i << " " << columns - i << endl;
            for(int j = columns - i - 1;j > i && v.size() != rows * columns;j--)
            {
                cout << matrix[rows - i - 1][j] << endl;
                v.push_back(matrix[rows - i - 1][j]);
            }
            cout << "---------------4----------------" << endl;
            for(int j = rows - i - 1;j > i && v.size() != rows * columns;j--)
            {
                cout << matrix[j][i] << endl;
                v.push_back(matrix[j][i]);
            }
            i++;
        }
        return v;
    }
};