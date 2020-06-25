#include<vector>
#include<iostream>
#include<string>
#include<math.h>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
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

int max_depth(TreeNode* root){
    if(root == NULL) return 0;
    return max(max_depth(root->left), max_depth(root->right)) + 1;
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
    int max_level = max_depth(root) - 1;
    if(max_level < 0) return;
    int max_width = (int)pow(2, max_level + 2) - 1;
    vector<string> ss(max_level * 2 + 1, string(max_width + 1, ' '));
    draw_subtree(root, ss, 0, 0, max_width, 0);
    for(int i = 0; i < ss.size(); i++)
        std::cout << ss[i] << std::endl;
    return;
}

ListNode* construct_list(vector<int> input){
    ListNode * head = new ListNode(input[0]);
    ListNode * p = head;
    for(int i = 1; i < input.size(); i++){
       ListNode * cur = new ListNode(input[i]);
       p->next = cur;
       p = cur;
    }
    return head;
}

void print_list(ListNode * head){
    ListNode * p = head;
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

// construct a node by vector
Node* construct_node(vector<int>& xs){
    if(xs.size() <= 0) return NULL;
    queue<Node*> qs;
    Node* head = new Node(xs[0]);
    qs.push(head);
    int index = 1;
    while(index < xs.size()){
        Node* cur = qs.front();
        // left node
        if(xs[index] != NULL){
            cur->left = new Node(xs[index]);
            qs.push(cur->left);
        }
        // right node
        if(index + 1 < xs.size()){
            index++;
            if(xs[index] != NULL){
                cur->right = new Node(xs[index]);
                qs.push(cur->right);
            }
        }
        index++;
        qs.pop();
    }
    return head;
}

// traversal a node level by level
vector<int> iter_node_by_level(Node* root){
    queue<Node*> qs;
    vector<int> res;
    qs.push(root);
    while(!qs.empty()){
        Node* node = qs.front();
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

int max_depth_for_node(Node* root){
    if(root == NULL) return 0;
    return max(max_depth_for_node(root->left), max_depth_for_node(root->right)) + 1;
}

void draw_subnode(Node* root, vector<string>& ss, int level, int start_id, int end_id, int tag){
    if(root == NULL) return;
    int mid = (start_id + end_id) / 2;
    if(tag != 0){
        int branch_level = level * 2 - 1;
        if(tag == 1) ss[branch_level][mid] = '/';
        else ss[branch_level][mid] = '\\';
    }
    int val_level = level * 2;
    char cs[100];
    if(root->next) sprintf(cs, "%d(%d)", root->val, root->next->val);
    else sprintf(cs, "%d(0)", root->val);
    for(int i = 0; i < strlen(cs); i++) ss[val_level][mid + i] = cs[i];
    draw_subnode(root->left, ss, level + 1, start_id, mid, 1);
    draw_subnode(root->right, ss, level + 1, mid, end_id, 2);
    return;
}

void print_node(Node* root, int size){
    if(root == NULL) return;
    // max_level = 0, 1, 2, ...
    // max width = 1, 3, 7, ...
    int max_level = max_depth_for_node(root) - 1;
    if(max_level < 0) return;
    int max_width = (int)pow(2, max_level + 3) - 1;
    vector<string> ss(max_level * 2 + 1, string(max_width + 1, ' '));
    draw_subnode(root, ss, 0, 0, max_width, 0);
    for(int i = 0; i < ss.size(); i++)
        std::cout << ss[i] << std::endl;
    return;
}
