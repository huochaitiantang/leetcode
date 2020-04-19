#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    
    
    vector<vector<int>> subsets_k(vector<int>& unique_nums, unordered_map<int, int>& map, int k){
        vector<vector<int>> res;
        int n = unique_nums.size();
        vector<int> s;
        vector<int> v;
        s.push_back(0);
        v.push_back(map[unique_nums[s.back()]]); 
        int cnt = v.back();
        while(true){
            if(cnt >= k){
                v.back() = v.back() - (cnt - k);
                cnt = k;
                vector<int> cur;
                for(int i = 0; i < s.size(); i++){
                    for(int j = 0; j < v[i]; j++){
                        cur.push_back(unique_nums[s[i]]);
                    }
                }
                res.push_back(cur);
            }
            int ind = s.back();
            int num = v.back();
            // backtrace
            // ind = n - 1, k = cnt
            // ind = n - 1, k > cnt, num >= map[nums[ind]]
            if((ind == n - 1) && ((k <= cnt) || ((k > cnt) && (num >= map[unique_nums[ind]])))){
                cnt -= num;
                s.pop_back();
                v.pop_back();
                if(s.empty()) break;
                if(v.back() > 1){
                    v.back()--;
                    cnt--;
                }
                else{
                    int curind = s.back();
                    s.pop_back();
                    v.pop_back();
                    cnt--;
                    s.push_back(curind + 1);
                    v.push_back(map[unique_nums[s.back()]]);
                    cnt = cnt + v.back();
                }
                continue;
            }
            // forward
            if(cnt == k){
                if(num > 1){
                    v.back()--;
                    cnt--;
                }
                else{
                    s.pop_back();
                    v.pop_back();
                    cnt--;
                    s.push_back(ind + 1);
                    v.push_back(map[unique_nums[s.back()]]);
                    cnt = cnt + v.back();
                }
            }
            else{
                s.push_back(s.back() + 1);
                v.push_back(map[unique_nums[s.back()]]);
                cnt = cnt + map[unique_nums[s.back()]];
            }
        }
        return res;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> unique_nums;
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            if(map.find(nums[i]) != map.end()) map[nums[i]]++;
            else{
                map[nums[i]] = 1;
                unique_nums.push_back(nums[i]);
            }
        }
        res.push_back(vector<int>());
        for(int k = 1; k <= nums.size(); k++){
            vector<vector<int>> cur = subsets_k(unique_nums, map, k);
            res.insert(res.end(), cur.begin(), cur.end());
        }
        return res;
    }
};

int main(){
    Solution solve;
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    //vector<int> nums = {1, 1};
    vector<vector<int>> res = solve.subsetsWithDup(nums);
    for(int i = 0; i  < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            std::cout << res[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
} 
