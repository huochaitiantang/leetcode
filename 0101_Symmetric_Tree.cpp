#include "common.hpp"

class Solution {
public:
    bool rr(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        return rr(p->left, q->right) && rr(p->right, q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return rr(root->left, root->right);
    }
};

int main(){
    Solution solve;
    //vector<int> v = {1, 2, 2, 3, 4, 4, 3};
    //vector<int> v = {1, 2, 2, 0, 3, 0, 3};
    vector<int> v = {1, 2, 2, 3, 4, 4, 3, 7, 0, 5, 6, 6, 5, 0, 8};    
    TreeNode* t = construct_tree(v);
    print_tree(t, v.size());
    std::cout << solve.isSymmetric(t) << std::endl;    
    return 0;
}
