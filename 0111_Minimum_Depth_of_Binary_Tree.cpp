#include "common.hpp"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if(l <= 0) return r + 1;
        if(r <= 0) return l + 1;
        return min(l, r) + 1;
    }
};

int main(){
    Solution solve;
    vector<int> v = {3,9,20,0,0,15,7};
    //vector<int> v = {1, 2};
    TreeNode* t = construct_tree(v);
    print_tree(t, v.size());
    std::cout << solve.minDepth(t) << std::endl;
    return 0;
}
