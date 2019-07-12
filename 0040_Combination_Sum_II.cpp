#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > output;
        if(candidates.size() <= 0) return output;
        
        int i, j, n, last_not_zero, sum = 0;
        vector<int> vals; // unique vals
        vector<int> ups; // max used count of each unique val
        vector<int> stack;

        // get unique vals and its max cnt
        for(i = 0; i < candidates.size(); i++){
            for(j = 0; j < vals.size(); j++)
                if(vals[j] == candidates[i]) break;
            if(j >= vals.size()){
                vals.push_back(candidates[i]);
                ups.push_back(1);
                stack.push_back(0);
            }
            else ups[j]++;
        }
        n = vals.size();
        
        while(true){
            //for(i = 0; i < n; i++) cout << stack[i] << " ";
            //cout << endl;

            // forward, last avaiable which is fasle and add <= target
            if(sum < target){
                for(i = n - 1; i >= 0; i--){
                    if((stack[i] >= ups[i]) || (sum + vals[i] > target)){
                        sum -= vals[i] * stack[i];
                        stack[i] = 0;
                    }
                    else{
                        sum += vals[i];
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
            for(i = 0; i < n; i++)
                for(j = 0; j < stack[i]; j++)
                    ans.push_back(vals[i]);
            output.push_back(ans);
            
            // get rid to last not zero and backtrace
            i = last_not_zero;
            sum -= vals[i] * stack[i];
            stack[i] = 0;
            // backtrace util last avaiable
            for(j = i - 1; j >= 0; j--){
                if((stack[j] >= ups[j]) || (sum + vals[j] > target)){
                    sum -= vals[j] * stack[j];
                    stack[j] = 0;
                }
                else{
                    sum += vals[j];
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
    //vector<int> input = {2, 3, 6, 7};
    //vector<int> input = {24,29,38,22,36,48,31,33,37,42,40,20,26,39,27,35,45,34,21,47,23,44,49,43,25,28,41,30,46};
    //int target = 68;

    vector<int> input = {10,1,2,7,6,1,5};
    int target = 8;

    cout << "Input: target=" << target << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    vector<vector<int> > output = solve.combinationSum2(input, target);
    
    cout << "Output:" << endl;
    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j <output[i].size(); j++)
            cout << output[i][j] << " ";
        cout << endl;
    }

    return 0;
}
