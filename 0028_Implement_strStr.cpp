#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    // Brute: 1168 ms
    int strStr1(string haystack, string needle) {
        if(needle.length() == 0) return 0;
        int i, j;
        int hlen = haystack.length();
        int nlen = needle.length();
        for(i = 0; i < hlen; i++){
            for(j = 0; j < nlen; j++)
                if(needle[j] != haystack[i + j]) break;
            if(j == nlen) return i;
        }
        return -1;
    }

    // KMP 16ms
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;
        
        int i, k;
        vector<int> next = {0};
        // get next array
        for(i = 1, k = 0; i < needle.length(); i++){
            // k jump to the max public prefix of prefix
            while((k > 0) && (needle[i] != needle[k])) k = next[k - 1];
            if(needle[i] == needle[k]) k++;
            next.push_back(k);
        }

        // kmp
        for(i = 0, k = 0; i < haystack.length(); i++){
            while((k > 0) && (haystack[i] != needle[k])) k = next[k - 1];
            if(haystack[i] == needle[k]) k++;
            if(k == needle.length()) return i - k + 1;
        }
        return -1;
    }
};

int main(){
    Solution solve;
    string haystack = "dabxabxababxabwabxad";
    string needle = "abxabwabxad";

    cout << "Input: " << haystack << " " << needle << endl;
    int output = solve.strStr(haystack, needle);
    cout << "Output: " << output << endl;
    
    return 0;
}
