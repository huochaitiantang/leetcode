#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


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
        ListNode* removeNthFromEnd(ListNode* head, int n) {         
            ListNode * p = head;
            vector<ListNode*> circle;
            int csize = 0;
            int chead = 0;
            
            // circle queue for pointer, max_size = n + 1
            if(n <= 0) return head;
            while(p != NULL){
                if(csize < n + 1){
                    circle.push_back(p);
                    csize++;
                }
                else if(csize == n + 1){
                    circle[chead] = p;
                    chead = (chead + 1) % (n + 1);
                }
                p = p->next;
            }
            // submit if free error: AddressSanitizer: alloc-dealloc-mismatch
            if(csize == n){
                head = circle[0]->next;
                free(circle[0]);
            }
            if(csize == n + 1){
                int ind = (chead + 1) % (n + 1);
                circle[chead]->next = circle[ind]->next;
                free(circle[ind]);
            }
            return head;
        }
};


int main (){
    Solution solve;
    vector<int> inputs = {1, 2, 3, 4, 5};
    vector<vector<int> > outputs;
    ListNode * head = new ListNode(inputs[0]);
    ListNode * p = head;

    for(int i = 1; i < inputs.size(); i++){
       ListNode * cur = new ListNode(inputs[i]);
       p->next = cur;
       p = cur;
    }

    cout << "Inputs: " << endl;
    print_list(head);

    p = solve.removeNthFromEnd(head, 2);
    
    cout << "Outputs: " << endl;
    print_list(p);

    return 0;

}
