#include "common.hpp"
#include<unordered_map>

class Solution {
public:
    
    void collect(vector<vector<bool>> &valid, vector<vector<vector<vector<string>>>> &part_ans, int start_idx, int end_idx, string s){
        vector<vector<string>> ans;
        for(int step = 0; start_idx + step <= end_idx; step++){
            //s[start_idx: start+idx + step] + collect(start_idx + step + 1, end_idx)
            if(valid[start_idx][start_idx + step]){
                // cur palindrome string
                string cur_s = s.substr(start_idx, step + 1);
                if(start_idx + step + 1 <= end_idx){
                    vector<vector<string>> sub_ans = part_ans[start_idx + step + 1][end_idx];
                    for(int i = 0; i < sub_ans.size(); i++){
                        vector<string> tmp = {cur_s};
                        for(int j = 0; j < sub_ans[i].size(); j++){
                            tmp.push_back(sub_ans[i][j]);
                        }
                        ans.push_back(tmp);
                    }
                }
                // single string
                else{
                    vector<string> tmp = {cur_s};
                    ans.push_back(tmp);
                }
            }
        }
        part_ans[start_idx][end_idx] = ans;
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        if(n == 0) return vector<vector<string>>();

        // valid[i][j] == true, if s[i:j] is palindrome
        vector<vector<bool>> valid(n, vector<bool>(n, false));
        // partition answer of s[i:j]
        vector<vector<vector<vector<string>>>> part_ans(n, vector<vector<vector<string>>>(n, vector<vector<string>>()));
        for(int i = 0; i < n; i++){
            valid[i][i] = true;
            collect(valid, part_ans, i, i, s);
        }
        for(int i = 0; i + 1 < n; i++){
            if(s[i] == s[i + 1]){
                valid[i][i + 1] = true;
            }
            collect(valid, part_ans, i, i + 1, s);
        }
        for(int step = 2; step < n; step++){
            for(int i = 0; i + step < n; i++){
                if((s[i] == s[i + step]) && valid[i + 1][i + step - 1])
                    valid[i][i + step] = true;
                collect(valid, part_ans, i, i + step, s);
            }
        }        
        return part_ans[0][n - 1];
    }
};


int main(){
    //string s = "aabbcdcefd";
    //string s = "aab";
    //string s = "a";
    string s = "";
    Solution solve;
    vector<vector<string>> res = solve.partition(s);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}
