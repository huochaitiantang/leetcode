#include <iostream>
#include <string> 
#include <vector>
using namespace std;
  
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j, k;
        int plen = p.length();
        int slen = s.length();
        vector<char> chars;
        vector<bool> stars;
        vector<int> times;

        // format pattern
        while(i < plen){
            if((i < plen - 1) && (p[i + 1] == '*')){
                chars.push_back(p[i++]);
                stars.push_back(true);
                while((i < plen) && (p[i] == '*')) i++;
            }
            else{
                chars.push_back(p[i++]);
                stars.push_back(false);
            }
        }
       
        plen = chars.size();
        i = j = k = 0;
        while(true){
            // with stars
            if((j < plen) && (i < slen) && (stars[j] == true)){
                // matched as many as posible
                if((chars[j] == '.') || (chars[j] == s[i])){
                    times.push_back(0);
                    while((i < slen)&&((chars[j] == '.') || (chars[j] == s[i]))){
                        times[times.size() - 1]++;
                        i++;
                    }
                    j++;
                    //cout << "star matched:" << " i:" << i << " j:" << j << endl;
                }
                // not matched, jump cur char
                else{
                    times.push_back(0);
                    j++;
                    //cout << "star not matched:" << " i:" << i << " j:" << j << endl;
                }
            }
            // not with stars and matched
            else if((j < plen) && (i < slen) && ((chars[j] == '.') || (chars[j] == s[i]))){
                times.push_back(1);
                i++;
                j++;
                //cout << "nostar matched:" << " i:" << i << " j:" << j << endl;
            }
            // matched with same ending
            else if((i == slen) && (j == plen)){
                /*cout << "Match Success" << endl;
                for(int m = 0; m < times.size(); m++){
                    cout << m << ": char=" << chars[m] << " star=" << stars[m] << " time=" << times[m] << endl;
                }*/
                return true;
            }
            // s = a, p = ab*
            else if((i == slen) && (j < plen) && (stars[j] == true)){
                times.push_back(0);
                j++;
            }
            // not matched without stars or j >= plen or i >= slen, should backtrace
            else{
                // backtrace
                while((j > 0) && (stars[j - 1] == false ||
                      ((stars[j - 1] == true) && (times[j - 1] <= 0)))){
                        i -= times[j - 1];
                        j--;
                        times.pop_back();
                }
                // the char with stars whose times > 0 --
                if(j > 0){
                    i--;
                    times[j - 1]--;
                }
                // cannot backtrace
                else{
                    //cout << "Match Failed" << endl;
                    return false;
                }
            }
        }
        
    }
};

int main (){
    string s = "a";
    string p = "ab*";

    Solution solve;
    cout << "s: " << s << endl << "p: " << p << endl;
    cout << solve.isMatch(s, p) << endl;

    return 0;

}
