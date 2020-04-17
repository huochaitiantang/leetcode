#include<iostream>
#include<string>
#include<vector>
using namespace std; 

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        int mid = n / 2;
        if(n == 0) return true;
        if(n == 1) return s1[0] == s2[0];
        string s1_pre, s1_last, s2_pre, s2_last;
        for(int i = 1; i < n; i++){
            s1_pre = s1.substr(0, i);
            s1_last = s1.substr(i, n - i);
            s2_pre = s2.substr(0, i);
            s2_last = s2.substr(i, n - i);
            if(i <= n / 2){
                if(isScramble(s1_pre, s2_pre) && isScramble(s1_last, s2_last)) return true;
            }
            else{
                if(isScramble(s1_last, s2_last) && isScramble(s1_pre, s2_pre)) return true;
            }
            if(i != n - i){
                s2_pre = s2.substr(0, n - i);
                s2_last = s2.substr(n - i, i);
            }
            if(i <= n / 2){
                if(isScramble(s1_pre, s2_last) && isScramble(s1_last, s2_pre)) return true;
            }
            else{
                if(isScramble(s1_last, s2_pre) && isScramble(s1_pre, s2_last)) return true;
            }
        }
        return false;
    }
};

int main(){
    //string s1 = "great";
    //string s2 = "rgtae";
    //string s1 = "abcde";
    //string s2 = "ceadb";
    //string s1 = "abb";
    //string s2 = "bab";
    string s1 = "abcdefghijklmn";
    string s2 = "efghijklmncadb";
    Solution solve;
    std::cout << solve.isScramble(s1, s2) << std::endl;
    return 0;
}
