#include "common.hpp"

class Solution {
public:
    int trailingZeroes(int n) {
        // because count of factor 2 is enough
        // count of factor 5
        int res = 0;
        int val = n;
        while(val > 0){
            val /= 5;
            res += val; 
        }
        return res;
    }
};

int main(){
    Solution solve;
    // int x = 10; 
    // int x = 100;
    // int x = 3;
    // int x = 5;
    int x = 0;
    cout << solve.trailingZeroes(x) << endl;
    return 0;
}
