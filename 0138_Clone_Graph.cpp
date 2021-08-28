#include<vector>
#include<unordered_map>
#include<queue>
#include<iostream>
using namespace std; 


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
    void print() {
        cout << "Node: val=" << val << " link to: ";
        for(auto n: neighbors){
            cout << n->val << " ";
        }
        cout << endl;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<int, Node*> O; // original nodes
        unordered_map<int, Node*> C; // generated nodes
        queue<Node*> qs;
        qs.push(node);

        while(!qs.empty()){
            Node* cur_node = qs.front();
            int k = cur_node->val;
            O[k] = cur_node;
            C[k] = new Node(k);
            for(auto n: cur_node->neighbors){
                if(O.find(n->val) == O.end()) qs.push(n);
            }
            qs.pop();
        }
        for(auto it: C){
            int k = it.first;
            for(auto n: O[k]->neighbors){
               C[k]->neighbors.push_back(C[n->val]);
            }
        }
        // for(auto it: C) it.second->print();
        return C[node->val];
    }
};

int main(){
    Solution solve;
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Node* res = solve.cloneGraph(n1);
    return 0;
}
