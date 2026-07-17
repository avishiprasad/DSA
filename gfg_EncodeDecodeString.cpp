// tc O(n), sc O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
      string encode(vector<string>& arr) {
          // write your logic to encode the strings
          string ans="";
          for(int i=0;i<arr.size();i++){
              ans+=to_string(arr[i].length())+"/:"+arr[i];
          }
          return ans;
      }
  
      vector<string> decode(string& s) {
          // write your logic to decode the string
          vector<string> ans;
          int i=0;
          while(i<s.length()){
              int delimposn=s.find("/:",i); // This finds the index of the delimiter "/:" starting from index i. 
              int len=stoi(s.substr(i,delimposn-i)); //This calculates the number of characters to extract. Because delimPos is the index where /: starts, subtracting your current index i from delimPos gives you exactly how many digits make up the number.
              i=delimposn+2;
              ans.push_back(s.substr(i,len));
              i+=len;
          }
          return ans;
      }
  };