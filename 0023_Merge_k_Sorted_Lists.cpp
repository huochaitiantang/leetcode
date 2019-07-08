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
        
        // second: merge 2 lists each time by divide, cost 24ms
        ListNode* mergeKLists(vector<ListNode*>& lists){
            ListNode* output = NULL;
            ListNode* p;
            if(lists.size() <= 0) return NULL;
            while(true){
                int size = lists.size(); 
                if(size == 1) break;

                for(int i = 0; i < size / 2; i++){
                    lists[i] = mergeTwoLists(lists[i], lists[size - i - 1]);
                    lists.pop_back();
                }
            }
            return lists[0];
        }

        // first: merge by compare head of each list, cost 396ms
        ListNode* mergeKLists2(vector<ListNode*>& lists) {
            ListNode* output = NULL;
            ListNode* p;
            
            while(true){
                int min_val, min_ind = -1;
                for(int i = 0; i < lists.size(); i++){
                    if((lists[i] != NULL) && 
                       ((min_ind < 0) || 
                        (min_val > lists[i]->val))){
                        min_ind = i;
                        min_val = lists[i]->val;
                    }
                }
                if(min_ind < 0) break;
                if(output == NULL){
                    output = lists[min_ind];
                    p = output;
                }
                else{
                    p->next = lists[min_ind];
                    p = p->next;
                }
                lists[min_ind] = lists[min_ind]->next;
            }
            return output;
    }
};

int main(){
    Solution solve;

    vector<int> v1 = {1,4,5};
    vector<int> v2 = {1,3,4};
    vector<int> v3 = {2,6};

    ListNode* l1 = construct(v1);
    ListNode* l2 = construct(v2);
    ListNode* l3 = construct(v3);
    vector<ListNode*> input = {l1, l2, l3};

    cout << "Input:" << endl;
    print_list(l1);
    print_list(l2);
    print_list(l3);
    
    ListNode* output = solve.mergeKLists(input);
    
    cout << "Output:" << endl;
    print_list(output);

    return 0;
}
