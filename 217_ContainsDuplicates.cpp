#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool containsDuplicate(vector<int>& nums) {
        
        //1 sort and chk adjacent - O(nlogn) time complexity, O(1) space complexity
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
            if(nums[i]==nums[i+1]) 
                return true;
        return false;

        //2 set - O(n) time complexity, O(n) space complexity
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])!=st.end()) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};