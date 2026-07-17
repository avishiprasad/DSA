#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // tc O(nlogn) due to sorting, sc O(1)
        if (nums.empty())
            return 0;
        int ans = 0, mx = 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] == nums[i])
                continue;
            else if (nums[i] + 1 == nums[i + 1])
                mx++;
            else
            {
                ans = max(ans, mx);
                mx = 1;
            }
        }
        ans = max(ans, mx);
        return ans;

        // tc O(n), sc O(n)
        unordered_set<int> st(nums.begin(), nums.end()); // stores unique
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (st.find(nums[i] - 1) == st.end())
            { // indicates nums[i] is the start
                int curr = nums[i], mx = 1;
                while (st.find(curr + 1) != st.end())
                {
                    mx++;
                    curr++;
                }
                ans = max(ans, mx);
            }
        }
        return ans;
    }
};