// Distant Barcodes [Medium]
// https://leetcode.com/problems/distant-barcodes/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>mp;
        for(int i=0;i<size(barcodes);i++){
            mp[barcodes[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto &p:mp){
            pq.push({p.second,p.first});
        }
        vector<int>ans;
        while(!pq.empty()){
           auto [f,b]=pq.top();
           pq.pop();
           ans.push_back(b);
           f--;
           if(!pq.empty()){
            auto [f1,b1]=pq.top();
            pq.pop();
            ans.push_back(b1);
            f1--;
            if(f1>0){
                pq.push({f1,b1});
            }
           }
           if(f>0){
            pq.push({f,b});
           }
        }
        return ans;
    }
};