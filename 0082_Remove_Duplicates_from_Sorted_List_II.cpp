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
        ListNode* q = NULL;
        ListNode* res = NULL;
        if(p == NULL || p->next == NULL) return p;
        while(true){
            //print_list(res);
            //std::cout << p->val << std::endl;
            if(p->val != p->next->val){
                if(q == NULL){
                    res = p;
                    q = res;
                }
                else{
                    q->next = p;    
                    q = q->next;
                }
                p = p->next;
                if(p->next == NULL){
                    q->next = p;
                    return res;
                }
            }
            else{
                while(p->val == p->next->val){
                    p = p->next;
                    if(p->next == NULL){
                        if(q != NULL) q->next = NULL;
                        return res;    
                    }
                }
                p = p->next;
                if(p->next == NULL){
                    if(q != NULL) q->next = p;
                    else res = p;
                    return res;
                }
            }
        }
        return res;
    }
};

int main(){
    //vector<int> input = {1,1,2,2,3,3,3,4,5,5,6,7,7,7,8,8,9};
    vector<int> input = {1, 1, 2};
    ListNode* head = construct(input);
    Solution solve;
    ListNode* res = solve.deleteDuplicates(head);
    print_list(res);
    return 0;
}
