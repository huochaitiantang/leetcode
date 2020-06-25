#include "common.hpp"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre;
        vector<int> cur;
        if(rowIndex < 0) return pre;
        pre.push_back(1);
        
        for(int i = 1; i <= rowIndex; i++){
            cur.clear(); 
            cur.push_back(1);
            for(int j = 1; j < i; j++){
                cur.push_back(pre[j - 1] + pre[j]);
            }
            cur.push_back(1);
            pre = cur;
        }
        return pre;
    }
};

int main(){
    Solution solve;
    vector<int> res = solve.getRow(3);
    for(auto val : res) std::cout << val << " ";
    std::cout << std::endl;
    return 0;
}
