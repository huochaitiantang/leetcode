#include "common.hpp"
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> book;
        for(int i = 0; i < nums.size(); i++){
            book.insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(book.count(nums[i] - 1)) continue;
            int cur = 1;
            int val = nums[i];
            while(book.count(++val)){
                cur++;
            }
            if(cur > ans) ans = cur;
        }
        return ans;
    }
};

int main(){
    Solution solve;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << solve.longestConsecutive(nums) << endl;
    return 0;
}
