#include "common.hpp"
#include<stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() <= 0) return 0;
        stack<int> stk;
        for(auto token: tokens){
            if(token != "+" && token != "-" && token != "*" && token != "/"){
                stk.push(atoi(token.c_str()));
                continue;
            }
            int op2 = stk.top();
            stk.pop();
            int op1 = stk.top();
            stk.pop();
            
            if(token == "+") stk.push(op1 + op2);
            else if(token == "-") stk.push(op1 - op2);
            else if(token == "*") stk.push(op1 * op2);
            else stk.push(op1 / op2);
        }
        return stk.top();
    }
};

int main(){
    Solution solve;
    vector<string> tokens;
    //vector<string> tokens = {"2","1","+","3","*"};
    //vector<string> tokens = {"4","13","5","/","+"};
    //vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << solve.evalRPN(tokens) << endl;
    return 0;
}
