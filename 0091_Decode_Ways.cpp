#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s){
        int n = s.length();
        int a[n + 1];
        a[n] = 1;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0'){
                a[i] = 0;
            }
            else if((s[i] == '1' && i < n - 1) ||
                    (s[i] == '2' && i < n - 1 && s[i + 1] >= '0' && s[i + 1] <= '6')){
                a[i] = a[i + 1] + a[i + 2];
            }
            else{
                a[i] = a[i + 1];
            }
        }
        return a[0];
    }
    
    int numDecodings2(string s) {
        int n = s.length(), res = 0;
        //std::cout << s << std::endl;
        if(n == 1 && s[0] == '0') return 0;
        if(n == 0 || n == 1) return 1;
        if(s[0] == '1'){
            if(s[1] == '0'){
                res = numDecodings(s.substr(2));
            }
            else{
                res = numDecodings(s.substr(1)) + numDecodings(s.substr(2));
            }
        }
        else if(s[0] == '2'){
            if(s[1] == '0' || s[1] >= '7'){
                res = numDecodings(s.substr(2));
            }
            else{
                res = numDecodings(s.substr(1)) + numDecodings(s.substr(2));
            }
        }
        else res = numDecodings(s.substr(1));
        return res;
    }
};

int main(){
    //string s = "226";
    string s = "9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253";
    Solution solve;
    std::cout << solve.numDecodings(s) << std::endl; 
    return 0;
} 
