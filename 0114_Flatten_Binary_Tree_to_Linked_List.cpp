#include "common.hpp"

class Solution {
public:
    // return the first node and last node after flatten
    vector<TreeNode*> rr(TreeNode* root){
        vector<TreeNode*> res;
        if(root == NULL) return res;
        res.push_back(root);
        if(root->left == NULL && root->right == NULL){
            res.push_back(root);
            return res;
        }
        vector<TreeNode*> ls = rr(root->left);
        vector<TreeNode*> rs = rr(root->right);
        if(root->left == NULL){
            root->right = rs[0];
            res.push_back(rs[1]);
            return res;
        }
        if(root->right == NULL){
            root->left = NULL;
            root->right = ls[0];
            res.push_back(ls[1]);
            return res;
        }
        root->left = NULL;
        root->right = ls[0];
        ls[1]->left = NULL;
        ls[1]->right = rs[0];
        res.push_back(rs[1]);
        return res;
    }
    
    void flatten(TreeNode* root) {
        vector<TreeNode*> ts = rr(root);
    }
};

int main(){
    Solution solve;
    vector<int> v = {1, 2, 5, 3, 4, 0, 6};
    TreeNode* t = construct_tree(v);
    print_tree(t, v.size());
    solve.flatten(t);
    vector<int> w = iter_tree_by_level(t);
    print_tree(t, w.size());
    return 0;
} 
