#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, output = 0;
        for(i = s.size() - 1; i >= 0; i--){
            if(s[i] == ' ') continue;
            else{
                while(i >= 0 && s[i] != ' '){
                    output++;
                    i--;
                }
                break;
            }
        }
        return output;
    }
};

int main(){
    Solution solve;
    //string input = "Hello World dsfj ";
    string input = " ";

    cout << "Input: " << input << endl;
    cout << "Output: " << solve.lengthOfLastWord(input) << endl;

    return 0;
}
