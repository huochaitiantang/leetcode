#include "common.hpp"
#include<vector>

class MinStack {
private:
    vector<int> vals;
    vector<int> mins;
    int min_val = INT_MAX;
public:
    MinStack() {
        
    }
    void push(int val) {
        if(val < min_val) min_val = val;
        mins.push_back(min_val);
        vals.push_back(val);
    }
    
    void pop() {
        mins.pop_back();
        vals.pop_back();
        if(mins.size() > 0) min_val = mins.back();
        else min_val = INT_MAX;
    }
    
    int top() {
        return vals.back();
    }
    
    int getMin() {
        return mins.back();
    }
};


int main(){
    MinStack* minStack = new MinStack();
    minStack->push(-10);
    minStack->push(14);
    cout << minStack->getMin() << endl; // -10
    cout << minStack->getMin() << endl; // -10
    minStack->push(-20);
    cout << minStack->getMin() << endl; // -20
    cout << minStack->getMin() << endl; // -20
    cout << minStack->top() << endl;    // -20    
    cout << minStack->getMin() << endl; // -20
    minStack->pop();
    minStack->push(10);
    minStack->push(-7);
    cout << minStack->getMin() << endl; // -10
    return 0;
}
