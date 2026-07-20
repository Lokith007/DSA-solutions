// Find a Safe Walk Through a Grid [Medium]
// https://leetcode.com/problems/find-a-safe-walk-through-a-grid/

class Solution {
public:
    bool issafe(int i,int j,vector<vector<int>>& grid){
        return (i>=0 && j>=0 && i<size(grid) && j<size(grid[0]));
    }
    bool solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& healthgrid,int health){
        if(health<1){
            return false;
        }
        if(i==size(grid)-1 && j==size(grid[0])-1){
            return true;
        }
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int ni=i+dx[k],nj=j+dy[k];
            if(issafe(ni,nj,grid)){
                int newhealth=health-grid[ni][nj];
                if(newhealth>=1 && healthgrid[ni][nj]<newhealth){
                    healthgrid[ni][nj]=newhealth;
                    if(solve(ni,nj,grid,healthgrid,newhealth)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=size(grid),m=size(grid[0]);
        if(health<1){
            return false;
        }
        health-=grid[0][0];
        vector<vector<int>>healthgrid(n,vector<int>(m,-1));
        healthgrid[0][0]=health;
        return solve(0,0,grid,healthgrid,health);
    }
};