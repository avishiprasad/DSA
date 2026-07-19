#include <bits/stdc++.h>
using namespace std;
class TimeMap {
    public:
        // store hashmap - {key,vector<pair<int,int>>} key,(val,time)
        // since times are sorted, you can use bs for efficient retrieval

        //tc: O(logn) for get, O(1) for set, sc: O(n)
        unordered_map<string, vector<pair<string,int>>> mpp;
        TimeMap() {  
    
        }
    
        void set(string key, string value, int timestamp) {
            mpp[key].push_back({value, timestamp});
        }
    
        string get(string key, int timestamp) {
            if (mpp.find(key) == mpp.end())
                return "";
            int l = 0, r = mpp[key].size() - 1;
            string res = "";
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (mpp[key][mid].second <=
                    timestamp) { // pot candidate,look closer to right
                    res = mpp[key][mid].first;
                    l = mid + 1;
                } else
                    r = mid - 1;
            }
            return res;
        }
    };
    
    /**
     * Your TimeMap object will be instantiated and called as such:
     * TimeMap* obj = new TimeMap();
     * obj->set(key,value,timestamp);
     * string param_2 = obj->get(key,timestamp);
     */