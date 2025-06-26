// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rowCount = matrix.size();
    int columnCount = matrix[0].size();
    pair<int,int> start = {0,0};
    pair<int,int> end = {rowCount-1,columnCount-1};
    pair<int,int> mid = {0,0};
    if(matrix[start.first][start.second] == target || matrix[end.first][end.second] == target) return true;
    if(matrix[start.first][start.second] > target || matrix[end.first][end.second] < target)   return false;
    while(start.first <= end.first)
    {
        if(matrix[mid.first][0] > target)
            end.first = mid.first - 1;
        else if(matrix[mid.first][0] < target)
            start.first = mid.first + 1;
        else
            return true;
        mid.first = (start.first + end.first) / 2;
    }
    while(start.second <= end.second)
    {
        
        if(matrix[mid.first][mid.second] > target)
            end.second = mid.second - 1;
        else if(matrix[mid.first][mid.second] < target)
            start.second = mid.second + 1;
        else
            return true;
        mid.second = (start.second + end.second) / 2;
    }
    return false;
    }
};