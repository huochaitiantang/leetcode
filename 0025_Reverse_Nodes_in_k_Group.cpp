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
         ListNode* reverseKGroup(ListNode* head, int k){
            int i;
            ListNode* p = head;
            ListNode* q;
            ListNode* r;
            vector<ListNode*> k_nodes;
            
            // size of listnode < k;
            for(i = 0; (i < k) && (p != NULL); i++, p = p->next)
                k_nodes.push_back(p);
            if((k <= 1) || (i < k)) return head;

            // new head
            ListNode* output = k_nodes.back();
            while(true){
                p = k_nodes.back()->next;
                q = k_nodes[0];

                // reverse for nodes 1 to k-1, 1->2->3 to 3->2<->1
                for(i = k - 1; i > 0; i--)
                    k_nodes[i]->next = k_nodes[i - 1];
                
                // update k_nodes
                for(i = 0, r = p; (i < k) && (r != NULL); i++, r = r ->next)
                    k_nodes[i] = r;
                
                // end when size of k_nodes < k
                if(i < k){
                    q->next = p;
                    break;
                }
                //                                     4->5->6
                // reverse for nodes 0, 3->2<->1 to 3->2->1->6
                q->next = k_nodes.back();
            }
            return output;
         }
};

int main(){
    Solution solve;

    vector<int> v = {1, 2, 3, 4, 5, 6};
    ListNode* input = construct(v);
    int k = 4;

    cout << "Input:" << endl;
    print_list(input);
    
    ListNode* output = solve.reverseKGroup(input, k);
    
    cout << "Output:" << endl;
    print_list(output);

    return 0;
}
