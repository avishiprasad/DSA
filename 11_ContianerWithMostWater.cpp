#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxArea(vector<int>& height) {
            // tc O(n), sc O(1)
            int l=0,r=height.size()-1,ar=0,mx,mxc,mxr;
            while(l<r){
                mx=min(height[l],height[r])*(r-l); // height is shorter one out of the 2
                ar=max(ar,mx);
                if(height[l]<height[r]) l++; // the one having less should move ahead or backwards
                else r--;          
            }
            return ar;
        }
    };
