#include <iostream>
#include <string> 
#include <vector>
using namespace std;
  
class Solution {
public:
    // using backtrace, run out of time
    bool isMatch1(string s, string p) {
        int i, j;
        int plen = p.size();
        int slen = s.size();
        vector<vector<int> > stack;
        // get rid of duplicate *
        for(i = 0, j = 0; i < plen; i++){
            p[j++] = p[i];
            if(p[i] == '*'){ 
                while(p[i] == '*') i++;
                i--;
            }
        }
        plen = j;

        // behind array save the no * char after cur index
        vector<int> behind(plen, 0);
        for(i = plen - 2; i >= 0; i--){
            behind[i] = behind[i + 1];
            if(p[i + 1] != '*') behind[i]++;
        }
        
        for(i = 0; i < plen; i++) cout << p[i];
        cout << endl;
        for(i = 0; i < plen; i++) cout << behind[i] << " ";
        cout << endl;
        

        i = j = 0;
        while(true){
            //cout << "i=" << i << " j=" << j << endl;
            // with stars, matched as many as posible, save the index and times
            if((j < plen) && (i < slen) && (p[j] == '*')){
                int max_time = slen - i - behind[j];
                // backtrace, eg. s=abcd, p=ab*abcd(i = j = 2, behind[j] = 4)
                if(max_time < 0){
                    while((stack.size() > 0) && (stack.back()[2] <= 0))
                        stack.pop_back();
                
                    if(stack.size() > 0){
                        i = stack.back()[0];
                        j = stack.back()[1];
                        stack.back()[2]--;
                        j++;
                        i += stack.back()[2];
                    }
                    else{
                        return false;
                    }
                }
                else{
                    vector<int> ind_time = {i, j, max_time};
                    stack.push_back(ind_time);
                    i += stack.back()[2];
                    j++;
                }
                //cout << "star matched:" << " i:" << i << " j:" << j << endl;
            }
            // not with stars and matched
            else if((j < plen) && (i < slen) && ((p[j] == '?') || (p[j] == s[i]))){
                i++;
                j++;
                //cout << "nostar matched:" << " i:" << i << " j:" << j << endl;
            }
            // matched with same ending
            else if((i == slen) && (j == plen)){
                /*cout << "Match Success" << endl;
                for(int m = 0; m < stack.size(); m++)
                    cout << m << ": i=" << stack[m][0] << " j=" << stack[m][1] << " time=" << stack[m][2] << endl;
                */
                return true;
            }
            // s = a, p = a*
            else if((i == slen) && (j < plen) && (p[j] == '*')){
                vector<int> ind_time = {i, j, 0};
                stack.push_back(ind_time);
                j++;
            }
            // not matched: backtrace
            else{
                while((stack.size() > 0) && (stack.back()[2] <= 0))
                    stack.pop_back();
                
                if(stack.size() > 0){
                    i = stack.back()[0];
                    j = stack.back()[1];
                    stack.back()[2]--;
                    j++;
                    i += stack.back()[2];
                }
                // cannot backtrace
                else{
                    return false;
                }
            }
        }

    }

    bool isMatch(string s, string p) {
        int i, j, k;
        int slen = s.size();
        int plen = p.size();

        if((slen == 0) && (plen == 0)) return true;
        if((slen != 0) && (plen == 0)) return false;
        if((slen == 0) && (plen != 0)){
            for(i = 0; i < plen; i++)
                if(p[i] != '*') return false;
            return true;
        }

        vector<vector<bool> > match(slen, vector<bool>(plen, false));
        
        // init match[i][0]
        if((p[0] == '?') || (p[0] == '*') || (p[0] == s[0])) match[0][0] = true;
        //match[i][0] = true(i >= 1) if only p[0] = '*';
        for(i = 1; i < slen; i++)
            if(p[0] == '*') match[i][0] = true;
        
        // init match[0][j]
        bool valid_char = false;
        if((s[0] == p[0]) || (p[0] == '?')) valid_char = true;
        for(j = 1; j < plen; j++){
            // valid char can only match once
            if((!valid_char) && match[0][j -1] && ((p[j] == s[0]) || (p[j] == '?'))){
                valid_char = true;
                match[0][j] = true;
            }
            if(p[j] == '*'){
                match[0][j] = match[0][j - 1];
            }
        }

        for(j = 1; j < plen; j++){
            for(i = 1; i < slen; i++){
                // match[i][j] = a[i][j-1] || a[i-1][j-1] || ... a[0][j-1], if p[j] = '*'
                if(p[j] == '*'){
                    for(k = 0; k <= i; k++)
                        if(match[k][j - 1]) break;
                    if(k <= i) match[i][j] = true;
                }
                // match[i][j] = a[i-1][j-1] && (s[i] = p[j] || p[j] = '?') if p[j] != '*'
                else{
                    match[i][j] = (match[i - 1][j - 1]) && ((s[i] == p[j] || (p[j] == '?')));

                }
            }
        }

        for(i = 0; i < slen; i++){
            for(j = 0; j < plen; j++){
                cout << match[i][j] << " ";
            }
            cout << endl;
        }

        return match[slen - 1][plen - 1];
         
    }
};

int main (){
    //string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    //string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    //string s = "aab";
    //string p = "c*a*b*";
    string s = "acdcb";
    string p = "*a*b";


    Solution solve;
    cout << "Input: " << endl << "s: " << s << endl << "p: " << p << endl;
    cout << "Output: " << solve.isMatch(s, p) << endl;

    return 0;

}
