#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //make 2 arrays pre and post and store all mul till that el from left and right resp
        //tc O(n), sc O(n)
        // int n=nums.size();
        // vector<int> ans,pre(n,1),post(n,1);
        // for(int i=1;i<n;i++){
        //     pre[i]=pre[i-1]*nums[i-1];
        //     post[n-i-1]=post[n-i]*nums[n-i];
        // }
        // for(int i=0;i<n;i++){
        //     ans.push_back(pre[i]*post[i]);
        // }        
        // return ans;

        //optimal - in ans array, go frwd storing pre, then go backward by mul pre with post
        //tc O(n), sc O(1)
        int pre=1,post=1;
        vector<int> ans(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            ans[i]=pre;
            pre*=nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=post;
            post*=nums[i];
        }
        return ans;
    }
};