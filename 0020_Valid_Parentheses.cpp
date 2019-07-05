#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:

    bool match(char c1, char c2){
        if(((c1 == '(') && c2 == ')') ||
          ((c1 == '[') && c2 == ']') ||
          ((c1 == '{') && c2 == '}'))
            return true;
        else return false;
    }

    bool isValid(string s) {
        vector<char> stack;
        int top = -1;
        for(int i = 0; i < s.length(); i++){
             
            if((top >= 0) && match(stack[top], s[i])){
                stack.pop_back();
                top--;
            }
            else if((s[i] == ')') || (s[i] == ']') || (s[i] == '}'))
                return false;
            else{
                stack.push_back(s[i]);
                top++;
            }
        }
        if(top < 0) return true;
        else return false;

    }
};

int main (){
    Solution solve;
    string input = "{[]}";

    cout << "Input: " << input << endl;
    cout << "Output: " << solve.isValid(input) << endl;
}
