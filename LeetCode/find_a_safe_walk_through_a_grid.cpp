// Find a Safe Walk Through a Grid [Medium]
// https://leetcode.com/problems/find-a-safe-walk-through-a-grid/

class Solution {
public:
    bool issafe(int i,int j,vector<vector<int>>&grid){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }

    bool solve(int i,int j,vector<vector<int>>&grid,int health,vector<vector<int>>&healthgrid){

        if(health<1)
            return false;

        if(i==grid.size()-1 && j==grid[0].size()-1)
            return true;

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];

            if(issafe(ni,nj,grid)){
                int newHealth=health-grid[ni][nj];

                if(newHealth>=1 && healthgrid[ni][nj]<newHealth){
                    healthgrid[ni][nj]=newHealth;
                    if(solve(ni,nj,grid,newHealth,healthgrid))
                        return true;
                }
            }
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(),m=grid[0].size();

        health-=grid[0][0];
        if(health<1)
            return false;

        vector<vector<int>>healthgrid(n,vector<int>(m,-1));
        healthgrid[0][0]=health;

        return solve(0,0,grid,health,healthgrid);
    }
};