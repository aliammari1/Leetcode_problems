// https://leetcode.com/problems/matrix-diagonal-sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0,i = 0, j = 0;
        while(i < mat.size() && j < mat[i].size())
        {
            sum += mat[i][j];
            i++, j++;
        }
        i = 0;
        j = mat[0].size() - 1;
        while(i < mat.size() && j >= 0)
        {
            if((mat.size() % 2 == 0) || (mat.size() % 2 == 1 && i != mat.size() / 2))
            sum += mat[i][j];
            i++, j--;
        }
        return sum;
    }
};