#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double base = x, output = 1.0;
        long long pos_n = abs((long long)n);

        // fast pow
        while(pos_n > 0){
            if(pos_n % 2 == 1)
                output *= base;
            pos_n >>= 1;
            base = base * base;
        }
        if(n < 0) output = 1.0 / output;

        return output;
    }
};

int main(){
    Solution solve;
    double x = 1;
    int n = -2147483648;

    cout << "Input: pow(" << x << "," << n << ")" << endl;
    cout << "Output: " << solve.myPow(x, n) << endl;

    return 0;
}
