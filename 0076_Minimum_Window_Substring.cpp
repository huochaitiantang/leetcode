#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std; 

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i, j, left, minlen = n + 1, curlen;
        char lack;
        unordered_map<char, int> map;
        unordered_map<char, int>::iterator it;
        // bound
        if(n == 0 || m == 0) return "";
        // init
        for(i = 0; i < m; i++){
        	if(map.find(t[i]) != map.end()){
        		map[t[i]] += 1;
			}
			else{
				map[t[i]] = 1;	
			}
		}
		// find the first satisfied sub string
		for(i = 0; i < n; i++){
			if(map.find(s[i]) != map.end()){
				map[s[i]]--;
				break;
			}
		}
		for(j = i, it = map.begin();j < n;){
			while(it->second > 0){
				j++;
				if(j >= n) break;
				if(map.find(s[j]) != map.end()) map[s[j]]--;
			}
			if(it->second > 0) break;
			it++;
			if(it == map.end()) break;
		}
		if(it != map.end()) return "";
		// left and right pointer
        while(true){
        	curlen = j - i + 1;
        	if(curlen < minlen){
        		left = i;
        		minlen = curlen;
			}
			// left pointer move to a letter in the T
			lack = s[i];
			map[lack]++;
			i++;
			while((i < n) && (map.find(s[i]) == map.end())) i++;
			if(i >= n) break;
			// if the lack letter not influence the new substring satisfied
			if(map[lack] <= 0) continue;
			else{
				// find the next s[j] == lack to make the new substring satisfied
				j++;
				while((j < n) && (s[j] != lack)){
					if(map.find(s[j]) != map.end()) map[s[j]]--;
					j++;
				}
				if(j >= n) break;
				map[lack]--;
			}
		}
		if(minlen > n) return "";
		else return s.substr(left, minlen);
    }
};


int main(){
	string S = "ADOBECODEBANC";
	string T = "ABC";
	//string S = "aa";
	//string T = "aa";
	Solution solve;
	cout << solve.minWindow(S, T); 
}
