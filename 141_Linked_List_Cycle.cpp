#include "common.hpp"
#include <unordered_set>

class Solution {
public:
    bool hasCycle1(ListNode *head) {
        unordered_set<ListNode*> nodes;
        ListNode* p = head;
        while(p){
            if(nodes.find(p) != nodes.end())
                return true;
            nodes.insert(p);
            p = p->next;
        }
        return false;
    }
    
    // fast and slow pointer
    bool hasCycle(ListNode *head) {
        if((head == NULL) || (head->next == NULL))
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        // if encounter, exist cycle
        while(slow != fast){
            if((fast->next == NULL) || (fast->next->next == NULL))
                return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};

int main(){
    Solution solve;
    vector<int> xs = {3, 2, 0, -4};
    ListNode* head = construct_list(xs);
    print_list(head); 
    cout << solve.hasCycle(head) << endl;
    head->next->next->next->next = head->next;
    cout << solve.hasCycle(head) << endl; 
    return 0;
}
