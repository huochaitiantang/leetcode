# include "common.hpp"

class Solution {
public:
    void rr(TreeNode* root, int cur_val, vector<int>& res){
        int new_val = cur_val * 10 + root->val;
        // leaf node
        if(!root->left && !root->right){
            res[0] = res[0] + new_val;
            return;
        }
        if(root->left){
            rr(root->left, new_val, res);
        }
        if(root->right){
            rr(root->right, new_val, res);    
        }
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<int> res(1, 0);
        rr(root, 0, res);
        return res[0];
    }
};

int main(){
    Solution solve;
    //vector<int> v = {1,2,3};
    vector<int> v = {4,9,1,5,1};
    TreeNode* root = construct_tree(v);
    print_tree(root, 0);
    std::cout << solve.sumNumbers(root) << std::endl;
    return 0;
} 
