#include "common.hpp"

class Solution {
public:
    int depth(TreeNode* root){
        if(root == NULL) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int diff = abs(depth(root->left) - depth(root->right));
        if(diff > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main(){
    Solution solve;
    //vector<int> v = {3,9,20,0,0,15,7};
    vector<int> v = {1,2,2,3,3,0,0,4,4};
    TreeNode* t = construct_tree(v);
    print_tree(t, v.size());
    std::cout << solve.isBalanced(t) << std::endl;
    return 0;
}
