#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* construct(vector<int>& xs, int index){
    if(index >= xs.size() || xs[index] == NULL) return NULL;
    TreeNode* node = new TreeNode(xs[index]);
    node->left = construct(xs, index * 2 + 1);
    node->right = construct(xs, index * 2 + 2);
    return node;
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == NULL) && (q == NULL)) return true;
        if((p == NULL) && (q != NULL)) return false;
        if((p != NULL) && (q == NULL)) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(){
    Solution solve;
    vector<int> v1 = {10, 5, 15};
    vector<int> v2 = {10, 5, NULL, NULL, 15}; 
    TreeNode* p = construct(v1, 0);
    TreeNode* q = construct(v2, 0);
    std::cout << solve.isSameTree(p, q) << std::endl;
    return 0;
}
