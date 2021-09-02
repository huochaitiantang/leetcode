#include "common.hpp"
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
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

        vector<bool> dp(sn, false);
        for(int i = 0; i < sn; i++){
            for(auto size: sizes){
                if(i - size + 1 < 0) continue;
                string cur_s = s.substr(i - size + 1, size);
                bool pre = (i - size < 0) || dp[i - size];
                if(pre && (map[size].find(cur_s) != map[size].end())){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[sn - 1];
    }
};

int main(){
    Solution solve;
    //string s = "leetcode";
    //vector<string> wordDict = {"leet", "code"};
    //string s = "applepenapple";
    //vector<string> wordDict = {"apple", "pen"};
    //string s = "catsandog";
    //vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    
    cout << solve.wordBreak(s, wordDict) << endl;
    return 0;
}
