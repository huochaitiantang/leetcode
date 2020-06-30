#include "common.hpp" 

class Solution {
public:
    int rr(TreeNode* root, int* res){
        int val = root->val;
        // for parent, only one branch could attach
        int branch_val = INT_MIN;
        if(root->left){
            int left_path = rr(root->left, res);
            if(left_path > 0){
                val += left_path;
                branch_val = left_path > branch_val ? left_path: branch_val;
            }
        }
        if(root->right){
            int right_path = rr(root->right, res);
            if(right_path > 0){
                val += right_path;
                branch_val = right_path > branch_val ? right_path: branch_val;
            }
        }
        if(val > *res) *res = val;
        if(branch_val > 0) return root->val + branch_val;
        else return root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int res = INT_MIN;
        rr(root, &res);
        return res;
    }
};

int main(){
    Solution solve;
    //vector<int> v = {1,2,3};
    //vector<int> v = {-10,9,20,0,0,15,7};
    vector<int> v = {5,4,8,11,0,13,4,7,2,0,0,0,1};
    TreeNode* root = construct_tree(v);
    print_tree(root, 0);
    std::cout << solve.maxPathSum(root) << std::endl;
    return 0;
}
