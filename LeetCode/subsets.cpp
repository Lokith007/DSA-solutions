// Subsets [Medium]
// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=size(nums);
        vector<vector<int>>ans;
        int size=1<<n;
        for(int j=0;j<size;j++){
            vector<int>subsets;
            for(int i=0;i<n;i++){
                if(j&(1<<i)){
                    subsets.push_back(nums[i]);
                }
            }
            ans.push_back(subsets);
        }
        return ans;
    }
};