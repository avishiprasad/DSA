#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // tc: O(logn), sc: O(1)
        int search(vector<int>& nums, int target) {
            int n=nums.size();
            int low=0,high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(nums[mid]==target) return mid;
                if(nums[low]<=nums[mid]){ //This condition ensures that the left part is sorted.
                    if(nums[low]<=target && target<=nums[mid]) high=mid-1; //It signifies that the target is in this sorted half. So, we will eliminate the right half
                    else low=mid+1;
                }else{ //Otherwise, if the right half is sorted
                    if(nums[mid] <= target && target <= nums[high]) low = mid+1;// It signifies that the target is in this sorted right half. So, we will eliminate the left half 
                    else high = mid-1;
                }
            }
            return -1;
        }
    };