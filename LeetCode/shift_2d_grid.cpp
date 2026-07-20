// Shift 2D Grid [Easy]
// https://leetcode.com/problems/shift-2d-grid/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=size(grid),n=size(grid[0]);
        int total=m*n;
        k%=total;
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int oldi=i*n+j;
                int newi=(oldi+k)%total;
                int newr=newi/n;
                int newc=newi%n;
                ans[newr][newc]=grid[i][j];
            }
        }
        return ans;
    }
};