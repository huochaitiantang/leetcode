#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* construct(vector<int> input){
    if(input.size() == 0) return NULL;
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
	ListNode* rotateRight(ListNode* head, int k) {
        ListNode* output;
        ListNode* p;
        int i, n;

        // get the length
        for(n = 0, p = head; p != NULL; n++)
            p = p->next;
        if(head == NULL || k % n == 0) return head;
        k = k % n;

        // find the (n-k)th node
        for(p = head, i = 1; i < n - k; i++)
            p = p->next;
        output = p->next;
        p->next = NULL;

        // last node link to the head
        p = output;
        while(p->next != NULL) p = p->next;
        p->next = head;
        return output;	
	}
};

int main(){
    Solution solve;

    //vector<int> v = {1,2,3,4,5};
    vector<int> v = {};
    ListNode* l = construct(v);
    int k = 5;

    cout << "Input:" << endl;
    print_list(l);
    
    ListNode* output = solve.rotateRight(l, k);
    
    cout << "Output:" << endl;
    print_list(output);

    return 0;
}
