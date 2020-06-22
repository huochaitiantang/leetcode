#include "common.hpp"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> qs;
        queue<int> levels;
        qs.push(root);
        levels.push(0);
        while(!qs.empty()){
            TreeNode* node = qs.front();
            int level = levels.front();
            if(node != NULL){
                while(level >= res.size()){
                    vector<int> cur;
                    res.push_back(cur);
                }
                res[level].push_back(node->val);
                qs.push(node->left);
                qs.push(node->right);
                levels.push(level + 1);
                levels.push(level + 1);
            }
            qs.pop();
            levels.pop();
        }
        return res;
    }
};

int main(){
    Solution solve;
    vector<int> v = {3, 9, 20, 0, 0, 15, 7};
    TreeNode* t = construct_tree(v);
    vector<vector<int>> res = solve.levelOrder(t);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
