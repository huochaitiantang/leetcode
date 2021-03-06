#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    public:
    // another solution: C(m, n)(m > n)
    int uniquePaths(int m, int n) {
        int i, j;
	    vector<vector<int> > dp(m, vector<int>(n, 0));
        for(i = 0; i < m; i++) dp[i][0] = 1;
        for(j = 0; j < n; j++) dp[0][j] = 1;

        for(i = 1; i < m; i++){
            for(j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
};

int main(){
    Solution solve;
    int m = 3, n = 2;

    cout << "Input: m=" << m << " n=" << n << endl;
    cout << "Output: " << solve.uniquePaths(m, n) << endl;
        
    return 0;
}
