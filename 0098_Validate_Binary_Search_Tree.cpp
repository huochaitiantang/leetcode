#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool rr(TreeNode* root, TreeNode* min_parent, TreeNode* max_parent){
        if(root == NULL) return true;
        if((min_parent != NULL) && (root->val <= min_parent->val)) return false;
        if((max_parent != NULL) && (root->val >= max_parent->val)) return false;
        return rr(root->left, min_parent, root) && rr(root->right, root, max_parent);
    }
    
    bool isValidBST(TreeNode* root) {
        return rr(root, NULL, NULL);
    }
};

int main(){
    Solution solve;
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(4);
    TreeNode* t3 = new TreeNode(5, t1, t2);
    std::cout << solve.isValidBST(t3) << std::endl;
    return 0;
}
