#include<iostream>
#include<string>

using namespace std;

class Solution {
    public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        int dp[m + 1][n + 1];
        for(int i = 0; i <= m; i++) dp[i][0] = i;
        for(int j = 0; j <= n; j++) dp[0][j] = j;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                // last is same
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else{
                    // delete word1[i-1] or insert word2[j-1]
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    // or replace word1[i-1] to word2[j-1]
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);

                }
                //cout << "i:" << i << " j:" << j << " " << dp[i][j] << endl;
            }
        }
        
        return dp[m][n];
    }
};

int main(){
    Solution solve;
    //string word1 = "horse";
    //string word2 = "ros";
    //string word1 = "intention";
    //string word2 = "execution";
    string word1 = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef";
    string word2 = "bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefg";

    cout << "Input: " << endl << word1 << endl << word2 << endl;
    cout << "Output: " << solve.minDistance(word1, word2) << endl;

    return 0;
}
