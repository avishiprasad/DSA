#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // tc O(n), sc O(n)
            int ans = 0, mx = 0, l = 0, r = 0;
            unordered_set<char> st;
            while (r < s.length()) {
                while (st.find(s[r]) != st.end()) {
                    st.erase(s[l]);
                    l++;
                }
                st.insert(s[r]);
                ans = max(ans, r - l + 1);
                r++;
            }
            return ans;
        }
    };