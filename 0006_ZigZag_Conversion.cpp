#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
       string ans = "";
        int size = s.size();
        int inter = (numRows-1)*2;
        if(numRows==1) return s;
        for(int row=0;row<numRows;row++){     	
        //cout << "row:"<<row<<endl;
			for(int i=row;i<size;i=i+inter){
			//	cout << "i:"<<i<<endl;
        		ans += s[i];
				if(row>0 && (row<numRows-1) && ((numRows-row-1)*2+i<size)){
        			ans += s[(numRows-row-1)*2+i];
        		}
        	}
        }
        return ans;
    }
};

int main(){
    Solution solve;
    string s = "PAYPALISHIRING";
    int rows = 4;

    cout << "Input: " << s << " " << rows << endl;
    cout << "Output: " << solve.convert(s, rows) << endl;

    return 0;
}
