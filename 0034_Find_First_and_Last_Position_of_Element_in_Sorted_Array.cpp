#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low, mid, high;
        vector<int> output = {-1, -1};
        // find the target, ignore order
        low = 0; 
        high = nums.size() - 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else break;
        }
        if(low <= high){
            int base_ind = mid;
            cout << "find index: " << mid << endl;
            // first appearance
            low = 0;
            high = base_ind;
            while(low < high){
                mid = (low + high) / 2;
                if(nums[mid] == target) high = mid;
                else low = mid + 1;
            }
            cout << "first:" << high << endl;
            output[0] = high;
            // last appearance
            low = base_ind;
            high = nums.size() - 1;
            while(low < high){
                mid = (low + high) / 2;
                if(nums[mid] == target){
                    low = mid;
                    // low = mid = high = target
                    if(nums[high] > target) high--;
                    else low++;
                }
                else high = mid - 1;
            }
            cout << "second: " << low << endl;
            output[1] = low;
        }
        else
            cout << "not find" << endl;
        return output;
    }
};

int main(){
    Solution solve;
    vector<int> input = {5, 7, 7, 7, 7, 7, 8, 8, 10};
    int target = 8;

    cout << "Input: target=" << target << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    vector<int> output = solve.searchRange(input, target);

    cout << "Output:" << endl;
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    cout << endl;

    return 0;
}
