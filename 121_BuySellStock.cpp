#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // tc O(n), sc O(1)
            int maxpro=0;
            int minele=prices[0];
            for(int i=0;i<prices.size();i++){
                minele=min(minele,prices[i]);
                maxpro=max(maxpro,prices[i]-minele);
            }
            return maxpro;
        }
    };