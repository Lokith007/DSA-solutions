// Subsets [Medium]
// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=size(nums);
        vector<vector<int>>ans;
        int count=1<<n;
        for(int i=0;i<count;i++){
            vector<int>temp;
            for(int j=0;j<size(nums);j++){
                if(i&(1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};