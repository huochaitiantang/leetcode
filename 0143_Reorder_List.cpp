#include "common.hpp"

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> vs;
        ListNode* p = head;        
        while(p){
            vs.push_back(p);
            p = p->next;
        }
        int max_index = vs.size() - 1;
        int reorder_cnt = max_index / 2;
        ListNode* q = NULL;
        ListNode* r = NULL;
        for(int i = 0; i < reorder_cnt; i++){
            p = vs[i];
            q = vs[max_index - i - 1];
            r = q->next;
            r->next = p->next;
            q->next = NULL;
            p->next = r;            
        }
    }
};

int main(){
    Solution solve;
    //vector<int> xs = {1};
    //vector<int> xs = {1, 2};
    //vector<int> xs = {1, 2, 3};
    //vector<int> xs = {1, 2, 3, 4};
    //vector<int> xs = {1, 2, 3, 4, 5};
    //vector<int> xs = {1, 2, 3, 4, 5, 6};
    vector<int> xs = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head = construct_list(xs);
    print_list(head);
    solve.reorderList(head);
    print_list(head);
    return 0;
}
