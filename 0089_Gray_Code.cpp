#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> deltas;
        vector<int> res;
        int i = 0, j, base = 1;
        // gray codes: 0, 1, 3, 2, 6, 7, 5, 4
        // deltas: +1, +2, -1, +4, +1, -2, -1
        // other great operation: for(i=0;i<pow(2,n);i++) res.push_back(i^(i>>1));
        while(i < n){
            deltas.push_back(base);
            for(j = deltas.size() - 2; j >= 0; j--){
                deltas.push_back(-deltas[j]);
            }
            base <<= 1;
            i++;
        }
        res.push_back(0);
        j = 0;
        for(i = 0; i < deltas.size(); i++){
            j = j + deltas[i];
            res.push_back(j);
        }
        return res;
    }
};

int main(){
    int n = 5;
    Solution solve;
    vector<int> res = solve.grayCode(n);
    for(int i = 0; i < res.size(); i++)
        std::cout << res[i] << " ";
    return 0;
} 
