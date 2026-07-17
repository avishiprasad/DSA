#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int trap(vector<int>& height) {
            // tc O(n), sc O(1)
            int tot=0,lmax=0,rmax=0,l=0,r=height.size()-1;
        while(l<r){
            if(height[l]<height[r]){
                if(lmax>height[l]) tot+=lmax-height[l];
                else lmax=height[l];
                l++;
            }else{
                if(rmax>height[r]) tot+=rmax-height[r];
                else rmax=height[r];
                r--;
            }
        }
        return tot;
    }
};