#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() <= 0) return 0;

        // find the first >= target
        int low = 0, mid, high = nums.size() - 1;
        while(low < high){
            mid = (low + high) / 2;
            if(nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        if(nums[low] < target) low++;
        return low;
    }
};

int main(){
    Solution solve;
    vector<int> input = {1, 3, 5, 7, 9, 11};
    int target = 7;

    cout << "Input: target=" << target << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    cout << "Output: " << solve.searchInsert(input, target) << endl;

    return 0;
}
