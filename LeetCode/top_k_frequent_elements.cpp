// Top K Frequent Elements [Medium]
// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto n:nums){
            mp[n]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto x:mp){
            int n=x.first,freq=x.second;
            pi p={freq,n};
            pq.push(p);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            int ele=pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};