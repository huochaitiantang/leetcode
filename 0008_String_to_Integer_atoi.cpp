#include<iostream>
#include<string>
#include<limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long output = 0;
        int i = 0, n = str.size();
        bool neg = false;
        while((i < n) && (str[i] == ' ')) i++;
        if(i >= n) return 0;

        if(str[i] == '-' || str[i] == '+'){
            if(str[i] == '-') neg = true;
            i++;
        }
        //while((i < n) && (str[i] == ' ')) i++;
        while((i < n) && (str[i] >= '0' && str[i] <= '9')){
            output = (str[i] - '0') + output * 10;
            if(neg && (-output < INT_MIN)) return INT_MIN;
            if(!neg && (output > INT_MAX)) return INT_MAX;
            i++;
        }
        if(neg) output = -output;

        return output;

    }
};

int main(){
    Solution solve;
    //string input = "- 4 2 3 4 dfaf  55";
    //string input = "2147483649";
    //string input = "-+20000000000000000000";
    //string input = "+ 0 1234";
    //string input = "  0000000000012345678";
    string input = "- 2147483648";

    cout << "Input: " << input << endl;
    cout << "Output: " << solve.myAtoi(input) << endl;

    return 0;
}

