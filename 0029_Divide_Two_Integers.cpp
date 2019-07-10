#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long output = 0, size = 1;
        long long pos_dend, sor;

        pos_dend = abs((long long)dividend);
        sor = abs((long long)divisor);

        // each iter, substract a number 2 times as last
        // could use shift operation, save memory
        while(pos_dend - sor >= 0){
            output += size;
            pos_dend -= sor;
            sor <<= 1;
            size <<= 1;
        }
        // substract the all rest of sors vector
        while(size > 0){
            if(pos_dend >= sor){
                output += size;
                pos_dend -= sor;
            }
            sor >>= 1;
            size >>= 1;
        }
        // signed
        if(!((dividend > 0) && (divisor > 0) || (dividend < 0) && (divisor < 0)))
            output = -output;
        if((output > 2147483647) || (output < -2147483648)) 
            return 2147483647;
        return output;
    }
};

int main(){
    Solution solve;
    int dividend = -2147483648;
    int divisor = -1;

    cout << "Input: " << dividend << " " << divisor << endl;
    cout << "Output: " << solve.divide(dividend, divisor) << endl;

    return 0;
}
