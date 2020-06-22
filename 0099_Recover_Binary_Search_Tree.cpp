#include "common.hpp"
#include<unordered_map>

class Solution {
public:
    TreeNode* pre_node = NULL;
    TreeNode* p = NULL;
    TreeNode* q = NULL;
    
    void rr(TreeNode* root){
        if(root == NULL) return;
        rr(root->left);
        if(pre_node != NULL && pre_node->val >= root->val){
            if(p == NULL){
                p = pre_node;
                q = root;
            }
            else{
                q = root;
            }
        }
        pre_node = root;
        rr(root->right);
        return;
    }
    
    void swap_val(TreeNode* p, TreeNode* q){
        int tmp = q->val;
        q->val = p->val;
        p->val = tmp;
        return;
    }
    
    void recoverTree(TreeNode* root) {
        rr(root);
        swap_val(p, q);
    }
};

int main(){
    Solution solve;
    vector<int> v = {1, 3, 0, 0, 2};
    //vector<int> v = {3, 1, 4, 0, 0, 2};
    //vector<int> v = {2, 3, 1};
    //vector<int> v= {3, 0, 2, 0, 1};
    //vector<int> v = {1, 2, 3, 4, 5, 6, 7}; 
    TreeNode* t = construct_tree(v);
    print_tree(t, v.size());
    solve.recoverTree(t);
    print_tree(t, v.size());
    return 0;
}
