#include "common.hpp"

class Solution {
public:
    int rr(string s, int si, string t, string cs){
        if(cs.size() == t.size()) return 1;
        if(si >= s.size()) return 0;
        // not include this char
        int cnt1 = rr(s, si + 1, t, cs);
        // include this char
        int cnt2 =0;
        if(s[si] == t[cs.size()]){
            cs.push_back(s[si]);
            cnt2 = rr(s, si + 1, t, cs);
            cs.pop_back();
        }
        return cnt1 + cnt2;
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m > n) return 0;
        // numbers substr t(0:j) of s(0:i) 
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        // border
        if(s[0] == t[0]) dp[0][0] = 1;
        for(int i = 1; i < n; i++){
            dp[i][0] = s[i] == t[0] ? dp[i - 1][0] + 1 : dp[i - 1][0];
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                // substr t(0:j) of s(0:i-1)£¬if equal add t(0:j-1) of s(0:i-1) 
                dp[i][j] = s[i] == t[j] ? dp[i - 1][j] + dp[i - 1][j - 1] 
                                        : dp[i - 1][j];
            }
        }
        return (int)dp[n - 1][m - 1];
    }
};

int main(){
    Solution solve;
    string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    string t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    std::cout << solve.numDistinct(s, t) << std::endl;
    return 0;
}
