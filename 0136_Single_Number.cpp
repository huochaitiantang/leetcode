#include "common.hpp"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[0] = nums[0] ^ nums[i];
        }
        return nums[0];
    }
};

int main(){
    Solution solve;
    // vector<int> nums = {2, 2, 1};
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << solve.singleNumber(nums) << endl;
    return 0;
}
