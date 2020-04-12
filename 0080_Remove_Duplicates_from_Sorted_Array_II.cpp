#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, val, cnt, res;
        if(nums.size() <= 0) return 0;
        val = nums[0];
        cnt = 1;
        res = 1;
        for(i = 1; i < nums.size(); i++){
            if(nums[i] == val){
                cnt++;
            }
            else{
                val = nums[i];
                cnt = 1;
            }
            if(cnt <= 2){
                nums[res] = val;
                res++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    //vector<int> nums = {0,0,1,1,1,1,2,3,3};
    Solution solve;
    int res = solve.removeDuplicates(nums);
    std::cout << res << std::endl;
    for(int i = 0; i < res; i++){
        std::cout << nums[i] << " ";
    }
    return 0;
}
 
