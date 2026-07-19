#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // tc: O(nlogm), sc: O(1) where m is the max element in piles
        int minEatingSpeed(vector<int>& piles, int h) {
    
            int mp=INT_MIN;
            for(int i=0;i<piles.size();i++) 
                mp=max(mp,piles[i]);
            int l=1,r=mp,speed;
            while(l<r){
                speed=(l+r)/2; //mid is speed
                int hrs=0;
                for(int bananas:piles) hrs+=((bananas+speed-1)/speed);
                if(hrs>h) l=speed+1; //if time>h, i.e. increase speed so that more bananas can be eaten
                else r=speed;
            }
            return l;
        }
    };