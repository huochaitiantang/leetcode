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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1 = NULL;
        ListNode* h2 = NULL;
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;
        while(p){
            if(p->val < x){
                if(!q){
                    h1 = p;
                    q = h1;
                }
                else{
                    q->next = p;
                    q = q->next;
                }
                p = p->next;
                q->next = NULL;
                continue;
            }
            else{
                if(!r){
                    h2 = p;
                    r = h2;
                }
                else{
                    r->next = p;
                    r = r->next;
                }
                p = p->next;
                r->next = NULL;
                continue;
            }
        }
        if(q){
            q->next = h2;
            return h1;
        }
        else{
            return h2;
        }
    }
};

int main(){
    vector<int> input = {1, 4, 3, 2, 5, 2}; 
    int x = 3;
    Solution solve;
    ListNode* head = construct(input);
    ListNode* res = solve.partition(head, x);
    print_list(res);
    return 0;
} 
