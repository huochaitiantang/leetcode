#include "common.hpp"
#include<vector>
#include<unordered_set>
#include<algorithm>


class Solution {
public:
    int maximumGap1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int tmp;
        for(int i = 1; i < nums.size(); i++){
            tmp = abs(nums[i] - nums[i - 1]);
            if (tmp > ans) ans = tmp;
        }
        return ans;
    }

    int maximumGap(vector<int>& nums) {
        int maxval = 0;
        int base = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            maxval = max(nums[i], maxval);  
        }
        vector<int> tmp(n);
        // repeat log(maxval)
        while(maxval >= base){
            vector<vector<int>> bucket(10, vector<int>());
            for(int i = 0; i < n; i++){
                int digit = (nums[i] / base) % 10;
                bucket[digit].push_back(i); 
            }
            // fetch from bucket
            int k = 0;
            for(int i = 0; i < 10; i++){
                for(auto x: bucket[i]){
                    tmp[k++] = nums[x];
                }
            }
            // copy
            for(int i = 0; i < n; i++){
                nums[i] = tmp[i];
            }
            base *= 10;
        }
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};

int main(){
    Solution solve;
    //vector<int> nums = {3, 6, 2, 1};
    vector<int> nums = {1, 100000000};
    cout << solve.maximumGap(nums);
    return 0;
}
