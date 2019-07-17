#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n == 2 || n == 3) return {};
        if(n == 1)return {{"Q"}};
        
        vector<vector<string> > output;
        //vector<bool> row(n, false);
        vector<bool> col(n, false);
        vector<bool> llean(2 * n - 1, false);
        vector<bool> rlean(2 * n - 1, false);
        vector<int> stack(n, 0); 
        
        // begin with 0,0
        int i = 0, j, k, lind, rind;
        while(true){
            // try to find a solution
            while(i < n){
                for(j = 0; j < n; j++){
                    lind = i + j;
                    rind = n - 1 + i - j;
                    if((!col[j]) && (!llean[lind]) && (!rlean[rind])){
                        stack[i] = j;
                        col[j] = llean[lind] = rlean[rind] = true;
                        i++;
                        break;
                    }
                }
                // can not forward continue
                if(j >= n) break;
            }

            for(k = 0; k < i; k++) cout << stack[k] << " ";
            cout << endl;

            // find a solution
            if(i == n){
                vector<string> ans;
                for(k = 0; k < n; k++){
                    string s(n, '.');
                    s[stack[k]] = 'Q';
                    ans.push_back(s);
                }
                output.push_back(ans);

                // delete the last one
                i--;
                j = stack[i];
                lind = i + j;
                rind = n - 1 + i - j;
                col[j] = llean[lind] = rlean[rind] = false;
            }

            // backtrace
            i--;
            while(true){
                // find the row which can add continue
                while((i >= 0) && (stack[i] >= n - 1)){
                    j = stack[i];
                    lind = i + j;
                    rind = n - 1 + i - j;
                    col[j] = llean[lind] = rlean[rind] = false;
                    i--;
                }
                if(i < 0) break;
                // reset i row
                j = stack[i];
                lind = i + j;
                rind = n - 1 + i - j;
                col[j] = llean[lind] = rlean[rind] = false;
                // find next avaiable
                for(j = stack[i] + 1; j < n; j++){
                    lind = i + j;
                    rind = n - 1 + i - j;
                    if((!col[j]) && (!llean[lind]) && (!rlean[rind])){
                        stack[i] = j;
                        col[j] = llean[lind] = rlean[rind] = true;
                        i++;
                        break;
                    }
                }
                if(j < n) break;
                i--;
            }
            if(i <= 0) break;
        }
        return output;
    }
};

int main(){
    Solution solve;
    int n = 4;

    cout << "Input: " << n << endl;

    vector<vector<string> > output = solve.solveNQueens(n);

    cout << "Output:" << endl;
    for(int i = 0; i < output.size(); i++){
        cout << "Ans: " << i + 1 << endl;
        for(int j = 0; j < output[i].size(); j++)
            cout << output[i][j] << endl;
        cout << endl;
    }

    return 0;
}
