#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int i, output = 0;
        vector<int> stack = {-1};
        for(i = 0; i < s.size(); i++){
            if(s[i] == '(') stack.push_back(i);
            if(s[i] == ')'){
                stack.pop_back();
                // i - stack[top] is the length;
                if(stack.size() > 0){
                    int len = i - stack.back();
                    if(len > output) output = len;
                }
                else stack.push_back(i);
            }
        }
        return output;
    }
};

int main(){
    Solution solve;
    //string input = "(()";
    //string input = ")()())";
    //string input = "()(()";
    //string input = "()))(((()))";
    string input = ")()())";

    cout << "Input: " << input << endl;
    cout << "Output: " << solve.longestValidParentheses(input) << endl;

    return 0;
}
