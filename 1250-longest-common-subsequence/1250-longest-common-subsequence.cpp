class Solution {
public:
    int helper(string& text1, string& text2, int index1, int index2, vector<vector<int>>& t){
        if(index1 < 0 || index2 < 0) return 0;
        if(t[index1][index2] != -1) return t[index1][index2];
        if(text1[index1] == text2[index2]){
            t[index1][index2] = 1 + helper(text1, text2, index1-1, index2-1, t);
        }
        else{
            t[index1][index2] = max(helper(text1, text2, index1, index2-1, t), 
                helper(text1, text2, index1-1, index2, t));
        }
        return t[index1][index2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> t(text1.size(), vector<int>(text2.size(), -1));
        return helper(text1, text2, text1.size()-1, text2.size()-1, t);
    }
};