#include "common.hpp"

class Solution {
public:
    void rr(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res){
        if(!root) return;
        path.push_back(root->val);
        if(sum == root->val && root->left == NULL && root->right == NULL){
            vector<int> cur;
            cur.assign(path.begin(), path.end());
            res.push_back(cur);
        }
        else{
            rr(root->left, sum - root->val, path, res);
            rr(root->right, sum - root->val, path, res);
        }
        path.pop_back();
        return;
    } 
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        rr(root, sum, path, res);
        return res;
        
    }
};

int main(){
    Solution solve;
    int sum = 22;
    vector<int> v = {5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 5, 1};
    TreeNode* t = construct_tree(v);
    print_tree(t, v.size());
    vector<vector<int>> res = solve.pathSum(t, sum);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
