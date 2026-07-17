#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {   
            //tc O(nlogn + n^2) , sc O(1)
            vector<vector<int>> res;
            sort(nums.begin(),nums.end()); // sort the nums array
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(i>0 && nums[i]==nums[i-1])continue; //skipping duplicate
                int j=i+1;
                int k=n-1;
                while(j<k){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum>0)k--; //large sum
                    else if(sum<0)j++; //small sum
                    else{
                       res.push_back({nums[i],nums[j],nums[k]});  
                       j++;k--;
                       while(j<k && nums[j]==nums[j-1])j++;  //skip dup of j
                       while(j<k && nums[k]==nums[k+1])k--;  //skip dup of k
                    } 
                }
            }
            return res;
        }
    };