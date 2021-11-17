#include "common.hpp"
#include<vector>

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = (low + high) / 2;
        while(low < high){
            // 3, 4, 5, 1, 2
            if(nums[mid] > nums[high]) low = mid + 1;
            // 5, 1, 2, 3, 4
            else if(nums[mid] < nums[low]) high = mid;
            // 4, 4, 4, 2, 4
            else if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                low = low + 1;
                high = high - 1;
            }
            // 1, 2, 3, 4, 5
            else high = low;
            mid = (low + high) / 2;
        }
        return nums[mid];
    }
};

int main(){
    Solution solve;
    //vector<int> nums = {3, 4, 5, 1, 2};
    //vector<int> nums = {3, 4, 5, 1};
    //vector<int> nums = {3, 4, 5, 6, 1};
    //vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    //vector<int> nums = {0, 1, 2};
    //vector<int> nums = {7, 3, 4, 5};
    //vector<int> nums = {1}; 
    //vector<int> nums = {7, 1, 3, 4, 5};
    //vector<int> nums = {1, 3, 4, 5};
    //vector<int> nums = {2, 2, 2, 0, 1};
    //vector<int> nums = {2, 2, 2, 0, 1, 2, 2, 2};
    vector<int> nums = {3, 3, 4, 0, 0, 1, 2, 2, 2, 2, 3};
    cout << solve.findMin(nums) << endl;
    return 0;
}
