#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //#define INT_MIN 0x80000000;
        int output = INT_MIN;
        int i, cur_sum = 0;
        for(i = 0; i < nums.size(); i++){
            cur_sum += nums[i];
            if(cur_sum > output) output = cur_sum;
            if(cur_sum <= 0) cur_sum = 0;
        }
        return output;
    }
};

int main(){
    Solution solve;
    vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    cout << "Output: " << solve.maxSubArray(input) << endl;

    return 0;
}
