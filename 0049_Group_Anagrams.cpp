#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > output;
        unordered_map<string, vector<string> > key_strs;
        unordered_map<string, vector<string> >::iterator it;

        // save as map
        for(int i = 0; i < strs.size(); i++){
            // sort each words
            string s = strs[i];
            sort(s.begin(), s.end());
            key_strs[s].push_back(strs[i]);
        }

        // save the result based on map
        for(it = key_strs.begin(); it != key_strs.end(); it++)
            output.push_back(it->second);

        return output;
     }
};

int main(){
    Solution solve;
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
    cout << endl;

    vector<vector<string> > output = solve.groupAnagrams(input);

    cout << "Output:" << endl;
    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j < output[i].size(); j++){
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
