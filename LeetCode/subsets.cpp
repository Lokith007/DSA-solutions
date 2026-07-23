// Subsets [Medium]
// https://leetcode.com/problems/subsets/

class Solution {
public:
    void solve(vector<int>& nums,int index,int n,vector<int>& temp,vector<vector<int>>& ans){
        if(index>=n){
            ans.push_back(temp);
            return;
        }
        solve(nums,index+1,n,temp,ans);
        temp.push_back(nums[index]);
        solve(nums,index+1,n,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,0,size(nums),temp,ans);
        return ans;
    }
};