#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // vector<int> nsefunc(vector<int> arr){//n if not there for an el
        //     vector<int> nse(arr.size());
        //     stack<int> st;
        //     for(int i=arr.size()-1;i>=0;i--){
        //         while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        //         if(st.empty()) nse[i]=arr.size();
        //         else nse[i]=st.top();
        //         st.push(i);
        //     }
        //     return nse;
        // }
        // vector<int> psefunc(vector<int> arr){  //-1 if not there for an el
        //     vector<int> pse(arr.size());
        //     stack<int> st;
        //     for(int i=0;i<arr.size();i++){
        //         while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        //         if(st.empty()) pse[i]=-1;
        //         else pse[i]=st.top();
        //         st.push(i);
        //     }
        //     return pse;
        // }
        int largestRectangleArea(vector<int>& heights) { //arr=height[i]*(nse[i]-pse[i]-1)
            // vector<int> nse(heights.size());
            // nse=nsefunc(heights);
            // vector<int> pse(heights.size());
            // pse=psefunc(heights);
            // int rect=heights[0];
            // for(int i=0;i<heights.size();i++){
            //     int ar=heights[i]*(nse[i]-pse[i]-1);
            //     if(ar>rect) rect=ar;
            // }
            // return rect;
    
    
        
            //tc: O(n), sc: O(n)
            //find nse and pse
            stack<int> st;
            int rect=0;
            for(int i=0;i<heights.size();i++){
                while(!st.empty() && heights[st.top()]>heights[i]){ // if smaller height found i.e. nse found
                    int h=heights[st.top()]; st.pop();
                    int pse = st.empty() ? -1 : st.top();
                    int nse=i;
                    rect=max(rect,h*(nse-pse-1));
                }
                st.push(i);
            }
            while(!st.empty()){
                int h=heights[st.top()]; st.pop();
                int nse=heights.size();
                int pse = st.empty() ? -1 : st.top();
                rect=max(rect,(nse-pse-1)*h);
            }
            return rect;
        }
    };