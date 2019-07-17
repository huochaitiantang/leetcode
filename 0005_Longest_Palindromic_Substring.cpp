#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
         int  size,i,j,maxsize=0,maxi,maxj;
        bool isPal[1000][1000];
        size = s.size();
       	//9,89,789,6789,56789,...
		for(i=size-1;i>=0;i--){
       		for(j=i;j<size;j++){
       			if(j==i) isPal[i][j] = true;
				else if(j==i+1) isPal[i][j] = (s[i]==s[j]);
       			else isPal[i][j] = (isPal[i+1][j-1] && (s[i]==s[j]));
       			
       			if(isPal[i][j] && (j-i+1>maxsize)){
       				maxsize = j-i+1;
       				maxi = i;
       				maxj = j;
       			}
       		}
       	}
       	
        return s.substr(maxi,maxsize);
    }
};

int main(){
    Solution solve;
    string input = "babad";

    cout << "Input: " << input << endl;
    cout << "Output: " << solve.longestPalindrome(input) << endl;

    return 0;
}
