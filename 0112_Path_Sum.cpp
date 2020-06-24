#include "common.hpp"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(sum == root->val && root->left == NULL && root->right == NULL) return true;   
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};


int main(){
    Solution solve;
    int sum = -1;
    //vector<int> v = {5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 0, 1};
    //vector<int> v = {1, 2};
    //vector<int> v = {-2, 0, -3}; 
    vector<int> v = {1, -2, -3, 1, 3, -2 , 0, -1};
    TreeNode* t = construct_tree(v);
    print_tree(t, v.size());
    std::cout << solve.hasPathSum(t, sum) << std::endl;
    return 0;
}
