#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
                int num,i,j;
        num = strs.size();
        if(num==0) return "";
        if(num==1) return strs[0];
        for(i=0;i<strs[0].size();i++){
        	for(j=1;j<num;j++){
        		if(strs[j][i]!=strs[0][i])
        		 break;
        	}
        	if(j!=num)
        		break;
        }
		
	return strs[0].substr(0,i);
    }
};

int main(){
    Solution solve;
    vector<string> input = {"flower","flow","flight"};

    cout << "Input: " << endl;
    for(int i = 0; i < input.size(); i++) cout << input[i] << endl;

    cout << "Output: " << solve.longestCommonPrefix(input) << endl; 

    return 0;
}
