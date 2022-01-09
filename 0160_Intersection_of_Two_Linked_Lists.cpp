#include "common.hpp"
#include<vector>
#include<unordered_set>

class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> maps;
        ListNode* p = headA;
        while(p){
            maps.insert(p);
            p = p->next; 
        }
        p = headB;
        while(p){
            if(maps.find(p) != maps.end()){
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        while(p != q){
            p = p == NULL ? headB : p->next;
            q = q == NULL ? headA : q->next; 
        }
        return p;
    }
};

int main(){
    ListNode* p = construct_list({8, 4, 5});
    ListNode* q = construct_list({4, 1}); 
    ListNode* r = construct_list({5, 6, 1});
    q->next->next = p;
    r->next->next->next = p;
    print_list(q);
    print_list(r);
    Solution solve;
    print_list(solve.getIntersectionNode(q, r));
    return 0;
}
