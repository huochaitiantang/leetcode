#include<iostream>
#include<vector> 
using namespace std;

class Solution {
public:
    vector<vector<int> > k_subsets(vector<int>& nums, int k){
        vector<vector<int> > res;
        vector<int> stack;
        int n = nums.size();   
        if((k == 0) || (n == 0)){
            vector<int> cur;
            res.push_back(cur);
            return res;
        }
        stack.push_back(0);
        while(true){
            if(stack.size() == k){
                vector<int> cur;
                for(int i = 0; i < k; i++){
                    cur.push_back(nums[stack[i]]);
                }
                res.push_back(cur);
            }
            // backtrace
            if(stack.back() >= n - 1){
                stack.pop_back();
                if(stack.size() <= 0) break;
                stack.back()++;
                continue;
            }
            // forward
            if(stack.size() == k){
                stack.back()++;
            }
            else{
                stack.push_back(stack.back() + 1);
            }
        }
        return res;
    }
    
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        for(int i = 0; i <= nums.size(); i++){
            vector<vector<int> > cur = k_subsets(nums, i);
            for(int k = 0; k < cur.size(); k++){
                res.push_back(cur[k]);
            }
        }  
        return res;
    }
};

int main(){
    vector<int> nums = {1,4,5,6};
    vector<vector<int> > res;
    Solution solve;
    res = solve.subsets(nums);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
