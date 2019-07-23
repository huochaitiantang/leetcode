#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string output = "";
        int i, j, ind = k - 1, cnt, fac = 1;
        vector<bool> used(n, false);

        // max fac value
        for(i = 1; i < n; i++) fac *= i;

        for(i = n - 1; i >= 0; i--){
            // find the jth not used number
            for(j = 0, cnt = -1; j < n; j++){
                if(!used[j]){
                    cnt++;
                    if(cnt >= ind / fac){
                        output += j + '1';
                        used[j] = true;
                        break;
                    }
                }
            }
            if(i == 0) break; 
            ind %= fac;
            fac /= i;
        }
        return output;
    }
};

int main(){
    Solution solve;
    int n = 4, k = 24;

    cout << "Input: n=" << n << ", k=" << k << endl;
    cout << "Output: " << solve.getPermutation(n, k) << endl;

    return 0;
}
