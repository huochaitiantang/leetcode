#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int key; 
    int val;
    Node* next;
    Node* prev;
    Node(int _key, int _val) : key(_key), val(_val), prev(NULL), next(NULL) {}
    void set_next(Node* n){
        next = n;
        if(n) n->prev = this;
    }
    void set_prev(Node* n){
        prev = n;
        if(n) n->next = this;
    }
};

void print_nodes(Node* node, bool from_head){
    Node* p = node;
    while(p){
        printf("(%d=%d) ", p->key, p->val);
        if(from_head) p = p->next;
        else p = p->prev;
    }
    printf("\n");
}

class LRUCache {
private:
    int _capacity = 0;
    int _used = 0;
    Node* _head = NULL;
    Node* _tail = NULL;
    unordered_map<int, Node*> _nodes;

public:    
    LRUCache(int capacity) {
       _capacity = capacity > 0 ? capacity : 0; 
    }

    void set_to_head(Node* n){
        // connect the prev and next nodes   
        if(n == _head) return;
        if(n == _tail) _tail = n->prev;
        if(n->next) n->next->prev = n->prev;
        if(n->prev) n->prev->next = n->next;
        n->prev = NULL;
        // attach to the head
        n->set_next(_head);
        _head = n;
        if(_tail == NULL) _tail = n;
    }

    void delete_tail(){
        if(_tail){
            Node* p = _tail->prev;
            _nodes.erase(_tail->key);
            _used--;
            free(_tail);
            _tail = p;
            if(_tail) _tail->next = NULL;
        }
    }

    int get(int key) {
        printf("Try to get key=%d\n", key);
        if(_nodes.find(key) == _nodes.end()) return -1;
        Node* n = _nodes[key];
        // set to the head
        set_to_head(n);
        printf("Got %d=%d\n", key, n->val);
        print_nodes(_head, true);
        print_nodes(_tail, false);
        return n->val;
    }
    
    void put(int key, int value) {
        // not exist
        if(_nodes.find(key) == _nodes.end()){
            if(_used >= _capacity) delete_tail();
            // insert new item
            Node* n = new Node(key, value);
            _used += 1;
            _nodes[key] = n;
            // set to the head
            set_to_head(n);
        }
        // exist
        else {
            Node* n = _nodes[key];
            n->val = value;
            // set to the head
            set_to_head(n);
        }
        printf("Put %d=%d:\n", key, value);
        print_nodes(_head, true);
        print_nodes(_tail, false);
    }
};

int main(){
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache->get(1);    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache->get(2);    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache->get(1);    // 返回 -1 (未找到)
    lRUCache->get(3);    // 返回 3
    lRUCache->get(4);    // 返回 4

    /*
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(2, 1);
    lRUCache->put(3, 2);
    lRUCache->get(3);
    lRUCache->get(2);
    lRUCache->put(4, 3);
    lRUCache->get(2);
    lRUCache->get(3);
    lRUCache->get(4);
    */
    return 0;
}
