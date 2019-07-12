#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        int i, j, k;
        string pre = "1";
        if(n == 1) return pre;
        
        for(i = 2; i <= n; i++){
            string cur = "";
            for(j = 0; j < pre.size(); j++){
                k = j + 1;
                while((k < pre.size()) && (pre[k] == pre[j])) k++;
                cur = cur + to_string(k - j) + pre[j];
                j = k - 1;
            }
            pre = cur;
        }
        return pre;
    }
};

int main(){
    Solution solve;
    int input = 10;

    cout << "Input: " << input << endl;
    cout << "Ouput: " << solve.countAndSay(input) << endl;

    return 0;
}
