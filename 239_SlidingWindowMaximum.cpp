#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            // tc O(n), sc O(k)
            deque<int> dq; // storing indices in dec order (front has max idx, and back has least idx)
            vector<int> ans;
            for(int i=0;i<nums.size();i++){
                while(!dq.empty() && dq.front()<=i-k) dq.pop_front(); // remove idx outside curr window
                while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back(); //if smaller found, remove from back
                dq.push_back(i); //push all indices
                if(i>=k-1) ans.push_back(nums[dq.front()]); //first window found
            }
            return ans;
        }
    };