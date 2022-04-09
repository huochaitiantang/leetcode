#include "common.hpp"

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        int x = columnNumber;
        char tmp;
        while(x > 0){
            if (x % 26 == 0) tmp = 'Z';
            else tmp = 'A' + (x % 26) - 1;
            s = tmp + s;
            x = (x - 1) / 26;
        }
        return s;
    }
};

int main(){
    Solution solve;
    int x = 1;
    //int x = 28;
    //int x = 701; //26 * 26 + 25
    //int x = 2147483647;
    //int x = 52; //1x26+26
    cout << solve.convertToTitle(x) << endl;
    return 0;
}
