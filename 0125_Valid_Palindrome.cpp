#include "common.hpp"

class Solution {
public:
    bool is_alpha(char c){
        return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'));
    }
    
    bool is_equal(char c1, char c2){
        if(((c1 >= '0') && (c1 <= '9')) || ((c2 >= '0') && (c2 <= '0'))) return c1 == c2;
        return (c1 == c2) || (abs(c1 - c2) == abs('a' - 'A'));
    }
    
    bool isPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return true;
        int i = 0, j = n - 1;
        while(true){
            while((i < j) && (!is_alpha(s[i]))) i++;
            while((j > i) && (!is_alpha(s[j]))) j--;
            if(i >= j) return true;
            else if(!is_equal(s[i], s[j])) return false;
            i++;
            j--;
        }
    }
};

int main(){
    Solution solve;
    //string s = "A man, a plan, a canal: Panama";
    string s = "race a car";
    //string s = "0P";
    std::cout << solve.isPalindrome(s) << std::endl;
    return 0;
}
