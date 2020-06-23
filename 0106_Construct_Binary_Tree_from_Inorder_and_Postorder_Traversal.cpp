#include "common.hpp" 

class Solution {
public:
    TreeNode* rr(vector<int>& inorder, vector<int>& postorder, int in_low, int in_high, int post_low, int post_high){
        if(post_low > post_high || in_low > in_high) return NULL;
        int target = postorder[post_high];
        TreeNode* root = new TreeNode(target);
        // find the target in inorder
        int k, cnt_left, cnt_right;
        for(k = in_low; k <= in_high; k++){
            if(inorder[k] == target){
                cnt_left = k - in_low;
                cnt_right = in_high - k;
                break;	
            }
        }
        root->left = rr(inorder, postorder, in_low, k - 1, post_low, post_low + cnt_left - 1);
        root->right = rr(inorder, postorder, k + 1, in_high, post_low + cnt_left, post_high - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return rr(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
};

int main(){
    Solution solve;
    vector<int> v1 = {9, 3, 15, 20, 7};
    vector<int> v2 = {9, 15, 7, 20, 3};
    TreeNode* t = solve.buildTree(v1, v2);
    print_tree(t, v1.size());
    return 0;
}
