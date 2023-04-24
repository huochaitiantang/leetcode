#include "common.hpp"
#include<stack>

class BSTIterator {
public:

    BSTIterator(TreeNode* root) {
        TreeNode* tmp = root;
        while(tmp){
            ns.push(tmp);
            tmp = tmp->left;
        }
    }
    
    int next() {
        TreeNode* n = ns.top();
        ns.pop();
        TreeNode* tmp = n->right;
        while(tmp){
            ns.push(tmp);
            tmp = tmp->left;
        }
        return n->val;
    }

    bool hasNext() {
        return ns.size() > 0;
    }

private:
    stack<TreeNode*> ns;
};

int main(){
    vector<int> v = {7, 3, 15, 0, 0, 9, 20};
    TreeNode* root = construct_tree(v);
    print_tree(root, 0);
    BSTIterator bSTIterator = BSTIterator(root);
    cout << bSTIterator.next() << endl;    // ���� 3
    cout << bSTIterator.next() << endl;    // ���� 7
    cout << bSTIterator.hasNext() << endl; // ���� True
    cout << bSTIterator.next() << endl;    // ���� 9
    cout << bSTIterator.hasNext() << endl; // ���� True
    cout << bSTIterator.next() << endl;    // ���� 15
    cout << bSTIterator.hasNext() << endl; // ���� True
    cout << bSTIterator.next() << endl;    // ���� 20
    cout << bSTIterator.hasNext() << endl; // ���� False
    return 0;
}
