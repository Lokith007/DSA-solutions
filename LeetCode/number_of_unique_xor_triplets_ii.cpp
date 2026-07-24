// Number of Unique XOR Triplets II [Medium]
// https://leetcode.com/problems/number-of-unique-xor-triplets-ii/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(size(nums)<=1){
            return 1;
        }
        const int maxx=2048;
        vector<bool>ones(maxx,false);
        vector<bool>twos(maxx,false);
        vector<bool>threes(maxx,false);
        for(int val:nums){
            for(int x=0;x<maxx;x++){
                if(ones[x]){
                    twos[x^val]=true;
                }
            }
            ones[val]=true;
        }
        for(int val:nums){
            for(int x=0;x<maxx;x++){
                if(twos[x]){
                    threes[x^val]=true;
                }
            }
        }
        int ans=0;
        for(bool t:threes){
            ans+=t;
        }
        return ans;
    }
};