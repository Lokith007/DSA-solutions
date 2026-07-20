// Find K Pairs with Smallest Sums [Medium]
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        if(size(nums1)==0||size(nums2)==0||k==0){
            return ans;
        }
 priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;
        for(int i=0;i<min((int)size(nums1),k);i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        while(k-- && !pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int i=curr.second.first;
            int j=curr.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<size(nums2)){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return ans;
    }
};