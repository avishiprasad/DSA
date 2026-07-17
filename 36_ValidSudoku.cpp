// TC: O(81) = O(1) (or O(N²) generalized NxN grid)
// SC: O(1) (or O(N) generalized NxN grid)
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // bool chkrow(int r,int c,vector<vector<char>>& board){
        //     vector<bool> occur(9,false);
        //     for(int i=0;i<9;i++){
        //         if(board[i][c]!='.'){
        //             if(occur[board[i][c]-'1']) return false;  // if already occurred in that row, ret false
        //             occur[board[i][c]-'1']=true; // else mark visited
        //         }
        //     }
        //     return true;
        // }
        // bool chkcol(int r,int c,vector<vector<char>>& board){
        //     vector<bool> occur(9,false);
        //     for(int i=0;i<9;i++){
        //         if(board[r][i]!='.'){
        //             if(occur[board[r][i]-'1']) return false;  // if already occurred in that row, ret false
        //             occur[board[r][i]-'1']=true; // else mark visited
        //         }
        //     }
        //     return true;
        // }
        // bool chkbox(int r,int c,vector<vector<char>>& board){
        //     vector<bool> occur(9,false);
        //     for(int i=r;i<r+3;i++){
        //         for(int j=c;j<c+3;j++){
        //             if(board[i][j]!='.'){
        //             if(occur[board[i][j]-'1']) return false;  // if already occurred in that row, ret false
        //             occur[board[i][j]-'1']=true; // else mark visited
        //         }
        //         }
        //     }
        //     return true;
        // }
        bool isValidSudoku(vector<vector<char>>& board) {     
            // for(int i=0;i<9;i++){
            //     if(!chkrow(0,i,board) || !chkcol(i,0,board)) return false;
            // }
            // for(int i=0;i<9;i+=3){
            //     for(int j=0;j<9;j+=3){
            //         if(!chkbox(i,j,board))return false;
            //     }
            // }
            // return true;
    
            // make sets for each row,col and box. chk each one if el already exists then false, else true
            unordered_set<char> rows[9],cols[9],boxes[9]; // sets for 9 rows, 9 cols, and 9 boxes each
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(board[i][j]=='.') continue;
                    char val=board[i][j];
    
                    if(rows[i].count(val)) return false; //if already in set, ret false
                    else rows[i].insert(val); // if not, add
    
                    if(cols[j].count(val)) return false;
                    else cols[j].insert(val);
    
                    if(boxes[(i/3)*3+j/3].count(val)) return false;
                    else boxes[(i/3)*3+j/3].insert(val); //(row/3)*3 + (col/3) to uniquely identify each box
                }
            }
            return true;
        }
    };