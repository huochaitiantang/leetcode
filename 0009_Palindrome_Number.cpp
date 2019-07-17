#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        vector<int> m;
        while(x > 0){
            m.push_back(x % 10);
            x /= 10;
        }
        for(int i = 0, j = m.size() - 1; i < j; i++, j--)
            if(m[i] != m[j]) return false;
        return true;
    }
};


int main(){
    Solution solve;
    int x = 12321;

    cout << "Input: " << x << endl;
    cout << "Output: " << solve.isPalindrome(x) << endl;

    return 0;
}
