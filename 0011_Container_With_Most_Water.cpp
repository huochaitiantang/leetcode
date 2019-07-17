#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
   int maxArea(vector<int>& height) {
    	int i,j,max,tmp;
    	i = 0;
    	j = height.size()-1;
    	while(i<j){
    		if(height[i]<height[j]){
    			tmp = (j-i)*height[i];
    			if(tmp>max)
    				max = tmp;
    			i++;
    		}
    		else{
    			tmp = (j-i)*height[j];
    			if(tmp>max)
    				max = tmp;
    			j--;
    		}
    		//cout<<"tmp:"<<tmp<<" max:"<<max<<endl;	
    	}
    	return max;
	}
};

int main(){
    Solution solve;
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Input: " << endl;
    for(int i = 0; i < height.size(); i++) cout << height[i] << " ";
    cout << endl;

    cout << "Output: " << solve.maxArea(height) << endl;

    return 0;
}
