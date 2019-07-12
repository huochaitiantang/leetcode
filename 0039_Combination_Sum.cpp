#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i, j, last_not_zero, sum = 0, n = candidates.size();
        vector<vector<int> > output;        
        if(n <= 0) return output;
        vector<int> stack(n, 0);
        
        while(true){
            if(sum < target){
                // forward, last avaible +1
                for(i = n - 1; i >= 0; i--){
                    if(sum + candidates[i] > target){
                        sum -= candidates[i] * stack[i];
                        stack[i] = 0;
                    }
                    else{
                        sum += candidates[i];
                        stack[i]++;
                        last_not_zero = i;
                        break;
                    }
                }
                if(i < 0) break;
                continue;
            }

            // satisfied, sum == target
            vector<int> ans;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < stack[i]; j++)
                    ans.push_back(candidates[i]);
            output.push_back(ans);

            // get rid to last not zero and backtrace
            i = last_not_zero;
            sum -= candidates[i] * stack[i];
            stack[i] = 0;
            // backtrace last avaiable
            for(j = i - 1; j >= 0; j--){
                if(sum + candidates[j] > target){
                    sum -= candidates[j] * stack[j];
                    stack[j] = 0;
                }
                else{
                    sum += candidates[j];
                    stack[j]++;
                    last_not_zero = j;
                    break;
                }
            }
            if(j < 0) break;
        }
        return output;
    }
};

int main(){
    Solution solve;
    vector<int> input = {2, 3, 6, 7};
    int target = 5;

    cout << "Input: target=" << target << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    vector<vector<int> > output = solve.combinationSum(input, target);
    
    cout << "Output:" << endl;
    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j <output[i].size(); j++)
            cout << output[i][j] << " ";
        cout << endl;
    }

    return 0;
}
