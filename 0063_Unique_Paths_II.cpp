#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    public:
    // another solution: C(m, n)(m > n)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int i, j;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

	    vector<vector<long long> > dp(m, vector<long long>(n, 0));
        
        if(obstacleGrid[0][0] == 0) dp[0][0] = 1;

        for(i = 1; i < m; i++) if(obstacleGrid[i][0] == 0) dp[i][0] = dp[i-1][0];
        for(j = 1; j < n; j++) if(obstacleGrid[0][j] == 0) dp[0][j] = dp[0][j-1];

        for(i = 1; i < m; i++){
            for(j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1)
                        dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    Solution solve;
    vector<vector<int> > input = {{0, 0, 0},{0,1,0},{0,0,0}};
    //vector<vector<int> > input = {{1,0}};
    
    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++)
            cout << input[i][j] << " ";
        cout << endl;
    }

    cout << "Output: " << solve.uniquePathsWithObstacles(input) << endl;
        
    return 0;
}
