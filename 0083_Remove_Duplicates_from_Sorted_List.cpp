#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* construct(vector<int> input){
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
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        ListNode* q;
        if(p == NULL) return p;
        int cur_val = p->val;
        while(true){
            q = p->next;
            while((q != NULL) && (q->val == cur_val)) q = q->next;
            p->next = q;
            if(q == NULL) break;
            p = q;
            cur_val = q->val;
        }
        return head;
    }
};

int main(){
    vector<int> input = {1,1,2,3,3};
    ListNode* head = construct(input);
    Solution solve;
    solve.deleteDuplicates(head);
    print_list(head);
    return 0;
}
