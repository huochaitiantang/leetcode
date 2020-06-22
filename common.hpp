#include<vector>
#include<iostream>
#include<string>
#include<math.h>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// construct a tree by vector
TreeNode* construct_tree(vector<int>& xs){
    if(xs.size() <= 0) return NULL;
    queue<TreeNode*> qs;
    TreeNode* head = new TreeNode(xs[0]);
    qs.push(head);
    int index = 1;
    while(index < xs.size()){
        TreeNode* cur = qs.front();
        // left node
        if(xs[index] != NULL){
            cur->left = new TreeNode(xs[index]);
            qs.push(cur->left);
        }
        // right node
        if(index + 1 < xs.size()){
            index++;
            if(xs[index] != NULL){
                cur->right = new TreeNode(xs[index]);
                qs.push(cur->right);
            }
        }
        index++;
        qs.pop();
    }
    return head;
}

// traversal a tree level by level
vector<int> iter_tree_by_level(TreeNode* root){
    queue<TreeNode*> qs;
    vector<int> res;
    qs.push(root);
    while(!qs.empty()){
        TreeNode* node = qs.front();
        if(node == NULL){
            res.push_back(NULL);
        }
        else{
            res.push_back(node->val);
            qs.push(node->left);
            qs.push(node->right);
        }
        qs.pop();        
    }
    return res;
}

void draw_subtree(TreeNode* root, vector<string>& ss, int level, int start_id, int end_id, int tag){
    if(root == NULL) return;
    int mid = (start_id + end_id) / 2;
    if(tag != 0){
        int branch_level = level * 2 - 1;
        if(tag == 1) ss[branch_level][mid] = '/';
        else ss[branch_level][mid] = '\\';
    }
    int val_level = level * 2;
    char cs[100];
    sprintf(cs, "%d", root->val);
    for(int i = 0; i < strlen(cs); i++) ss[val_level][mid + i] = cs[i];
    draw_subtree(root->left, ss, level + 1, start_id, mid, 1);
    draw_subtree(root->right, ss, level + 1, mid, end_id, 2);
    return;
}

void print_tree(TreeNode* root, int size){
    if(root == NULL) return;
    // max_level = 0, 1, 2, ...
    // max width = 1, 3, 7, ...
    int max_level = (int)(log((float)size + 0.5) / log(2.0));
    int max_width = (int)pow(2, max_level + 2) - 1;
    vector<string> ss(max_level * 2 + 1, string(max_width + 1, ' '));
    draw_subtree(root, ss, 0, 0, max_width, 0);
    for(int i = 0; i < ss.size(); i++)
        std::cout << ss[i] << std::endl;
    return;
}
