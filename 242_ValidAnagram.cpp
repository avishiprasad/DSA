// Time Complexity: O(n)
// Space Complexity: O(1) (because the frequency array has a fixed size of 26)

#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;
        for(char c:t) freq[c-'a']--;
        for(int i:freq) if(i!=0) return false;
        return true;
    }
};