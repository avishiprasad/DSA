// Time Complexity: O(n + m log m) average, where m=number of distinct elements. 
// Worst case: O(n log n).
// Space Complexity: O(m). 
// Worst case: O(n).

#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int num:nums) mpp[num]++;

        priority_queue<pair<int,int>> pq;
        for(auto [key,val]:mpp) pq.push({val,key});

        vector<int> ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};