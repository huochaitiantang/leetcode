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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head;
        ListNode * r;
        ListNode * p = l1;
        ListNode * q = l2;
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(p->val <= q->val){
            head = p;
            p = p->next;
        }
        else{
            head = q;
            q = q->next;
        }
        r = head;

        while((p != NULL) && (q != NULL)){
            if(p->val <= q->val){
                r->next = p;
                p = p->next;
            }
            else{
                r->next = q;
                q = q->next;
            }
            r = r->next;
        }

        if(p == NULL) r->next = q;
        if(q == NULL) r->next = p;

        return head;
    }
};

int main (){
    Solution solve;
    vector<int> input1 = {1, 3, 5, 7};
    vector<int> input2 = {1, 2, 2, 8, 9};
    ListNode * output;

    ListNode * l1 = construct(input1);
    ListNode * l2 = construct(input2);

    cout << "Input: " << endl;
    print_list(l1);
    print_list(l2);

    output = solve.mergeTwoLists(l1, l2);
    
    cout << "Output: " << endl;
    print_list(output);

    return 0;

}


