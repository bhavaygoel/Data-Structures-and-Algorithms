class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> v;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0)
                    v.push_back({i,j});
            }
        }
        for(auto it: v){
            auto [row, col] = it;
            for(int i=0; i<matrix[0].size(); i++)
                matrix[row][i] = 0;
            for(int j=0; j<matrix.size(); j++)
                matrix[j][col] = 0;
        }
    }
};