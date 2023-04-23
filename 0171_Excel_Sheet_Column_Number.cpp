#include "common.hpp"

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int val = 0;
        for(auto c : columnTitle){
            val = 26 * val + (c - 'A') + 1;
        }
        return val;
    }
};

int main(){
    Solution solve;
    string s = "A";
    //string s = "AA";
    //string s = "AAA";
    //string s = "ZY";
    //string s = "FXSHRXW";
    cout << solve.titleToNumber(s) << endl;
    return 0;
}
