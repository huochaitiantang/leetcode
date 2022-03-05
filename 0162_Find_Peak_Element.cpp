#include "common.hpp"
#include<vector>
#include<unordered_set>


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[len - 1] > nums[len - 2]) return len - 1;
        
        int low, mid, high;
        low = 1;
        high = len - 2;
        while(low <= high){
            mid = (low + high) / 2;
            if((nums[mid] > nums[mid - 1]) && (nums[mid] > nums[mid + 1])) return mid;
            if((nums[low] > nums[low - 1]) && (nums[low] > nums[low + 1])) return low;
            if((nums[high] > nums[high - 1]) && (nums[high] > nums[high + 1])) return high;
            
            if((nums[low] > nums[low - 1]) && (nums[mid] < nums[low])){
                low++;
                high = mid - 1;
            }
            else if((nums[mid] > nums[mid - 1]) && (nums[high] < nums[mid])){
                low = mid + 1;
                high--; 
            }
            else{
                low++;
                high--;
            }
        }
        return -1;
    }
};

int main(){
    Solution solve;
    // vector<int> nums = {1, 2, 3, 1}; 
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << solve.findPeakElement(nums);
    return 0;
}
