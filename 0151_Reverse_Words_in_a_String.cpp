#include "common.hpp"
#include<stack>

class Solution {
public:
    
    void reverse_by_index(string& s, int low, int high){
        for(int i = low, j = high; i < j; i++, j--){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }

    string reverseWords(string s) {
        int i, j;
        int len = s.length();

        // remove the space
        for(i = 0, j = 0; i < len && j < len;){
            bool flag = s[j] == ' ';
            while(s[j] == ' ' && j < len) j++;
            // end of string
            if(j >= len) break;
            if(flag && i > 0) s[i++] = ' ';
            s[i++] = s[j++];
        }
        if(i < len) s.erase(i, len - i);

        // reverse the string, by sub words and whole
        len = s.size();
        for(i = 0, j = 0; j < len;){
            while(s[j] != ' ' && j < len) j++;
            if(j >= len) break;
            reverse_by_index(s, i, j - 1);
            j++;
            i = j;
        }
        reverse_by_index(s, i, len - 1);
        reverse_by_index(s, 0, len - 1);
        return s;
    }
};

int main(){
    Solution solve;
    //string s = "the sky is blue";
    //string s = "  hello world  ";
    //string s = "a good   example";
    //string s = "  Bob    Loves  Alice   ";
    //string s = "Alice does not even like bob";
    string s = " a  bc de ";
    cout << s << endl;
    cout << solve.reverseWords(s) << endl;
    return 0;
}
