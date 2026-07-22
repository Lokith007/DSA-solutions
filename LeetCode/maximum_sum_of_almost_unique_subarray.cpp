// Maximum Sum of Almost Unique Subarray [Medium]
// https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n=size(nums);
        unordered_map<int,int>freq;
        long long maxx=0,sum=0;
        int l=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            freq[nums[r]]++;
            if(r-l+1>k){
                sum-=nums[l];
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    freq.erase(nums[l]);
                }
                l++;
            }
            if(r-l+1==k){
                if(size(freq)>=m){
                    maxx=max(maxx,sum);
                }
            }
        }
        return maxx;
    }
};