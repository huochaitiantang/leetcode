#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double ans = 0;
        int m,n,start1,start2,end1,end2,mid1,mid2,des,step;
        step = start1 = start2 = 0;
		m = nums1.size();
		n = nums2.size();
		end1 = m-1;
        end2 = n-1;
		des = (end1+end2+2)/2;
		mid1 = (start1+end1)/2;
	    mid2 = (start2+end2)/2;
	    if(m==0){
	    	if(n%2==1){ return (double)nums2[end2/2]; }
	    	else{ return ((double)nums2[end2/2]+nums2[end2/2+1])/2; }
	    }
	    if(n==0){
	    	if(m%2==1){ return (double)nums1[end1/2];}
	    	else{ return ((double)nums1[end1/2]+nums1[end1/2+1])/2;}	    
		}
	   while(step<des){
			int cha1,cha2;
	    	cha1 = mid1 - start1;
	    	cha2 = mid2 - start2;
	    	if(cha1==0) cha1 = 1;
	    	if(cha2==0) cha2 = 1;
	    	if(nums1[mid1]<nums2[mid2]){
	    		if(cha1+cha2+step<=des || ((start1==mid1) && (start2==mid2))){ 
					if(start1<mid1) start1 = mid1; 
					else start1++;
				}
				else{
					if(start2!=end2) end2 = mid2;
					else end1 = mid1;
				}	      		
	      	}
	      	else{
	      		if(cha1+cha2+step<=des || ((start1==mid1) && (start2==mid2))){ 
					if(start2<mid2) start2 = mid2; 
					else start2++;
				}
				else{ 
					//1,2  1,2,3这种情况，相等元素 
					if(start1!=mid1) end1 = mid1;
					else end2 = mid2;				
				}	
	      	}
	      	//若第一个数组元素全部删除掉 
	    	step = start1+start2;  
			if(step<des && start1 == m){	start2 = start2 + des - step; }
	      	else if(step<des && start2 == n){ start1 = start1 + des - step; }
				
			mid1 = (start1+end1)/2;
      		mid2 = (start2+end2)/2;
			step = start1+start2;		  	
		}
		//总数为偶 
		if((m+n)%2==0){
			int tb1,tb2;
			if(start1>=m) tb1 = nums2[start2];
			else if(start2>=n) tb1 = nums1[start1];
			else tb1 = (nums1[start1]<nums2[start2])?nums1[start1]:nums2[start2];
			if(start1<=0) tb2 = nums2[start2-1];
			else if(start2<=0)  tb2 = nums1[start1-1];
			else tb2 = (nums1[start1-1]>nums2[start2-1])?nums1[start1-1]:nums2[start2-1];		
			cout <<"tb1:"<<tb1<<" tb2:"<<tb2<<endl;
			ans = ((double)tb1+tb2)/2;
		}
		else{
			if(start1>=m) ans = nums2[start2];
			else if(start2>=n ) ans = nums1[start1];
			else ans = (nums1[start1]<nums2[start2])?(double)nums1[start1]:(double)nums2[start2];
		}
		return ans;
    }
};

int main(){
    Solution solve;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    
    cout << "Input: " << endl;
    for(int i = 0; i < nums1.size(); i++) cout << nums1[i] << " ";
    cout << endl;
    for(int i = 0; i < nums2.size(); i++) cout << nums2[i] << " ";

    cout << "Output: " << solve.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
