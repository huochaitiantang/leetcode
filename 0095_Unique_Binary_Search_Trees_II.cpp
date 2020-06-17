#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* copy_tree(TreeNode* x){
        if(x == NULL) return NULL;
        TreeNode* head = new TreeNode(x->val);
        head->left = copy_tree(x->left);
        head->right = copy_tree(x->right);
        return head;
    }
    
    vector<TreeNode*> dfs(vector<int> xs, int low, int high){
        vector<TreeNode*> res;
        if(low > high){
            res.push_back(NULL);
            return res;
        }
        if(low == high){
            res.push_back(new TreeNode(xs[low]));
            return res;
        }
        for(int i = low; i <= high; i++){
            vector<TreeNode*> lefts  = dfs(xs, low, i - 1);
            vector<TreeNode*> rights = dfs(xs, i + 1, high);
            for(int j = 0; j < lefts.size(); j++){
                for(int k = 0; k < rights.size(); k++){
                    TreeNode* head = new TreeNode(xs[i]);
                    head->left = copy_tree(lefts[j]);
                    head->right = copy_tree(rights[k]);
                    res.push_back(head);       
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n){
        vector<TreeNode*> res;
        vector<int> xs;
        if(n <= 0) return res;
        for(int i = 1; i <= n; i++) xs.push_back(i);
        res = dfs(xs, 0, n - 1);
        return res;
    }
};

int main(){
    Solution solve;
    int n = 3;
    vector<TreeNode*> res;
    res = solve.generateTrees(n);
    return 0;
} 
