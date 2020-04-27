#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* construct(vector<int> input){
    if(input.size() == 0) return NULL;
    TreeNode* head = new TreeNode(input[0]);
    queue<TreeNode*> que;
    que.push(head);
    int n = input.size();
    for(int i = 1; i < n; i = i + 2){
        TreeNode* p = que.front();
        p->left = new TreeNode(input[i]);
        que.push(p->left);
        if(i + 1 < n){
            p->right = new TreeNode(input[i + 1]);
            que.push(p->right);
        }
        que.pop();  
    }
    return head;
}

class Solution {
public:
    void collect(TreeNode* root, vector<int>& res){
        if(!root) return;
        collect(root->left, res);
        res.push_back(root->val);
        collect(root->right, res);
    }
    // recursive solution
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> res;
        collect(root, res);
        return res;
    }
    // no recursive solution
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        if(!root) return res;
        TreeNode* p = root;
        TreeNode* q;
        while(p){
            s.push(p);
            p = p->left;
        }
        while(!s.empty()){
            p = s.top();
            res.push_back(p->val);
            s.pop();
            if(p->right){
                q = p->right;
                while(q){
                    s.push(q);
                    q = q->left;
                }
            }    
        }
        return res;
    }
}; 

int main(){
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};
    TreeNode* head = construct(input);
    Solution solve;
    vector<int> res = solve.inorderTraversal(head);
    for(int i = 0; i < res.size(); i++) std::cout << res[i] << " ";
    return 0;
}

