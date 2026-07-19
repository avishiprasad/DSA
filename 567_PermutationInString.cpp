#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            //tc O(n), sc O(1)
            if (s1.length() > s2.length())
                return false;
    
            vector<int> a1(26, 0), a2(26, 0);
            for (int i = 0; i < s1.length(); i++) { // initialize first window
                a1[s1[i] - 'a']++;
                a2[s2[i] - 'a']++;
            }
    
            for (int i = 0; i < s2.length() - s1.length(); i++) {
                if (a1 == a2) {
                    return true; // chk
                }
    
                a2[s2[i] - 'a']--;               // remove last from s2
                a2[s2[i + s1.length()] - 'a']++; // add new chrs ahead
            }
    
            return (a1 == a2); // chk last
        }
    };