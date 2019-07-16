#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // stack: run out of time, 80/92
    int jump1(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        
        int output = -1, n = nums.size();
        vector<vector<int> > stack; // save the index and jump length;
        vector<int> init = {0, min(n - 1, nums[0])};
        stack.push_back(init);

        while(true){
            //cout << "stack: " << stack.size() << endl;
            int next_ind = stack.back()[0] + stack.back()[1];
            // backtrace condition
            if((next_ind == n - 1) || (nums[next_ind] == 0) ||
               ((output > 0) && (stack.size() >= output))){
                // satisfy the condition, update the output
                if(next_ind == n - 1){
                    if((output < 0) || (stack.size() < output))
                        output = stack.size();
                    
                    for(int i = 0; i < stack.size(); i++)
                        cout << stack[i][0] << "(" << stack[i][1] << ")" << " ";
                    cout << endl;
                    cout << "update: " << output << endl;
                }
                if((next_ind == n - 1) || ((output > 0) && (stack.size() >= output))) 
                    stack.pop_back();
                
                // backtrace: find last >= 2, substract one step
                while((stack.size() > 0) && (stack.back()[1] <= 1)) stack.pop_back();
                if(stack.size() <= 0) break;
                stack.back()[1]--;
            }
            // jump forward as the biggest step
            else{
                vector<int> jmp = {next_ind, min(n - 1 - next_ind, nums[next_ind])};
                stack.push_back(jmp);
            }
        }
        return output;
    }

    // dp, 90/92
    int jump2(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        if(nums.size() == 2) return 1;
        int n = nums.size();
        vector<vector<int> > jmp(n, vector<int>(n, 0));
        cout << "size=" << nums.size() << endl;

        for(int j = 1; j < n; j++){
            for(int i = 0; i + j < n; i++){
                cout << "j=" << j << " i=" << i << endl; 
                if(nums[i] >= j) jmp[i][i + j] = 1;
                else if(nums[i] == 0) jmp[i][i + j] = n;
                else{
                    int min_step = n;
                    for(int k = 1; k < j; k++)
                        min_step = min(min_step, jmp[i][i + k] + jmp[i + k][i + j]);
                    jmp[i][i + j] = min_step;
                }
            }
        }
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)  cout << jmp[i][j] << " ";
            cout << endl;
        }

        return jmp[0][n - 1];
    }

    // dp2, 91/92
    int jump3(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        if(nums.size() == 2) return 1;
        int n = nums.size();
        vector<int> jmp(n, n);
        jmp[0] = 0;
        jmp[1] = 1;
        for(int i = 2; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] >= i - j){
                    jmp[i] = min(jmp[i], jmp[j] + 1);
                }
            }
        }
        return jmp[n - 1];
    }

    // greedy
    int jump(vector<int>& nums) {
        int output = 0, next = 0, cur = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cur < i){
                // could reach here at the minimum jump
                cur = next;
                output++;
            }
            next = max(nums[i] + i, next);
        }
        return output;
    }



};

int main(){
    Solution solve;
    
    //vector<int> input = {1};
    //vector<int> input = {2,3,1,1,4};
    //vector<int> input = {2,1};
    //vector<int> input = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    vector<int> input = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    //vector<int> input(25000, 1);

    cout << "Input:" << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    cout << "Output: " << solve.jump(input) << endl;

    return 0;
}
