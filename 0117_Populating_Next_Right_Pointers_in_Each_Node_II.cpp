#include "common.hpp"

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> qs;
        if(root == NULL) return NULL;
        qs.push(root);
        while(!qs.empty()){
            int size = qs.size();
            Node* pre = qs.front();
            if(pre->left) qs.push(pre->left);
            if(pre->right) qs.push(pre->right);
            qs.pop();
            for(int i = 1; i < size; i++){
                Node* cur = qs.front();
                pre->next = cur;
                if(cur->left) qs.push(cur->left);
                if(cur->right) qs.push(cur->right);
                qs.pop();
                pre = cur;
            } 
        }
        return root;
    }
};

int main(){
    Solution solve;
    vector<int> v = {1,2,3,4,5,0,7};
    Node* root = construct_node(v);
    print_node(root, 0);
    Node* t = solve.connect(root);    
    print_node(t, 0);
    return 0;
}
