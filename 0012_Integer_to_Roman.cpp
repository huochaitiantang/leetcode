#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int qian,bai,shi,ge;
        qian = num/1000;
        bai = num/100%10;
        shi = num/10%10;
        ge = num%10;
        for(int i=0;i<qian;i++){ ans+="M"; }
        
		if(bai<=3){
        	for(int i=0;i<bai;i++) ans+="C";
        }
        else if(bai==4){ ans+="CD"; }
        else if(bai<=8){
        	ans+="D";
        	for(int i=5;i<bai;i++) ans+="C";
        }
        else{ ans+="CM"; }
        
    	if(shi<=3){
        	for(int i=0;i<shi;i++) ans+="X";
        }
        else if(shi==4){ ans+="XL"; }
        else if(shi<=8){
        	ans+="L";
        	for(int i=5;i<shi;i++) ans+="X";
        }
        else{ ans+="XC"; }
        
        if(ge<=3){
        	for(int i=0;i<ge;i++) ans+="I";
        }
        else if(ge==4){ ans+="IV"; }
        else if(ge<=8){
        	ans+="V";
        	for(int i=5;i<ge;i++) ans+="I";
        }
        else{ ans+="IX"; }
        
        return ans;
    }
};

int main(){
    Solution solve;
    int x = 1994;
    
    cout << "Input: " << x << endl;
    cout << "Output: " << solve.intToRoman(x) << endl;

    return 0;
}
