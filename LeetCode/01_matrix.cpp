// 01 Matrix [Medium]
// https://leetcode.com/problems/01-matrix/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=size(mat),c=size(mat[0]);
        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j]=INT_MAX;
                }
            }
        }
        while(!q.empty()){
            pair<int,int>pos=q.front();
            q.pop();
            int row=pos.first;
            int col=pos.second;
            for(int i=0;i<size(directions);i++){
                int newr=row+directions[i].first;
                int newc=col+directions[i].second;
                if(newr>=0 && newr<r && newc>=0 && newc<c && mat[newr][newc]>mat[row][col]+1){
                    mat[newr][newc]=mat[row][col]+1;
                    q.push({newr,newc});
                }
            }
        }
        return mat;
    }
};