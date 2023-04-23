#include "common.hpp"
#include<unordered_map>

class Solution {
public:
    int majorityElement1(vector<int>& nums) {
        unordered_map<int, int> ms;
        int res;
        int res_count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(ms.find(nums[i]) == ms.end()){
                ms[nums[i]] = 0;
            }
            ms[nums[i]] += 1;
        }
        for(auto it = ms.begin(); it != ms.end(); it++){
            if(it->second > res_count){
                res_count = it->second;
                res = it->first;
            }
        }
        return res;
    }
    
    // Boyer-Moore ͶƱ�㷨 
    int majorityElement(vector<int>& nums) {
        int cand;
        int rest = 0;
        for(int i = 0; i < nums.size(); i++){
            if(rest == 0){
                cand = nums[i];
                rest++;
            }
            else if(nums[i] == cand){
                rest++;
            }
            else{
                rest--;
            }
        }
        return cand;
    }
};

int main(){
    Solution solve;
    vector<int> x = {3, 2, 3};
    // vector<int> x = {2,2,1,1,1,2,2};
    cout << solve.majorityElement(x) << endl;
    return 0;
}
