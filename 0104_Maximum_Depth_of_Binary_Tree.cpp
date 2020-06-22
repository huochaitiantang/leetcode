#include "common.hpp"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        int res = ld > rd ? ld + 1 : rd + 1;
        return res;
    }
};

int main(){
    Solution solve;
    vector<int> v = {3, 9, 20, 0, 0, 15, 7};
    TreeNode* t = construct_tree(v);
    print_tree(t, v.size());
    std::cout << solve.maxDepth(t) << std::endl;;
    return 0;
}
