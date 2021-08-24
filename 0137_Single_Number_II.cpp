#include "common.hpp"
#include<unordered_map>

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> flag;
        for(auto val: nums){
            if(flag.find(val) == flag.end()) flag[val] = 1;
            else flag[val] += 1;
            if (flag[val] == 3) flag.erase(val);
        }
        return flag.begin()->first;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for(auto val: nums){
            one = (one ^ val) & ~two;
            two = (two ^ val) & ~one;
        }
        return one;
    }
};

int main(){
    Solution solve;
    //vector<int> nums = {2, 2, -3, 2, 4, 4, 4};
    vector<int> nums = {0, -1, 0, -1, 0, -1, -99};
    cout << solve.singleNumber(nums) << endl;
    return 0;
}
