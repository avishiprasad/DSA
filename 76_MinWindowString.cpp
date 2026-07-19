#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string minWindow(string s, string t) { 
            // tc O(n), sc O(1)
            int l=0,r=0,cnt=0,mx=INT_MAX,startind=-1;
            vector<int> h(256,0);
            for(int i=0;i<t.length();i++){
                h[t[i]]++;
            }
            while(r<s.length()){
                if(h[s[r]]>0) cnt++;  //it it was stored in hash, implies it was present in t 
                while(cnt==t.length()){
                    if(mx>r-l+1){
                        mx=r-l+1;
                        startind=l;
                    }
                    h[s[l]]++; //since r getting subtracted everytime, it makes -1 for chars not in t,this brings it back to 0 
                    if(h[s[l]]>0)
                    cnt--; //it was present in t , so remove from cnt; l++;
                }
                h[s[r]]--;  // subtract everytime
                r++;
            }
            return (mx==INT_MAX) ? "" :s.substr(startind,mx);
        }
    };