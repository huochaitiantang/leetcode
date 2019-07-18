#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, cur = 0, next = 0, n = nums.size();
        if(n <= 1) return true;
        for(i = 0; i < n; i++){
            if(cur < i){
                cur = next;
                if(cur < i) return false;
            }
            next = max(next, nums[i] + i);
            if(next >= n - 1) return true;
        }
        return false;
    }
};

int main(){
    Solution solve;
    //vector<int> input = {2,3,1,1,4};
    //vector<int> input = {3,2,1,0,4};
    vector<int> input = {0,4};

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    cout << "Output: " << solve.canJump(input) << endl;

    return 0;
}
