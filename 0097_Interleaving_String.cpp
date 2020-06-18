#include<iostream>
#include<string>
#include<vector>
using namespace std; 

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1 + n2 != n3) return false;
        vector<vector<bool> > a(n1 + 1, vector<bool>(n2 + 1, false));
        a[0][0] = true;
        for(int j = 1; j <= n2; j++){
            a[0][j] = a[0][j - 1] ? s2[j - 1] == s3[j - 1] : false;
        }
        for(int i = 1; i <= n1; i++){
            a[i][0] = a[i - 1][0] ? s1[i - 1] == s3[i - 1] : false;
        }
        // a[i][j] = true when 
        // a[i-1][j]=true && s1[i-1]==s3[i+j-1] or
        // a[i][j-1]=true && s2[j-1]==s3[i+j-1]
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if((a[i - 1][j] && s3[i + j - 1] == s1[i - 1]) ||
                   (a[i][j - 1] && s3[i + j - 1] == s2[j - 1]))
                    a[i][j] = true;
                else
                    a[i][j] = false;
            }
        }
        return a[n1][n2];
    }
};

int main(){
    Solution solve;
    string s1 = "aabcc";
    string s2 = "dbbca";
    //string s3 = "aadbbcbcac";
    string s3 = "aadbbbaccc";
    
    s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    
    std::cout << solve.isInterleave(s1, s2, s3) << std::endl;
    return 0;
}
