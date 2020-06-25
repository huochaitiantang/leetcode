#include "common.hpp"

class Solution {
public:
    // the last case not passed
    int helper(vector<vector<int>>& triangle, int level, int index){
        if(level == triangle.size()) return 0;
        return min(helper(triangle, level + 1, index), 
                   helper(triangle, level + 1, index + 1)) + triangle[level][index];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        //return helper(triangle, 0, 0);
        int n = triangle.size();
        vector<int> dp(n + 1, 0);
        for(int i = n; i > 0; i--){
            for(int j = 0; j < i; j++){
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i - 1][j];
            }
        }
        return dp[0];
    }
};

int main(){
    Solution solve;
    vector<vector<int>> vs = {{2},{3,4},{6,5,7},{4,1,8,3}}; 
    std::cout << solve.minimumTotal(vs) << std::endl;
    return 0;
}
