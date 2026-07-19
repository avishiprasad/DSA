#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    //tc: O(nlogn), sc: O(n)
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            // store info of {car,time to reach end} in 2d array, sort cars based on distance to target
            int n=position.size();
            vector<pair<int, double>> cars(n);
            for (int i = 0; i < n; i++) {
                cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
            }
    
            // Sort cars based on position in descending order (closest to target first)
            sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
                return a.first > b.first;
            });
    
            int fleets = 0;
            double max_time = 0.0;
    
            // Process from right to left
            for (int i = 0; i < n; i++) {
                // If this car takes more time than the leading fleet ahead,
                // it cannot catch up and starts a new fleet.
                if (cars[i].second > max_time) {
                    fleets++;
                    max_time = cars[i].second; // This car becomes the new fleet leader
                }
            }
    
            return fleets;
        }
    };