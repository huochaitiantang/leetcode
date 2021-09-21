#include "common.hpp"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode* p = head;
        ListNode* q = p->next;
        while(q){
            if(q->val <= head->val){
                p->next = q->next;
                q->next = head;
                head = q;
                q = p->next;   
            }
            else if(q->val >= p->val){
                p = q;
                q = p->next;
            }
            else{
                p->next = q->next; 
                ListNode* r = head;
                while(r != p){
                    if((q->val >= r->val) && (q->val <= r->next->val)) break;
                    r = r->next;
                }
                q->next = r->next;
                r->next = q;
                q = p->next;
            }
        }
        return head;
    }
};


int main(){
    Solution solve;
    //vector<int> xs = {4, 2, 1, 3};
    vector<int> xs = {-1, 5, 3, 4, 0};
    ListNode* head = construct_list(xs);
    print_list(head);
    ListNode* ans = solve.insertionSortList(head);
    print_list(ans);
    return 0;
}
