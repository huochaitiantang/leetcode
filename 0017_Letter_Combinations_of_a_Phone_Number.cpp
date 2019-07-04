#include <iostream>
#include <string> 
#include <vector>
using namespace std;
  
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> outputs;
        vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<int> indexs;
        vector<int> bias;
        int i;
        int dlen = digits.length();

        for(i = 0; i < dlen; i++){
            indexs.push_back(digits[i] - '2');
            bias.push_back(0);
        }

        // search by dfs
        while(true){
            string s = "";
            for(i = 0; i < dlen; i++)
                s = s + letters[indexs[i]][bias[i]];
            if(s.length() > 0) outputs.push_back(s);

            i = dlen - 1;
            if(i >= 0) bias[i]++;
            // backtrace
            while((i >= 0) && (bias[i] >= letters[indexs[i]].length())){
                bias[i--] = 0;
                if(i >= 0) bias[i]++;
            }
            if(i < 0) break;
        }
        return outputs;
    }
};

int main (){
    string digits = "233";
    vector<string> outputs;

    Solution solve;
    cout << "digits: " << digits << endl;

    outputs = solve.letterCombinations(digits);
    
    for(int i = 0; i < outputs.size(); i++){
        cout << outputs[i] << endl;
    }
    

    return 0;

}
