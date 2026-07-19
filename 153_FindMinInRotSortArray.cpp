#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    // tc: O(logn), sc: O(1)
        int findMin(vector<int>& nums) {
            int n=nums.size(),low=0,high=n-1,minn=nums[0];
            while(low<=high){
                int mid=(low+high)/2;
                if(nums[low]<=nums[mid]){
                    minn=min(nums[low],minn);
                    low=mid+1; // first half ka min leke next half mai gaya
                }else{
                    minn=min(nums[mid],minn);
                    high=mid-1;  //2nd half ka min leke 1st half mai ghuso chk karne
                }
            }
            return minn;
        }
    };