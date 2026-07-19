#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int characterReplacement(string s, int k) {
            // (len - maxfreq) is the chrs which need to be converted
            // tc O(n), sc O(1)   
            int maxfreq=0,l=0,cnt,r=0,ans=0;
            vector<int> h(26,0);
            while(r<s.length()){
                h[s[r]-'A']++;
                maxfreq=max(maxfreq,h[s[r]-'A']);
                cnt=(r-l+1)-maxfreq; // (len-maxfreq) gives the count pf the chrs that need to be converted to get the longest cont len
                if(cnt<=k) ans=max(ans,r-l+1); //if cnt less than k, then those can be converted
                else{   // else reduce window
                    h[s[l]-'A']--;
                    l++;
                } 
                r++;
            }
            return ans;
        }
    };