#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        vector<int> stack;
        vector<char> maps = {'(', ')'};
        vector<int> cnt = {n, n};
        int top = n * 2 - 1;

        for(int i = 0; i < n; i++) stack.push_back(0);
        for(int i = 0; i < n ;i++) stack.push_back(1);

        while(true){
            string s = "";
            for(int i = 0; i < n * 2; i++) s += maps[stack[i]];
            if(s.length() > 0) output.push_back(s);

            //backtrace to the 0 and cnt[0] - cnt[1] > 1
            while((top >= 0) && !((stack[top] == 0) && (cnt[0] - cnt[1] > 1))){
                cnt[stack[top]]--;
                top--;
            }
           
            if(top < 0) break;

            stack[top]++;
            cnt[1]++;
            cnt[0]--;
           
            while(++top < n * 2){
                if(cnt[0] >= n) stack[top] = 1;
                else stack[top] = 0;
                cnt[stack[top]]++;
            }
            top--;
        }
        return output;
    }
};

int main(){
    Solution solve;
    int input = 3;
    vector<string> output;

    cout << "Input: " << input << endl;

    output = solve.generateParenthesis(input);

    cout << "Output: " << endl;
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;

}

