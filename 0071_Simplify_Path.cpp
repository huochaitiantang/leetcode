#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    public:
    string simplifyPath(string path) {
        int i, n = path.size();
        vector<string> stack;
        string output = "/";
        for(i = 0; i < n; i++){
            while(i < n && path[i] == '/') i++;
            if(i >= n) break;
            // cur path
            if(path[i] == '.' && (i + 1 >= n || path[i + 1] == '/')) continue;
            // last path, pop back
            if(path[i] == '.' && path[i + 1] == '.' && (i + 2 >= n || path[i + 2] == '/')){
                if(stack.size() > 0){
                    //cout << "POP " << stack.back() << endl;
                    stack.pop_back();
                }
                i++;
            }
            // directory
            else{
                string tmp = "";
                while(i < n && path[i] != '/')
                    tmp += path[i++];
                stack.push_back(tmp);
                //cout << "PUSH " << stack.back() << endl;
                i--;
            }
        }
        // tidy directory in the stack
        for(i = 0; i < stack.size(); i++){
            output += stack[i];
            if(i < stack.size() - 1)
                output += '/';
        }
        return output;
    }
};

int main(){
    Solution solve;
    //string input = "/home//";
    //string input = "/../";
    //string input = "/home//foo/";
    //string input = "/a/./b/../../c/";
    //string input = "/a/../../b/../c//.//";
    string input = "/a//b////c/d//././/..";
    //string input = "/...";
    //string input = "/.b";

    cout << "Input: " << input << endl;
    cout << "Output: " << solve.simplifyPath(input) << endl;

    return 0;
}
