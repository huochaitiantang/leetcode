#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long output = 0;
        long long pos_x = abs((long long)x);
        // find the first
        while(pos_x > 0){
            output = (pos_x % 10) + output * 10;
            pos_x /= 10;
        }
        if(x < 0) output = -output;
        if(output > INT_MAX || output < INT_MIN)
            return 0;
        
        return output;
    }
};

int main(){
    Solution solve;
    //int x = -123400;
    //int x = -2147483648;
    int x = 2147483412;
    cout << "Input: " << x << endl;
    cout << "Outut: " << solve.reverse(x) << endl;

    return 0;
}  
