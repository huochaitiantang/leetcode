#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() <= 0) return -1;
        if((target < nums.front()) && (target > nums.back())) return -1;
        int low, mid, high;
        low = 0;
        high = nums.size() - 1;
        mid = (low + high) / 2;

        // find the pivot index
        while(low < high){
            if(nums[mid] > nums.back()) low = mid + 1;
            else if(nums[mid] < nums.back()) high = mid;
            mid = (low + high) / 2;
        }
        
        // second part
        if(target <= nums.back()){
            low = mid;
            high = nums.size() - 1;
        }
        // first part, target >= nums.front()
        else{
            low = 0;
            high = mid - 1;
        }
        
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else return mid;
        }
        return -1;
    }
};


int main(){
    Solution solve;
    vector<int> input = {5, 1, 3};
    int target = 5;

    cout << "Input: target=" << target << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    cout << "Ouput: " << solve.search(input, target) << endl;

    return 0;
}
