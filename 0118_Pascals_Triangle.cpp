#include "common.hpp"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows <= 0) return res;
        vector<int> cur = {1};
        res.push_back(cur);
        for(int i = 1; i < numRows; i++){
            vector<int> cur = {1};
            for(int j = 1; j < i; j++){
                cur.push_back(res.back()[j - 1] + res.back()[j]);
            }
            cur.push_back(1);
            res.push_back(cur);
        }
        return res;
    }
};

int main(){
    Solution solve;
    vector<vector<int>> res = solve.generate(5);
    for(auto v : res){
        for(auto val : v) std::cout << val << " ";
        std::cout << std::endl;
    }
    return 0;
}
