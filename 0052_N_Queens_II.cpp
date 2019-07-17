#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if(n == 2 || n == 3) return 0;
        if(n == 1)return 1;

        int output = 0;
        vector<bool> col(n, false);
        vector<bool> llean(2 * n - 1, false);
        vector<bool> rlean(2 * n - 1, false);
        vector<int> stack(n, 0); 

        // begin with 0,0
        int i = 0, j = 0;
        while(true){
            //cout << "i=" << i << " j=" << j << endl;
            // find a solution, backtrace
            if(i == n){
                output++;
                i--;
                col[stack[i]] = llean[i + stack[i]] = rlean[n - 1 + i - stack[i]] = false;
                i--;
                col[stack[i]] = llean[i + stack[i]] = rlean[n - 1 + i - stack[i]] = false;
                j = stack[i] + 1;
                continue;
            }
            // backtrace if j >= n
            if(j == n){
                i--;
                if(i < 0) break;
                col[stack[i]] = llean[i + stack[i]] = rlean[n - 1 + i - stack[i]] = false;
                j = stack[i] + 1;
                continue;
            }
            // forward
            if((!col[j]) && (!llean[i + j]) && (!rlean[n - 1 + i - j])){
                col[j] = llean[i + j] = rlean[n - 1 + i - j] = true;
                stack[i++] = j;
                j = 0;
                continue;
            }
            else j++;
        }
        return output;
    }
};

int main(){
    Solution solve;
    int n = 9;

    cout << "Input: " << n << endl;
    cout << "Output:" << solve.totalNQueens(n) << endl;

    return 0;
}
