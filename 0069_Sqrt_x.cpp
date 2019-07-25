#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    int mySqrt(int x) {
        long long mid, low = 0, high = x;
        if(x <= 1) return x;
        while(low <= high){
            mid = (low + high) / 2;
            if(mid * mid > x) high = mid - 1;
            else low = mid + 1;
        }
        return high;
    }
};

int main(){
    Solution solve;
    int x = 9;
    //int x = 2147395599;

    cout << "Input: " << x << endl;
    cout << "Output: " << solve.mySqrt(x) << endl;

    return 0;
}
