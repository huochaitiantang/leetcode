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
         ListNode* swapPairs(ListNode* head) {
            if(head == NULL) return NULL;
            if(head->next == NULL) return head;

            ListNode* output = head->next;
            ListNode* p1 = head;
            ListNode* p2 = output;
            ListNode* tmp;
            
            /* for 1->2->3->4
               iter 1: p1=1, p2=2, tmp=3, 2->1->4 && 3->4
               iter 2: p1=3, p2=4, tmp=NULL, 2->1->4->3
               for 1->2->3->4->5
               iter 1: p1=1, p2=2, tmp=3, 2->1->4 && 3->4
               iter 2: p1=3, p2=4, tmp=5, tmp->next=NULL, 2->1->4->3->5
            */
            while(true){
                tmp = p2->next;
                // size % 2 == 0, size % 2 == 1
                if((tmp == NULL) || (tmp->next == NULL)){
                    p2->next = p1;
                    p1->next = tmp;
                    break;
                }
                p1->next = tmp->next;
                p2->next = p1;
                p2 = p1->next;
                p1 = tmp;
            }
            return output;
         }
};

int main(){
    Solution solve;

    vector<int> v = {1, 2, 3, 4, 5, 6};
    ListNode* input = construct(v);

    cout << "Input:" << endl;
    print_list(input);
    
    ListNode* output = solve.swapPairs(input);
    
    cout << "Output:" << endl;
    print_list(output);

    return 0;
}
