#include "common.hpp"

class Solution {
public:
    TreeNode* rr(ListNode* head, int high){
        if(!head || high < 0) return NULL;
        if(high == 0) return new TreeNode(head->val);
        ListNode* p = head;
        int i = 0, mid = high / 2;
        while(p && i < mid){
            p = p->next;
            i++;
        }
        TreeNode* root = new TreeNode(p->val);
        root->left = rr(head, mid - 1);
        root->right = rr(p->next, high - mid - 1);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p){
            len++;
            p = p->next;
        }
        return rr(head, len - 1);     
    }
};

int main(){
    Solution solve;
    vector<int> v = {-10, -3, 0, 5, 9};
    ListNode* l = construct_list(v);
    print_list(l);
    TreeNode* t = solve.sortedListToBST(l);
    print_tree(t, v.size());
    return 0;
}
