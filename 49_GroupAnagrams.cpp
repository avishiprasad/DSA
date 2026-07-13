#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //sort words(anagrams become same after sorting) then store in hashmap
        // timeO(n · k log k) , space O(nk)
        vector<vector<string>> ans;
        if(strs.empty()) return ans;
        unordered_map<string,vector<string>> mpp;
        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            sort(word.begin(),word.end());
            mpp[word].push_back(strs[i]);
        }
        for(auto &[key,val]:mpp) ans.push_back(val);
        return ans;

        //optimal- create a freq signature for all, this avoid sorting tc
        // time O(n · k) , space O(nk)
        vector<vector<string>> ans;
        if(strs.empty()) return ans;
        unordered_map<string,vector<string>> mpp; //key,strings
        for(int i=0;i<strs.size();i++){
            vector<int> freq(26,0);
            for(char c:strs[i]) freq[c-'a']++;
            string key="";
            for(int j:freq) key+=to_string(j)+"#";  //eg. abce = 1#1#1#0#1#0#0#0#.... delim bec if 10 d's then 10 will get stored
            mpp[key].push_back(strs[i]);
        }
        for(auto &[key,val]:mpp) ans.push_back(val);
        return ans;
    }
};