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
         ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

            int cur_sum = l1->val + l2->val;
            int flag = cur_sum / 10;
            ListNode* head = new ListNode(cur_sum % 10);

            ListNode* p = head;
            ListNode* q = l1->next;
            ListNode* r = l2->next;

            while((q != NULL) && (r != NULL)){
                cur_sum = flag + q->val + r->val;
                flag = cur_sum / 10;
                ListNode * cur = new ListNode(cur_sum % 10);
                p->next = cur;
                p = p->next;
                q = q->next;
                r = r->next;
            }
            while(q != NULL){
                cur_sum = flag + q->val;
                flag = cur_sum / 10;
                ListNode * cur = new ListNode(cur_sum % 10);
                p->next = cur;
                p = p->next;
                q = q->next;
            }
            while(r != NULL){
                cur_sum = flag + r->val;
                flag = cur_sum / 10;
                ListNode * cur = new ListNode(cur_sum % 10);
                p->next = cur;
                p = p->next;
                r = r->next;
            }
            if(flag > 0){
                ListNode * cur = new ListNode(flag);
                p->next = cur;
            }
            return head;
         }
};

int main(){
    Solution solve;

    vector<int> v1 = {5, 4, 6, 9, 9};
    vector<int> v2 = {5, 6, 4};
    ListNode* l1 = construct(v1);
    ListNode* l2 = construct(v2);

    cout << "Input:" << endl;
    print_list(l1);
    print_list(l2);
    
    ListNode* output = solve.addTwoNumbers(l1, l2);
    
    cout << "Output:" << endl;
    print_list(output);

    return 0;
}
