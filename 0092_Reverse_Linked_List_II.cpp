#include<iostream>
#include<vector>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* x){
    while(x){
        std::cout << x->val << " ";
        x = x->next;
    }
    std::cout << std::endl;
}

ListNode* construct(vector<int> x){
    if(x.size() <= 0) return NULL;
    ListNode* head = new ListNode(x[0]);
    ListNode* p = head;
    for(int i = 1; i < x.size(); i++){
        p->next = new ListNode(x[i]);
        p = p->next;
    }
    return head;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(n <= 1 || m >= n) return head;
        ListNode* res;
        ListNode* p = NULL; // first point
        ListNode* q;
        ListNode* r1;
        ListNode* r2;
        int i;
        for(i = 1; i < m; i++){
            if(!p){
                p = head;
                res = p;
            }
            else p = p->next;
        }
        q = p ? p->next: head;
        r1 = q;
        r2 = q->next;
        r1->next = NULL;
        for(; i < n; i++){
            ListNode* tmp = r2;
            r2 = r2->next;
            tmp->next = r1;
            r1 = tmp;
        } 
        q->next = r2;
        if(p) p->next = r1;
        else res = r1;
        return res;
    }
};

int main(){
    vector<int> input = {1, 2, 3, 4, 5};
    int m = 2, n = 4;
    ListNode* head = construct(input);
    Solution solve;
    ListNode* res = solve.reverseBetween(head, m, n);
    print_list(res);
    return 0;
}
