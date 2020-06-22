#include "common.hpp"
#include<algorithm>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> qs;
        if(root) qs.push(root);
        bool order = true;
        while(!qs.empty()){
            vector<int> cur;
            int cnt = qs.size();
            for(int i = 0; i < cnt; i++){
                TreeNode* node = qs.front();
                cur.push_back(node->val);
                qs.pop();
                if(node->left) qs.push(node->left);
                if(node->right) qs.push(node->right);
            }
            if(!order) reverse(cur.begin(), cur.end());
            order = !order;
            res.push_back(cur);
        }
        return res;
    }
};

int main(){
    Solution solve;
    vector<int> v = {3, 9, 20, 0, 0, 15, 7};
    TreeNode* t = construct_tree(v);
    print_tree(t, v.size());
    vector<vector<int>> res = solve.zigzagLevelOrder(t);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
