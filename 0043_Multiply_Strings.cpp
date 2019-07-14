#include<iostream>
#include<string>
#include<vector>
#include <algorithm>  

using namespace std;

class Solution {
public:
    vector<long long> format_num(string num){
        vector<long long> ans;
        // split as 8 bits (as 10 dec)
        for(int i = num.size() - 1; i >= 0; i -= 8){
            long long base = 1, val = 0;
            for(int j = 0; (j < 8) && (i - j >= 0); j++){
                val += (num[i - j] - '0') * base;
                base *= 10;
            }
            ans.push_back(val);
        }
        //reverse(ans.begin(), ans.end());
        return ans;
    }

    string multiply1(string num1, string num2) {
        int i, j;
        long long base, val, flag = 0;
        vector<long long> x1 = format_num(num1);
        vector<long long> x2 = format_num(num2);
        
        // multiply
        int n = x1.size() + x2.size() - 1;
        vector<long long> ans(n, 0);
        for(i = 0; i < x1.size(); i++){
            for(j = 0; j < x2.size(); j++){
                ans[i + j] += x1[i] * x2[j];
            }
        }

        vector<char> str;
        // tidy the ans, from low bit to high bit
        for(i = 0; i < n; i++){
            ans[i] += flag;
            cout << "ans " << i << " " << ans[i] << endl;
            flag = ans[i] / 100000000;
            ans[i] = ans[i] % 100000000;
            
            for(j = 0; j < 8; j++){
                str.push_back('0' + (ans[i] % 10));
                ans[i] = ans[i] / 10;
            }
        }
        if(flag > 0){
            for(j = 0; j < 8; j++){
                str.push_back('0' + (flag % 10));
                flag = flag / 10;
            }
        }
        
        // convert to the string ans
        string s = "";
        flag = 0;
        for(i = str.size() - 1; i >= 0; i--){
            if((flag == 0) && (str[i] == '0')) continue;
            flag = 1;
            s += str[i];
        }

        if(s.size() <= 0) return "0";
        else return s;
    }

    // split as one bit only
    string multiply(string num1, string num2) {
        int i, j, n1, n2, flag = 0;
        n1 = num1.size();
        n2 = num2.size();
        vector<int> ans(n1 + n2 - 1, 0);

        for(i = 0; i < n1; i++)
            for(j = 0; j < n2; j++)
                ans[i + j] += (num2[j] - '0') * (num1[i] - '0');
            
        string s = "";
        for(i = n1 + n2 - 2; i >= 0; i--){
            ans[i] += flag;
            flag = ans[i] / 10;
            ans[i] %= 10;
            s += (char)(ans[i] + '0');
        }
        while(flag > 0){
            s += (char)(flag % 10 + '0');
            flag /= 10;
        }
        while(s.back() == '0') s.pop_back();
        if(s.size() <= 0) return "0";
        reverse(s.begin(), s.end());

        return s;
    }
};

int main(){
    Solution solve;
    string num1 = "10000";
    string num2 = "0";

    cout << "Input: " << num1 << " x " << num2 << endl;
    cout << "Output: " << solve.multiply(num1, num2) << endl;

    return 0;
}
