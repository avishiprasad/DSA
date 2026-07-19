#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    //tc: O(logn), sc: O(1)
        int search(vector<int>& nums, int target) {
    
            int l=0,r=nums.size()-1;
    
            while(l<r){
                int m=(l+r)/2;
                if(nums[m]==target) return m;
                if(nums[m]<target) l=m+1;
                else r=m-1;
            }
            return -1;
        }
    };