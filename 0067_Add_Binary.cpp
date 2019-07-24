#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
    public:
    string addBinary(string a, string b) {
        string output = "";
        int i, j, flag, cursum;
        int n1 = a.size(), n2 = b.size();
        for(i = n1 - 1, j = n2 -1, flag = 0; i >= 0 && j >= 0; i--, j--){
            cursum = (a[i] - '0') + (b[j] - '0') + flag;
            output += (cursum % 2) + '0';
            flag = cursum / 2;
        }
        while(i >= 0){
            cursum = (a[i] - '0') + flag;
            output += (cursum % 2) + '0';
            flag = cursum / 2;
            i--;
        }
        while(j >= 0){
            cursum = (b[j] - '0') + flag;
            output += (cursum % 2) + '0';
            flag = cursum / 2;
            j--;
        }
        if(flag == 1) output += '1';
        reverse(output.begin(), output.end());
        return output;
    }
};

int main(){
    Solution solve;
    //string a = "11", b = "1";
    //string a = "1010", b = "1011";
    string a = "1", b = "111";

    cout << "Input: a=" << a << " b=" << b << endl;
    cout << "Output: " << solve.addBinary(a, b) << endl;

    return 0;
}
