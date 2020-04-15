#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == target) return true;
            while((low < mid) && (nums[mid] == nums[low])) low++;
            if(nums[mid] == nums[low]) low = mid + 1;
            else if(nums[mid] > nums[low]){
                if((target <= nums[mid]) && (target >= nums[low])) high = mid - 1;
                else low = mid + 1;
            }
            else{
                if((target >= nums[mid]) && (target <= nums[high])) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false; 
    }
};

int main(){
    vector<int> nums = {2,5,6,0,0,1,2};
    //vector<int> nums = {1};
    //vector<int> nums = {1, 1};
    int target = 9;
    Solution solve;
    std::cout << solve.search(nums, target) << std::endl;
    return 0;
} 
