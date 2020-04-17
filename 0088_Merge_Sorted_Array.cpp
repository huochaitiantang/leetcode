#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        int i = m - 1, j = n - 1;
        while((i >= 0) && (j >= 0)){
            if(nums2[j] > nums1[i]) nums1[k--] = nums2[j--];
            else nums1[k--] = nums1[i--];
        }
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
        return;
    }
};

int main(){
    vector<int> nums1 = {2, 2, 3, 0, 0, 0};
    vector<int> nums2 = {1, 5, 6};
    int m = 3, n = 3;
    Solution solve;
    solve.merge(nums1, m, nums2, n);
    for(int i = 0; i < m + n; i++)
        std::cout << nums1[i] << " ";
    return 0;
} 
