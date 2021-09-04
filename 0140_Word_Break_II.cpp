#include "common.hpp"
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int sn = s.length();
        int wn = wordDict.size();

        unordered_map<int, unordered_set<string>> map;
        unordered_set<int> sizes;

        for(auto word: wordDict){
            int len = word.size();
            sizes.insert(len);
            if(map.find(len) == map.end()){
                map[len] = unordered_set<string>();
            }
            map[len].insert(word);
        }

        // fast judge
//        vector<bool> flag(sn, false);
//        for(int i = 0; i < sn; i++){
//            for(auto size: sizes){
//                if(i - size + 1 < 0) continue;
//                string cur_s = s.substr(i - size + 1, size);
//                bool pre = (i - size < 0) || flag[i - size];
//                if(pre && (map[size].find(cur_s) != map[size].end())){
//                    flag[i] = true;
//                    break;
//                }
//            }
//        }
//        if (flag[sn - 1] == false) return {};

        vector<vector<string>> dp(sn, vector<string>());
        for(int i = 0; i < sn; i++){
            for(auto size: sizes){
                if(i - size + 1 < 0) continue;
                string cur_s = s.substr(i - size + 1, size);
                bool pre = (i - size < 0) || dp[i - size].size() > 0;
                if(pre && (map[size].find(cur_s) != map[size].end())){
                    // first split word
                    if(i - size < 0)
                        dp[i].push_back(cur_s);
                    // behind other word
                    else
                        for(auto pre_s: dp[i - size])
                            dp[i].push_back(pre_s + " " + cur_s);
                }
            }
        }
        return dp[sn - 1];
    }
};

int main(){
    Solution solve;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    //string s = "pineapplepenapple";
    //vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    //string s = "catsandog";
    //vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

    vector<string> res = solve.wordBreak(s, wordDict);
    for(auto s: res) cout << s << endl; 
    return 0;
}
