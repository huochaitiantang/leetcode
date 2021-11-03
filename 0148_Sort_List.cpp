#include "common.hpp"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        // find the mid node
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        // sort for two parts
        ListNode* half_head = slow->next;
        slow->next = NULL;
        ListNode * p = sortList(head);
        ListNode * q = sortList(half_head);

        // merge two parts
        ListNode * r = NULL;
        ListNode * min = NULL;
        head = NULL;
        while(p && q){
            if(p->val < q->val){
                min = p;
                p = p->next;
            }
            else {
                min = q;
                q = q->next;
            }
            // init head
            if(!head){
                head = min;
                r = head;
            }
            else{
                r->next = min;
                r = r->next; 
            }
        }
        if(p){
            if(!head) head = p;
            else r->next = p;
        }
        if(q){
            if(!head) head = q;
            else r->next = q;
        }
        return head;
    }
};


int main(){
    Solution solve;
    vector<int> xs = {4, 2, 1, 3, 9, 8, 7, 6, 13, 21, 12, 15};
    //vector<int> xs = {-1, 5, 3, 4, 0};
    ListNode* head = construct_list(xs);
    print_list(head);
    ListNode* ans = solve.sortList(head);
    print_list(ans);
    return 0;
}
