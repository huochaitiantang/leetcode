#include "common.hpp"

class Solution {
public:
    void visit(TreeNode* root, vector<int>& ans){
        if(root){
            ans.push_back(root->val);
            visit(root->left, ans);
            visit(root->right, ans);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        visit(root, ans);
        return ans;
    }
};

int main(){
    Solution solve;
    vector<int> v = {5,4,8,11,0,13,4,7,2,0,0,0,1};
    TreeNode* root = construct_tree(v);
    print_tree(root, 0);
    vector<int> res = solve.preorderTraversal(root);
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}
