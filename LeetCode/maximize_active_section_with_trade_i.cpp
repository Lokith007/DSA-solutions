// Maximize Active Section with Trade I [Medium]
// https://leetcode.com/problems/maximize-active-section-with-trade-i/

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int one=0;
        for(int i=0;i<size(s);i++){
            if(s[i]=='1'){
                one++;
            }
        }
        s.insert(0,1,'1');
        int n=size(s);
        s.insert(n,1,'1');
        vector<pair<char,int>>vec;
        int i=0;
        while(i<size(s)){
            int j=i;
            while(j<size(s)&& s[i]==s[j]){
                j++;
            }
            vec.push_back({s[i],j-i});
            i=j;
        }
        int maxx=0;
        for(int i=1;i<size(vec)-1;i++){
            if(vec[i].first=='1' && vec[i-1].first=='0' && vec[i+1].first=='0'){
                int gain=vec[i-1].second+vec[i+1].second;
                maxx=max(maxx,gain);
            }
        }
        return maxx+one;
    }
};