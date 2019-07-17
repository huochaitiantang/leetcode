#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int i, n = s.size(), output = 0;
        map<char, int> vals = 
        { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
          {'C', 100}, {'D', 500}, {'M', 1000}};
        
        for(i = 0; i < n; i++){
            if((i + 1 < n) && (vals[s[i]] < vals[s[i + 1]])){
                output += vals[s[i + 1]] - vals[s[i]];
                i++;
            }
            else{
                output += vals[s[i]];
            }
        }
        return output;
    }
};



int main(){
    Solution solve;
    //string s = "MCMXCIV";
    string s = "LVIII";

    cout << "Input: " << s << endl;
    cout << "Output: " << solve.romanToInt(s) << endl;

    return 0;
}
