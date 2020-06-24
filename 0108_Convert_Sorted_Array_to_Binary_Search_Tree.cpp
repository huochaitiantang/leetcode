#include "common.hpp"

class Solution {
public:
    TreeNode* rr(vector<int> nums, int low, int high){
        if(high < low) return NULL;
        int mid = (low + high) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = rr(nums, low, mid - 1);
        root->right = rr(nums, mid + 1, high);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return rr(nums, 0, nums.size() - 1);
    }
};

int main(){
    Solution solve;
    vector<int> v = {-10, -3, 0, 5, 9};
    TreeNode* t = solve.sortedArrayToBST(v);
    print_tree(t, v.size());
    return 0;
}
