#include "common.hpp"
#include<unordered_map>

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator;
        long long den = denominator;

        string pre = "";
        if(num * den < 0) pre = "-";    
        num = num >= 0 ? num : -num;
        den = den >= 0 ? den : -den;

        string integer = pre + to_string(num / den);
        long long remainder = num % den;
        if(remainder == 0) return integer;

        string s = "";
        int idx = 0;
        unordered_map<long long, int> maps; // {remainder: idx}

        while(remainder > 0){
            remainder *= 10;
            if(maps.find(remainder) != maps.end()){
                s.insert(maps[remainder], "(");
                s += ")";
                break;
            }
            else maps[remainder] = idx;
            s += to_string(remainder / den);
            remainder = remainder % den;
            idx++;
        }
        return integer + "." + s;
    }
};

int main(){
    Solution solve;
    cout << solve.fractionToDecimal(2, 1) << endl;
    cout << solve.fractionToDecimal(100, 7) << endl;
    cout << solve.fractionToDecimal(1, 41) << endl;
    cout << solve.fractionToDecimal(5, 6) << endl;
    cout << solve.fractionToDecimal(-50, 8) << endl;
    cout << solve.fractionToDecimal(50, -8) << endl;
    cout << solve.fractionToDecimal(-50, -8) << endl;
    cout << solve.fractionToDecimal(-1, -2147483648) << endl;
    return 0;
}
