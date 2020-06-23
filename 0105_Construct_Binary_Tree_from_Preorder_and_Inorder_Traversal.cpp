#include "common.hpp" 

class Solution {
public:
	TreeNode* rr(vector<int>& preorder, vector<int>& inorder, int pre_low, int pre_high, int in_low, int in_high){
		if(pre_low > pre_high || in_low > in_high) return NULL;
		int target = preorder[pre_low];
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
		//assert(k >= in_low && k <= in_high);
	    root->left = rr(preorder, inorder, pre_low + 1, pre_low + cnt_left, in_low, k - 1);
	    root->right = rr(preorder, inorder, pre_low + cnt_left + 1, pre_high, k + 1, in_high);
		return root;
	}
	
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rr(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size());
    }
};

int main(){
	Solution solve;
	vector<int> v1 = {3, 9, 20, 15, 7};
	vector<int> v2 = {9, 3, 15, 20, 7};
	TreeNode* t = solve.buildTree(v1, v2);
	print_tree(t, v1.size());
	return 0;
}
