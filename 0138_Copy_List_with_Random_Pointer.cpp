#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std; 

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void print_node(Node* head){
    if(!head) return;
    unordered_map<int, Node*> xs;
    Node* p = head;
    while(p){
        xs[p->val] = p;
        p = p->next;
    }
    p = head;
    while(p){
        int random_val = -1;
        if(p->random) random_val = p->random->val;
        cout << p->val << "(" << random_val << ")" << " -> ";
        p = p->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        unordered_map<Node*, int> order; // ordered
        vector<Node*> O;  // original nodes
        vector<Node*> C;  // copied nodes

        Node* p = head;
        Node* q = NULL;
        Node* r = NULL;
        int cnt = 0;

        while(p){
            r = new Node(p->val);
            O.push_back(p);
            C.push_back(r);
            if(q) q->next = r;
            q = r;
            order[p] = cnt;
            p = p->next;
            cnt++;
        }

        for(int i = 0; i < C.size(); i++){
            if(O[i]->random){
                int idx = order[O[i]->random];
                C[i]->random = C[idx];
            }
        }

        return C[0];
    }
};


int main(){
    Solution solve;
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(11);
    Node* n5 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    //vector<int> nums = {2, 2, -3, 2, 4, 4, 4};
    print_node(n1);
    Node* res = solve.copyRandomList(n1);
    print_node(res);
    return 0;
}
