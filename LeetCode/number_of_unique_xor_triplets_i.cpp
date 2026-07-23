// Number of Unique XOR Triplets I [Medium]
// https://leetcode.com/problems/number-of-unique-xor-triplets-i/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=size(nums);
        if(n<=2){
            return n;
        }
        int ans=1;
        for(int num:nums){
            ans|=num;
        }
        return ans+1;
    }
};