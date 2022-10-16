#include "common.hpp"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();

        vector<vector<int>> dp;
        for(int i = 0; i < M; i++){
            dp.push_back(vector<int>(N, 0));
        }

        // for P
        dp[M - 1][N - 1] = max(1 - dungeon[M - 1][N - 1], 1);

        // last row
        for(int j = N - 2; j >= 0; j--){
            dp[M - 1][j] = max(dp[M - 1][j + 1] - dungeon[M - 1][j], 1);
        }

        // last column
        for(int i = M - 2; i >= 0; i--){
            dp[i][N - 1] = max(dp[i + 1][N - 1] - dungeon[i][N - 1], 1);
        }
    
        // for other
        for(int i = M - 2; i >= 0; i--){
            for(int j = N - 2; j >= 0; j--){
                dp[i][j] = max(min(dp[i + 1][j] - dungeon[i][j], dp[i][j + 1] - dungeon[i][j]), 1);
            }
        }
        return dp[0][0];
    }
};

int main(){
    Solution solve;
    vector<vector<int>> x = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    //vector<vector<int>> x = {{0}};
    cout << solve.calculateMinimumHP(x) << endl;
    return 0;
}
