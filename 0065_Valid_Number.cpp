#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    public:

        // .-+e
        bool isNumber(string s) {
            int n = s.size(), i = n - 1;
            bool pointStart = false;
            // remove last space
            while(i >= 0 && s[i] == ' '){
                i--;
                n--;
            }
            if(n <= 0) return false;
            i = 0;
            // remove the first space
            while(i < n && s[i] == ' ') i++;
            if(s[i] == '+' || s[i] == '-') i++;

            if(i >= n) return false;
            if(!(((s[i] >= '0') && (s[i] <= '9')) || s[i] == '.')) return false;
            if(s[i] == '.') pointStart = true;
            while(i < n && s[i] >= '0' && s[i] <= '9') i++;
            if(i >= n) return true;
            
            if(s[i] == 'e'){
                i++;
                if(i >= n) return false;
                if(s[i] == '+' || s[i] == '-') i++;
                if(i >= n) return false;
                while(i < n && s[i] >= '0' && s[i] <= '9') i++;
                while(i < n && s[i] == ' ') i++;
                if(i < n) return false;
                else return true;
            }
            else if(s[i] == '.'){
                i++;
                if(i >= n && pointStart) return false;
                if(i >= n) return true;
                if(pointStart && (s[i] < '0' || s[i] > '9')) return false;
                while(i < n && s[i] >= '0' && s[i] <= '9') i++;
                if(i >= n) return true;
                if(s[i] == 'e'){
                    i++;
                    if(i >= n) return false;
                    if(s[i] == '+' || s[i] == '-') i++;
                    if(i >= n) return false;
                    while(i < n && s[i] >= '0' && s[i] <= '9') i++;
                    while(i < n && s[i] == ' ') i++;
                    if(i < n) return false;
                    else return true;
                }
                else return false;
            }
            else return false;
        }
};

int main(){
    Solution solve;
    //string input = "0";
    //string input = " 0.1";
    //string input = "abc";
    //string input = "1 a";
    //string input = "2e10";
    //string input = "-90e3";
    //string input = " 1e";
    //string input = "e3";
    //string input = "6e-1";
    //string input = "99e2.5";
    //string input = "53.5e93";
    //string input = " --6";
    //string input = "-+3";
    //string input = "95a54e53";
    //string input = ".1";
    //string input = ".";
    string input = "1.";
    //string input = ".e1";

    cout << "Input: " << input << endl;
    cout << "Output: " << solve.isNumber(input) << endl;

    return 0;
}
