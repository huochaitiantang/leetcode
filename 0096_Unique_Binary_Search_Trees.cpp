#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:    
    int numTrees(int n) {
        vector<int> a;
        a.push_back(1);
        a.push_back(1);
        int i = 2;
        while(i <= n){
            int ans = 0;
            for(int j = 0; j < i; j++){
                ans += a[j] * a[i - j - 1];
            }
            a.push_back(ans);
            i++;
        }
        return a.back();
        /*
        vector<vector<int>> a = vector<vector<int>>(n + 1, vector<int>(n + 1, 1));
        for(int i = 1; i < n; i++){
            for(int j = 1; j + i <= n; j++){
                int res = 0;
                for(int k = j; k <= j + i; k++){
                    int v1 = k - 1 < j ? 1 : a [j][k - 1];
                    int v2 = k + 1 > j + i ? 1 : a[k + 1][j + i];
                    res += v1 * v2;
                }
                a[j][j + i] = res;
            }
        }
        return a[1][n];
        */
       
    }
};

int main(){
    Solution solve;
    int n = 3;
    std::cout << solve.numTrees(n) << std::endl;     
    return 0;
} 
