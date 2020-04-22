#include<sstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public: 
    void collect(string s, vector<int>& cur, vector<string>& res){
        if(cur.size() == 4){
            if(s.length() == 0){
                std::ostringstream ostr;
                ostr << cur[0] << "." << cur[1] << "." << cur[2] << "." << cur[3];
                res.push_back(ostr.str());
            }
            else return;
        }
        for(int i = 0, x = 0; i < s.length(); i++){
            x = x * 10 + (s[i] - '0');
            if(x < 256){
                cur.push_back(x);
                collect(s.substr(i + 1), cur, res);
                cur.pop_back();
                if((s[i] == '0') && (x == 0)) break;
            }
            else break;
        }
        return;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> cur;
        collect(s, cur, res);
        return res;
    }
};

int main(){
    //string s = "25525511135";
    string s = "010010";
    Solution solve;
    vector<string> res = solve.restoreIpAddresses(s);
    for(int i = 0; i < res.size(); i++)
        std::cout << res[i] << std::endl;
    return 0;
}
