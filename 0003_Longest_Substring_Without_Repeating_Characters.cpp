#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, k, output = 0, n = s.size();
        vector<int> flag(128, -1);

        while(i < n){
            // find as long as possible
            while((j < n) && (flag[(int)s[j]] < 0)){
                flag[(int)s[j]] = j;
                j++;
            }
            // record
            if(j - i > output) output = j - i;
            if(j >= n) return output;
            // jump the i to index of duplicate value
            for(k = i; k < flag[(int)s[j]]; k++)
                flag[(int)s[k]] = -1;
            flag[(int)s[k]] = j;
            i = k + 1;
            j++;
        }
        return output;
    }
};

int main(){
    Solution solve;
    //string input = "abcabcbb";
    //string input = "bbbb";
    //string input = "pwwkew";
    //string input = "abcdec";
    string input = "umvejcuuk";

    cout << "Input: " << input << endl;
    cout << "Output: " << solve.lengthOfLongestSubstring(input) << endl;

    return 0;
}
