class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int sr = 0;
        int sc = col-1;
        while(sr < row && sc >=0){
            if(matrix[sr][sc] == target){
                return true;
            }
            if(matrix[sr][sc] < target){
                sr++;
            }
            else sc--;
        }
        return false;
    }
};