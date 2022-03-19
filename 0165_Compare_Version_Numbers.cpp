#include "common.hpp"
#include<vector>
#include<unordered_set>
#include<algorithm>

class Solution {
public:
    // get next index and number value
    pair<int, int> get_next_number(string s, int index) {
        int ans = 0;
        while((index < s.length()) && (s[index] != '.')) {
            ans = ans * 10 + (s[index] - '0');
            index++;
        }
        return {index + 1, ans};
    }

    int compareVersion(string version1, string version2) {
        int idx1 = 0, idx2 = 0;  
        pair<int, int> tmp1;
        pair<int, int> tmp2; 
        while((idx1 < version1.length()) || (idx2 < version2.length())) {
            tmp1 = get_next_number(version1, idx1);
            tmp2 = get_next_number(version2, idx2);
            if(tmp1.second > tmp2.second) return 1;
            else if(tmp1.second < tmp2.second) return -1;
            else{
                idx1 = tmp1.first;
                idx2 = tmp2.first;
            }
        }
        return 0;
    }
};

int main(){
    Solution solve;
    string s1 = "02.1";
    string s2 = "1.1";
    cout << solve.compareVersion(s1, s2);
    return 0;
}
